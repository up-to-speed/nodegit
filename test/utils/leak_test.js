var assert = require("assert");

var garbageCollect = require("./garbage_collect");

function leakTest(Type, getInstance) {
  // Use async gc for baseline to ensure N-API weak ref callbacks from
  // prior tests have fired before we record starting counts
  return garbageCollect.async()
    .then(function() {
      var startSelfFreeingCount = Type.getSelfFreeingInstanceCount();
      var startNonSelfFreeingCount = Type.getNonSelfFreeingConstructedCount();

      // CRITICAL: Mocha stores the returned promise, keeping the entire chain
      // alive. V8 promises retain [[PromiseResult]] until the promise is GC'd.
      // We must ensure NO reference path from the returned chain reaches back
      // to getInstance()'s promise.
      //
      // Strategy: fire-and-forget getInstance() with NO chaining into the
      // returned promise. Use closure variables as a side-channel.
      var creationError = null;
      var creationChecked = false;

      getInstance()
        .then(function() {
          // No parameter — do NOT capture the resolved value so V8 can
          // release the native object when this promise is GC'd.
          var selfFreeingCount = Type.getSelfFreeingInstanceCount();
          try {
            assert.equal(startSelfFreeingCount + 1, selfFreeingCount);
          } catch(e) {
            creationError = e;
          }
          creationChecked = true;
        })
        .catch(function(e) {
          creationError = e;
          creationChecked = true;
        });

      // Poll until the fire-and-forget chain completes.
      function waitForCreation(remaining) {
        if (creationChecked) {
          if (creationError) {
            return Promise.reject(creationError);
          }
          return Promise.resolve();
        }
        if (remaining <= 0) {
          return Promise.reject(new Error("getInstance() did not resolve in time"));
        }
        return new Promise(function(resolve) {
          setTimeout(resolve, 50);
        }).then(function() {
          return waitForCreation(remaining - 1);
        });
      }

      return waitForCreation(60)
        .then(function() {
          // getInstance() promise chain should now be unreachable.
          var maxAttempts = 15;
          function attemptGcAndCheck(remaining) {
            return garbageCollect.async()
              .then(function() {
                var endSelfFreeingCount = Type.getSelfFreeingInstanceCount();
                var endNonSelfFreeingCount = Type.getNonSelfFreeingConstructedCount();
                if (endSelfFreeingCount === startSelfFreeingCount &&
                    endNonSelfFreeingCount === startNonSelfFreeingCount) {
                  return; // success
                }
                if (remaining <= 0) {
                  // Final check — assert so we get a clear error
                  assert.equal(startSelfFreeingCount, endSelfFreeingCount);
                  assert.equal(startNonSelfFreeingCount, endNonSelfFreeingCount);
                }
                // Yield and try again
                return new Promise(function(resolve) {
                  setTimeout(resolve, 100);
                }).then(function() {
                  return attemptGcAndCheck(remaining - 1);
                });
              });
          }
          return attemptGcAndCheck(maxAttempts);
        });
    });
}

module.exports = leakTest;
