#include "editor/imgui_core.h"
#include "editor/header_bar.h"
#include "editor/properties_inspector.h"
#include "editor/scene_hierarchy.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace jumi
{
    bool ImGuiCore::s_ConfigFlags_NavEnableKeyboard    = true;
    bool ImGuiCore::s_ConfigFlags_NavEnableGamepad     = true;
    bool ImGuiCore::s_ConfigFlags_NavEnableSetMousePos = false;
    bool ImGuiCore::s_ConfigFlags_NavNoCaptureKeyboard = false;
    bool ImGuiCore::s_ConfigFlags_NoMouse              = false;
    bool ImGuiCore::s_ConfigFlags_NoMouseCursorChange  = false;
    bool ImGuiCore::s_ConfigFlags_DockingEnable        = true;
    bool ImGuiCore::s_ConfigFlags_ViewportsEnable      = false;
    bool ImGuiCore::s_ConfigFlags_IsSRGB               = false;
    bool ImGuiCore::s_ConfigFlags_IsTouchScreen        = false;

    ImGuiCore::ImGuiCore() { }

    ImGuiCore::~ImGuiCore()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    ImGuiCore& ImGuiCore::instance()
    {
        static ImGuiCore instance;
        return instance;
    }

    void ImGuiCore::init(GLFWwindow* window)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        set_config_flags();
        set_default_fonts();
        set_color_style();
        initialize_backends(window);
        initialize_imgui_windows();

        _initialized = true;
    }

    void ImGuiCore::initialize_backends(GLFWwindow* window)
    {
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 460");
    }

    void ImGuiCore::begin_frame() const
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiCore::draw_ui() const
    {
        ImGuiID dockspace_id = ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        ImGui::ShowDemoWindow();

        _header_bar->render();
        _properties_inspector->render();
        _scene_hierarchy->render();
    }

    void ImGuiCore::end_frame() const
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        ImGui::UpdatePlatformWindows();
    }

    void jumi::ImGuiCore::initialize_imgui_windows()
    {
        _header_bar = std::make_unique<HeaderBar>();
        _properties_inspector = std::make_unique<PropertiesInspector>();
        _scene_hierarchy = std::make_unique<SceneHierarchy>();
    }

    void ImGuiCore::set_config_flags()
    {
        ImGuiIO& io = ImGui::GetIO();

        if (s_ConfigFlags_NavEnableKeyboard)    _config_flags |= ImGuiConfigFlags_NavEnableKeyboard;
        if (s_ConfigFlags_NavEnableGamepad)     _config_flags |= ImGuiConfigFlags_NavEnableGamepad;
        if (s_ConfigFlags_NavEnableSetMousePos) _config_flags |= ImGuiConfigFlags_NavEnableSetMousePos;
        if (s_ConfigFlags_NavNoCaptureKeyboard) _config_flags |= ImGuiConfigFlags_NavNoCaptureKeyboard;
        if (s_ConfigFlags_NoMouse)              _config_flags |= ImGuiConfigFlags_NoMouse;
        if (s_ConfigFlags_NoMouseCursorChange)  _config_flags |= ImGuiConfigFlags_NoMouseCursorChange;
        if (s_ConfigFlags_DockingEnable)        _config_flags |= ImGuiConfigFlags_DockingEnable;
        if (s_ConfigFlags_ViewportsEnable)      _config_flags |= ImGuiConfigFlags_ViewportsEnable;
        if (s_ConfigFlags_IsSRGB)               _config_flags |= ImGuiConfigFlags_IsSRGB;
        if (s_ConfigFlags_IsTouchScreen)        _config_flags |= ImGuiConfigFlags_IsTouchScreen;

        io.ConfigFlags |= _config_flags;
    }

    void ImGuiCore::set_default_fonts() const
    {
        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontFromFileTTF("assets/fonts/iosevka-custom.ttf", 16.0f);
    }

    void ImGuiCore::set_color_style() const
    {
        ImGui::StyleColorsDark();
    }
}
