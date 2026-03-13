// aggressively collects garbage until we fail to improve terminatingIterations
// times.
function garbageCollect() {
  var terminatingIterations = 3;
  var usedBeforeGC = Number.MAX_VALUE;
  var nondecreasingIterations = 0;
  for ( ; ; ) {
    if (global.gc) {
      global.gc();
    } else if (typeof Bun !== "undefined" && Bun.gc) {
      Bun.gc(true);
    }
    var usedAfterGC = process.memoryUsage().heapUsed;
    if (usedAfterGC >= usedBeforeGC) {
      nondecreasingIterations++;
      if (nondecreasingIterations >= terminatingIterations) {
        break;
      }
    }
    usedBeforeGC = usedAfterGC;
  }
}

// Async version: runs gc, then yields to the event loop so that N-API weak ref
// / destructor callbacks fire. Repeats multiple rounds to handle destructor
// chains where freeing object A releases a reference to object B, which then
// needs another gc + yield cycle to be collected.
function garbageCollectAsync(rounds) {
  rounds = rounds || 10;
  function doRound(remaining) {
    garbageCollect();
    if (remaining <= 0) {
      return Promise.resolve();
    }
    return new Promise(function(resolve) {
      setTimeout(function() {
        resolve(doRound(remaining - 1));
      }, 0);
    });
  }
  return doRound(rounds);
}

garbageCollect.async = garbageCollectAsync;

module.exports = garbageCollect;
