#pragma once

#include <memory>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "editor/scene_hierarchy.h"

namespace jumi
{
    class WindowHandler;
    class Renderer;
    class SceneHierarchy;

    class ImGuiCore 
    {
    public:
        ImGuiCore();
        ~ImGuiCore();
        ImGuiCore(const ImGuiCore& other) = delete;
        ImGuiCore& operator=(const ImGuiCore& other) = delete;
        ImGuiCore(ImGuiCore&& other) = delete;
        ImGuiCore& operator=(const ImGuiCore&& other) = delete;

        static ImGuiCore& instance();
        void init(WindowHandler& window, Renderer& renderer);
        void begin_frame() const;
        void render() const;

    private:
        bool _initialized = false;
        std::unique_ptr<SceneHierarchy> _scene_hierarchy;

        void initialize_imgui_windows();
    };

}
