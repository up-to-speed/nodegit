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

module.exports = garbageCollect;
