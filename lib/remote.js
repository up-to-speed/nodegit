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

function wrapCredentials(callbacks) {
  if (!callbacks || !callbacks.credentials) {
    return callbacks;
  }
  var originalCredentials = callbacks.credentials;
  var hasRejected = false;
  callbacks.credentials = function() {
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
  return callbacks;
}

var _push = Remote.prototype.push;
Remote.prototype.push = function(refSpecs, options, callback) {
  if (options && options.callbacks) {
    wrapCredentials(options.callbacks);
  }
  return _push.call(this, refSpecs, options, callback);
};

var _fetch = Remote.prototype.fetch;
Remote.prototype.fetch = function(refSpecs, options, message, callback) {
  if (options && options.callbacks) {
    wrapCredentials(options.callbacks);
  }
  return _fetch.call(this, refSpecs, options, message, callback);
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
