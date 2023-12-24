@echo off

REM Define the path to the vcpkg toolchain file
set VCPKG_TOOLCHAIN=D:\vcpkg\scripts\buildsystems\vcpkg.cmake

REM Create the build directory
if not exist bin mkdir bin

REM Ask user for build mode
echo Select build mode: (d) Debug, (r) Release
set /p choice="Enter choice: "

REM Set build type based on user input
if "%choice%"=="d" (
    set BUILD_TYPE=Debug
) else if "%choice%"=="r" (
    set BUILD_TYPE=Release
) else (
    echo Invalid choice. Defaulting to Release mode.
    set BUILD_TYPE=Release
)

REM Run CMake with the vcpkg toolchain and build type to generate a Visual Studio 2022 solution
cmake -S . -B bin -G "Visual Studio 17 2022" --log-level=VERBOSE -DCMAKE_TOOLCHAIN_FILE=%VCPKG_TOOLCHAIN% -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=%BUILD_TYPE%

pause
