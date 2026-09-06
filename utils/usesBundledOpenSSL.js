const isBuildingForElectron = require("./isBuildingForElectron");

/**
 * Whether this build links the OpenSSL in vendor/openssl instead of borrowing
 * the host runtime's.
 *
 * bungit is built for Bun. Bun exports the N-API entry points and nothing else,
 * so an addon that leaves OpenSSL symbols to be resolved by the executable
 * cannot load in it. On Windows that is the only way an addon can get OpenSSL
 * without bundling it -- node.exe re-exports its own OpenSSL through node.lib,
 * bun.exe does not -- so a Windows build always bundles. Electron does not
 * re-export OpenSSL either, so Electron builds bundle on every platform.
 *
 * Bundling on Windows is not just a matter of naming the libraries: node.lib
 * can satisfy every OpenSSL symbol we need, and the MSVC linker takes the first
 * library that offers a symbol. node-gyp puts node.lib in the target's
 * "libraries", which gyp emits AFTER anything in
 * msvs_settings.VCLinkerTool.AdditionalDependencies -- so binding.gyp lists the
 * static libcrypto/libssl there, ahead of node.lib. Listed the other way round,
 * the addon still builds and still works under node.exe, and still fails to
 * load under bun.exe.
 *
 * Note that this is a host-platform decision, matching gyp's OS variable:
 * node-gyp cannot cross-compile a Windows addon from another platform.
 */
module.exports = function usesBundledOpenSSL(nodeRootDir) {
  return process.platform === "win32" || isBuildingForElectron(nodeRootDir);
};

// Called on the command line by the .gyp files
if (require.main === module) {
  if (process.argv.length < 3) {
    process.exit(1);
  }

  process.stdout.write(module.exports(process.argv[2]) ? "1" : "0");
}
