var util = require("util");
var NodeGit = require("../");
var lookupWrapper = NodeGit.Utils.lookupWrapper;

var Remote = NodeGit.Remote;

/**
 * Retrieves the remote by name
 * @async
 * @param {Repository} repo The repo that the remote lives in
 * @param {String|Remote} name The remote to lookup
 * @param {Function} callback
 * @return {Remote}
 */
Remote.lookup = lookupWrapper(Remote);

/**
 * Lists advertised references from a remote. You must connect to the remote
 * before using referenceList.
 *
 * @async
 * @return {Promise<Array<RemoteHead>>} a list of the remote heads the remote
 *                                      had available at the last established
 *                                      connection.
 *
 */
Remote.prototype.referenceList = Remote.prototype.referenceList;

// Wrap credential callbacks to prevent libgit2 from retrying indefinitely
// after a promise rejection. libgit2 treats -1 as "try again", so when a
// credential callback's promise rejects, subsequent calls return null
// (which makes libgit2 give up) instead of calling the user's callback again.
function wrapCredentials(callbacks) {
  if (!callbacks || !callbacks.credentials) {
    return callbacks;
  }

  var originalCredentials = callbacks.credentials;
  var hasRejected = false;
  var wrappedCallbacks = Object.assign({}, callbacks);

  wrappedCallbacks.credentials = function() {
    if (hasRejected) {
      return null;
    }

    var result = originalCredentials.apply(this, arguments);
    if (result && typeof result.then === "function") {
      return result.catch(function(err) {
        hasRejected = true;
        throw err;
      });
    }

    return result;
  };

  return wrappedCallbacks;
}

function wrapOptions(options) {
  if (!options || !options.callbacks) {
    return options;
  }

  var wrappedCallbacks = wrapCredentials(options.callbacks);
  if (wrappedCallbacks === options.callbacks) {
    return options;
  }

  return Object.assign({}, options, {
    callbacks: wrappedCallbacks
  });
}

var _push = Remote.prototype.push;
Remote.prototype.push = function(refSpecs, options, callback) {
  return _push.call(this, refSpecs, wrapOptions(options), callback);
};

var _fetch = Remote.prototype.fetch;
Remote.prototype.fetch = function(refSpecs, options, message, callback) {
  return _fetch.call(this, refSpecs, wrapOptions(options), message, callback);
};

NodeGit.Remote.COMPLETION_TYPE = {};
var DEPRECATED_STATES = {
  COMPLETION_DOWNLOAD: "DOWNLOAD",
  COMPLETION_INDEXING: "INDEXING",
  COMPLETION_ERROR: "ERROR"
};

Object.keys(DEPRECATED_STATES).forEach((key) => {
  const newKey = DEPRECATED_STATES[key];
  Object.defineProperty(NodeGit.Remote.COMPLETION_TYPE, key, {
    get: util.deprecate(
      () => NodeGit.Remote.COMPLETION[newKey],
      `Use NodeGit.Remote.COMPLETION.${newKey} instead of ` +
      `NodeGit.Remote.COMPLETION_TYPE.${key}.`
    )
  });
});
