#pragma once

#include <memory>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

struct GLFWwindow;

namespace jumi
{
    class WindowHandler;
    class Renderer;
    class SceneHierarchy;
    class HeaderBar;
    class PropertiesInspector;

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
        void init(GLFWwindow* window);
        void begin_frame() const;
        void draw_ui() const;
        void end_frame() const;

    private:
        bool _initialized = false;
        std::unique_ptr<HeaderBar> _header_bar;
        std::unique_ptr<PropertiesInspector> _properties_inspector;
        std::unique_ptr<SceneHierarchy> _scene_hierarchy;

        void initialize_imgui_windows();
    };

}
