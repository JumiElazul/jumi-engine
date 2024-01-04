#include "imgui_core.h"
#include "editor/imgui_core.h"
#include "editor/header_bar.h"
#include "editor/properties_inspector.h"
#include "editor/scene_hierarchy.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace jumi
{
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
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 460");

        initialize_imgui_windows();

        _initialized = true;
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
}
