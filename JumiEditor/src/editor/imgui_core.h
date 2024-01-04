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
        ImGuiConfigFlags _config_flags = 0;

        std::unique_ptr<HeaderBar> _header_bar;
        std::unique_ptr<PropertiesInspector> _properties_inspector;
        std::unique_ptr<SceneHierarchy> _scene_hierarchy;

        void initialize_imgui_windows();
        void initialize_backends(GLFWwindow* window);
        void set_config_flags();
        void set_default_fonts() const;
        void set_color_style() const;

        static bool s_ConfigFlags_NavEnableKeyboard;
        static bool s_ConfigFlags_NavEnableGamepad;
        static bool s_ConfigFlags_NavEnableSetMousePos;
        static bool s_ConfigFlags_NavNoCaptureKeyboard;
        static bool s_ConfigFlags_NoMouse;
        static bool s_ConfigFlags_NoMouseCursorChange;
        static bool s_ConfigFlags_DockingEnable;
        static bool s_ConfigFlags_ViewportsEnable;
        static bool s_ConfigFlags_IsSRGB;
        static bool s_ConfigFlags_IsTouchScreen;
    };

}
