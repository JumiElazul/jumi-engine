## JumiEngine
---------------

JumiEngine is a simple graphics engine to easily render 3d objects onto the screen with various custom shaders.
The engine uses a C++ backend with OpenGL to handle all graphics rendering.



### Dependencies
This project uses `vcpkg` for managing C++ libraries, and premake5 for its build system.


# Engine Dependencies
- spdlog


### Setup
1.  Install `vcpkg` following [these instructions](https://github.com/microsoft/vcpkg) to the directory of your choice.
2.  Add vcpkg to your environment path
3.  Run build_project.sh
4.  Run this command to get dependencies for project built in libraries:
        sudo apt install libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev pkg-config


### Usage

## Create the window

Call Jumi::EngineCore::SetWindowContext() with parameters needed for the window you want to create.
Then, proceed to call Jumi::EngineCore::Initialize().  If Initialize() is called before the WindowContext
is created, a default WindowContext is provided.


### Troubleshooting

