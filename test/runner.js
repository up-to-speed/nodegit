var fse = require("fs-extra");
var path = require("path");
var local = path.join.bind(path, __dirname);
var exec = require('../utils/execPromise');

var NodeGit = require('..');

var workdirPath = local("repos/workdir");
var constWorkdirPath = local("repos/constworkdir");
var masterSha;
var gitDir;
var gitBackupDir;

const testRepos = [
  "repos/bare",
  "repos/blameRepo",
  "repos/cherrypick",
  "repos/clone",
  "repos/constworkdir",
  "repos/convenientLineTest",
  "repos/empty",
  "repos/index",
  "repos/index",
  "repos/merge",
  "repos/merge-head",
  "repos/new",
  "repos/newrepo",
  "repos/nonrepo",
  "repos/rebase",
  "repos/renamedFileRepo",
  "repos/revertRepo",
  "repos/stagingRepo",
  "repos/submodule",
  "repos/submodule/nodegittest/",
  "repos/tree/",
  "repos/workdir",
];

before(function() {
  this.timeout(350000);

  var testUrl = "https://github.com/nodegit/test";
  var constTestUrl = "https://github.com/nodegit/test-frozen";

  gitDir = path.join(workdirPath, ".git");

  // Check if repos already exist (e.g. from a prior test:node run)
  var reposExist = fse.existsSync(workdirPath) &&
                   fse.existsSync(constWorkdirPath);

  var setupRepos;
  if (reposExist) {
    setupRepos = Promise.resolve();
  } else {
    setupRepos = fse.remove(local("repos"))
      .then(function() {
        return fse.remove(local("home"));
      })
      .then(function() {
        return fse.ensureDir(local("repos"));
      })
      .then(function() {
        return exec("git init " + local("repos", "empty"));
      })
      .then(function() {
        return exec("git clone " + constTestUrl + " " + constWorkdirPath);
      })
      .then(function() {
        return exec("git clone " + testUrl + " " + workdirPath);
      });
  }

  return setupRepos
    .then(function() {
      //to checkout the longpaths-checkout branch
      if(process.platform === "win32") {
        return exec("git config core.longpaths true", {cwd: workdirPath});
      }
      return Promise.resolve();
    })
    .then(function() {
      return exec("git checkout rev-walk", {cwd: workdirPath}).catch(function() {});
    })
    .then(function() {
      return exec("git checkout checkout-test", {cwd: workdirPath}).catch(function() {});
    })
    .then(function() {
      return exec("git checkout longpaths-checkout", {cwd: workdirPath}).catch(function() {});
    })
    .then(function() {
      return exec("git checkout -f master", {cwd: workdirPath});
    })
    .then(function() {
      // Use the SHA from refs/remotes directly, not the remote name,
      // in case config is corrupted from prior test runs
      return exec("git rev-parse refs/remotes/origin/master", {cwd: workdirPath});
    })
    .then(function(sha) {
      masterSha = sha.trim();
      return exec("git reset --hard " + masterSha, {cwd: workdirPath});
    })
    .then(function() {
      // Clear stashes before any test file's before() hook opens the repo
      return exec("git stash clear", {cwd: workdirPath}).catch(function() {});
    })
    .then(function() {
      // Delete any stale local branches left from prior test runs
      // Keep only the branches we explicitly checked out above
      var keepBranches = ["master", "rev-walk", "checkout-test", "longpaths-checkout"];
      return exec("git for-each-ref '--format=%(refname:short)' refs/heads/",
        {cwd: workdirPath})
        .then(function(output) {
          var branches = output.trim().split("\n").filter(function(b) {
            return b && keepBranches.indexOf(b) === -1;
          });
          var deletes = branches.map(function(b) {
            return exec("git branch -D " + b, {cwd: workdirPath})
              .catch(function() {});
          });
          return Promise.all(deletes);
        });
    })
    .then(function() {
      // Write a clean git config directly to avoid corruption from
      // duplicate remote entries left by prior test runs
      var cleanConfig =
        "[core]\n" +
        "\trepositoryformatversion = 0\n" +
        "\tfilemode = true\n" +
        "\tbare = false\n" +
        "\tlogallrefupdates = true\n" +
        "\tignorecase = true\n" +
        "\tprecomposeunicode = true\n" +
        "[remote \"origin\"]\n" +
        "\turl = https://github.com/nodegit/test\n" +
        "\tfetch = +refs/heads/*:refs/remotes/origin/*\n" +
        "[branch \"master\"]\n" +
        "\tremote = origin\n" +
        "\tmerge = refs/heads/master\n" +
        "[branch \"rev-walk\"]\n" +
        "\tremote = origin\n" +
        "\tmerge = refs/heads/rev-walk\n" +
        "[branch \"checkout-test\"]\n" +
        "\tremote = origin\n" +
        "\tmerge = refs/heads/checkout-test\n" +
        "[branch \"longpaths-checkout\"]\n" +
        "\tremote = origin\n" +
        "\tmerge = refs/heads/longpaths-checkout\n";
      return fse.writeFile(path.join(gitDir, "config"), cleanConfig);
    })
    .then(function() {
      // Save a snapshot of .git state for beforeEach to restore
      gitBackupDir = local("repos", ".workdir-git-backup");
      return fse.remove(gitBackupDir).catch(function() {});
    })
    .then(function() {
      return fse.ensureDir(gitBackupDir);
    })
    .then(function() {
      // Back up config, packed-refs, and all ref directories
      return Promise.all([
        fse.copy(path.join(gitDir, "config"),
                 path.join(gitBackupDir, "config")),
        fse.copy(path.join(gitDir, "refs"),
                 path.join(gitBackupDir, "refs")),
        fse.copy(path.join(gitDir, "packed-refs"),
                 path.join(gitBackupDir, "packed-refs"))
          .catch(function() {})
      ]);
    })
    .then(function() {
      return fse.ensureDir(local("repos", "nonrepo"));
    })
    .then(function() {
      return fse.writeFile(local("repos", "nonrepo", "file.txt"),
        "This is a bogus file");
    })
    .then(function() {
      return fse.ensureDir(local("home"));
    })
    .then(function() {
      return fse.writeFile(local("home", ".gitconfig"),
        "[user]\n  name = John Doe\n  email = johndoe@example.com");
    })
    .then( async function() {
      //mark all test repos as safe
      for(let repo of testRepos) {
        await exec(`git config --global --add safe.directory ${local(repo)}`);
      }
    })
});

