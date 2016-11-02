@echo off

rd /q /s ..\build
rd /q /s ..\deploy

:: Prevent Hudson from stopping the build.
set errorlevel=0
