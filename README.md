## JumiEngine
---------------

JumiEngine is a simple graphics engine to easily render 3d objects onto the screen with various custom shaders.
The engine uses a C++ backend with OpenGL to handle all graphics rendering.



### Dependencies
This project uses `vcpkg` for managing C++ libraries, and premake5 for its build system.


# Engine Dependencies
- spdlog
- fmt
- glfw
- glad

# JumiEditor Dependencies
- dear imgui


### Setup
1.  Install `vcpkg` following [these instructions](https://github.com/microsoft/vcpkg) to the directory of your choice.
2.  Add vcpkg to your environment path
3.  Run build_dependencies.bat for vcpkg to install all dependencies
4.  Run build_project.bat to generate a Visual Studio 2022 solution file (if you want a different target run the command in the .bat file
    with a different generator arg)

### Usage

### Troubleshooting