beforeEach(function() {
  this.timeout(10000);
  // Remove stale lock files FIRST, before any git operations that need them
  return Promise.all([
    fse.remove(path.join(gitDir, "index.lock")).catch(function() {}),
    fse.remove(path.join(gitDir, "HEAD.lock")).catch(function() {})
  ])
  .then(function() {
    return exec("git clean -xdf", {cwd: workdirPath});
  })
  .then(function() {
    // Abort any in-progress merge/rebase
    return exec("git merge --abort", {cwd: workdirPath}).catch(function() {});
  })
  .then(function() {
    // Restore git config, packed-refs, and key ref directories from backup
    // Only restore refs/heads, refs/remotes, refs/tags — leave refs/notes
    // and other directories alone since describe-level before() hooks may
    // create them
    return Promise.all([
      fse.copy(path.join(gitBackupDir, "config"),
               path.join(gitDir, "config"), {overwrite: true}),
      fse.remove(path.join(gitDir, "refs", "heads"))
        .then(function() {
          return fse.copy(path.join(gitBackupDir, "refs", "heads"),
                          path.join(gitDir, "refs", "heads"));
        }).catch(function() {}),
      fse.remove(path.join(gitDir, "refs", "remotes"))
        .then(function() {
          return fse.copy(path.join(gitBackupDir, "refs", "remotes"),
                          path.join(gitDir, "refs", "remotes"));
        }).catch(function() {}),
      fse.remove(path.join(gitDir, "refs", "tags"))
        .then(function() {
          return fse.copy(path.join(gitBackupDir, "refs", "tags"),
                          path.join(gitDir, "refs", "tags"));
        }).catch(function() {}),
      fse.copy(path.join(gitBackupDir, "packed-refs"),
               path.join(gitDir, "packed-refs"), {overwrite: true})
        .catch(function() {
          return fse.remove(path.join(gitDir, "packed-refs"))
            .catch(function() {});
        })
    ]);
  })
  .then(function() {
    return exec("git checkout -f master", {cwd: workdirPath})
      .catch(function() {
        // If checkout fails, try harder
        return exec("git reset --hard", {cwd: workdirPath})
          .then(function() {
            return exec("git checkout -f master", {cwd: workdirPath});
          });
      });
  })
  .then(function() {
    return exec("git reset --hard " + masterSha, {cwd: workdirPath});
  })
  .then(function() {
    // Clean up stashes and merge/rebase state files
    return Promise.all([
      exec("git stash clear", {cwd: workdirPath}).catch(function() {}),
      fse.remove(path.join(gitDir, "MERGE_HEAD")).catch(function() {}),
      fse.remove(path.join(gitDir, "MERGE_MSG")).catch(function() {}),
      fse.remove(path.join(gitDir, "MERGE_MODE")).catch(function() {}),
      fse.remove(path.join(gitDir, "REBASE_HEAD")).catch(function() {}),
      fse.remove(path.join(gitDir, "rebase-merge")).catch(function() {}),
      fse.remove(path.join(gitDir, "rebase-apply")).catch(function() {})
    ]);
  });
});

afterEach(function(done) {
  process.nextTick(function() {
    if (global.gc) {
      global.gc();
    } else if (typeof Bun !== "undefined" && Bun.gc) {
      Bun.gc();
    }
    done();
  });
});
