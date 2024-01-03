#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace jumi
{
    class WindowHandler;
    class Renderer;

    class ImGuiCore 
    {
    public:
        ImGuiCore();
        ~ImGuiCore();

        void init(WindowHandler& window, Renderer& renderer);
        void begin_frame();
        void render();
        void end_frame();

    private:
        bool _initialized = false;
    };

}
