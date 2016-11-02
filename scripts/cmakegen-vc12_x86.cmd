@echo off

mkdir ..\build\vc12-x86
pushd ..\build\vc12-x86

cmake ^
	-G"Visual Studio 12" ^
	"-DBOOST_LIBRARYDIR=%BOOST_ROOT%/lib32-msvc-12.0" ^
        "-Wno-dev" ^
	../..
if errorlevel 1 goto :error

echo [*] Project generation succeeded!

popd
goto :eof

:error
echo [!] ERROR: Failed to generate project - see above and correct.
popd
exit /b 1