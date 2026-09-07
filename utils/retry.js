const { spawn } = require('child_process');

const [, , cmd, ...args] = process.argv;
if (!cmd) {
  process.exit(-1);
}

// A test run that hangs used to produce no `close` event, so this wrapper
// waited on it until the job timeout killed the whole step -- the slowest and
// (on a macOS runner, at 10x the Linux rate) most expensive way to learn
// nothing. Bound each attempt, and bound every attempt put together, so the
// step always exits on its own with logs attached.
const ATTEMPT_TIMEOUT_MS = Number(process.env.RETRY_ATTEMPT_TIMEOUT_MS || 15 * 60 * 1000);
const TOTAL_TIMEOUT_MS = Number(process.env.RETRY_TOTAL_TIMEOUT_MS || 25 * 60 * 1000);
const deadline = Date.now() + TOTAL_TIMEOUT_MS;

const once = (fn) => {
  let runOnce = false;
  return (...args) => {
    if (runOnce) {
      return;
    }

    runOnce = true;
    fn(...args);
  }
};

// `npm test` spawns the test runner in turn, and on Windows we spawn through a
// shell besides. Signalling only the process we hold would leave the ones
// actually hung alive, still holding the pipes this process waits on.
const killTree = (child) => {
  if (process.platform === 'win32') {
    spawn('taskkill', ['/pid', String(child.pid), '/T', '/F'], { stdio: 'ignore' });
  } else {
    child.kill('SIGKILL');
  }
};

const retry = (numRetries = 3) => {
  const child = spawn(cmd, args, {
    shell: process.platform === 'win32',
    stdio: [0, 'pipe', 'pipe']
  });

  child.setMaxListeners(0);

  child.stdout.setEncoding('utf8');
  child.stderr.setEncoding('utf8');

  child.stdout.pipe(process.stdout);
  child.stderr.pipe(process.stderr);

  let timer;

  const cleanupAndExit = once((error, status) => {
    clearTimeout(timer);
    killTree(child);
    if (numRetries > 0 && (error || status !== 0) && Date.now() < deadline) {
      retry(numRetries - 1);
    } else if (error) {
      console.log(error);
      process.exit(-1);
    } else {
      // A child killed by a signal reports a null status. Exiting on that
      // would report the hang we just gave up on as a pass.
      process.exit(status === 0 ? 0 : (status || 1));
    }
  });
  const onClose = status => cleanupAndExit(null, status);

  // Never overrun the shared deadline: the last attempt gets whatever is left
  // of it rather than a fresh allowance.
  const attemptTimeoutMs = Math.max(1, Math.min(ATTEMPT_TIMEOUT_MS, deadline - Date.now()));
  timer = setTimeout(() => {
    console.log(`\n[retry] \`${[cmd, ...args].join(' ')}\` produced no exit in ${attemptTimeoutMs}ms; killing it`);
    cleanupAndExit(null, null);
  }, attemptTimeoutMs);

  child.on('close', onClose);
  child.on('error', cleanupAndExit);
};

retry();
