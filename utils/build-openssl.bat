rem Build OpenSSL for Windows
rem %1 - path to vcvarsall.bat
rem %2 - architecture argument for vcvarsall.bat
rem %3 - OpenSSL Configure target

@call %1 %2

perl .\Configure %3 no-shared no-ssl2 no-ssl3 no-comp --prefix="%cd%\.." --openssldir="%cd%\.." || goto :error

rem We link libcrypto/libssl and nothing else, so build and install just those:
rem the apps, docs and test suite are the slowest part of a Windows build, and
rem every build_libs run happens on a Windows machine waiting on a prebuild.
nmake build_libs || goto :error

nmake install_dev || goto :error

goto :EOF

:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%
