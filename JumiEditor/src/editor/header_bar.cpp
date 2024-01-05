#include "editor/header_bar.h"
#include <imgui.h>

namespace jumi
{
    HeaderBar::HeaderBar() { set_window_flags(); }

    HeaderBar::~HeaderBar() { }

    void HeaderBar::set_window_flags()
    {
        //_flags |= ImGuiWindowFlags_NoTitleBar;
        //_flags |= ImGuiWindowFlags_NoResize;
        //_flags |= ImGuiWindowFlags_NoMove;
        //_flags |= ImGuiWindowFlags_NoScrollbar;
        //_flags |= ImGuiWindowFlags_NoScrollWithMouse;
        //_flags |= ImGuiWindowFlags_NoCollapse;
        //_flags |= ImGuiWindowFlags_AlwaysAutoResize;
        //_flags |= ImGuiWindowFlags_NoBackground;
        //_flags |= ImGuiWindowFlags_NoSavedSettings;
        //_flags |= ImGuiWindowFlags_NoMouseInputs;
        //_flags |= ImGuiWindowFlags_MenuBar;
        //_flags |= ImGuiWindowFlags_HorizontalScrollbar;
        //_flags |= ImGuiWindowFlags_NoFocusOnAppearing;
        //_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        //_flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
        //_flags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
        //_flags |= ImGuiWindowFlags_AlwaysUseWindowPadding;
        //_flags |= ImGuiWindowFlags_NoNavInputs;
        //_flags |= ImGuiWindowFlags_NoNavFocus;
        //_flags |= ImGuiWindowFlags_UnsavedDocument;
        //_flags |= ImGuiWindowFlags_NoDocking;
    }

    void HeaderBar::render()
    {
        if (ImGui::BeginMainMenuBar())
        {
            render_file_menu();
            render_edit_menu();
            render_components_menu();

            ImGui::EndMainMenuBar();
        }
    }

    void HeaderBar::render_file_menu() const
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New Scene")) { }
            if (ImGui::MenuItem("Open Scene")) { }
            if (ImGui::MenuItem("Open Recent Scene")) { }
            if (ImGui::MenuItem("Save")) { }
            if (ImGui::MenuItem("Save As")) { }
            if (ImGui::MenuItem("Save As")) { }

            ImGui::EndMenu();
        }
    }

    void HeaderBar::render_edit_menu() const
    {
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Item #1")) { }
            if (ImGui::MenuItem("Item #2")) { }
            if (ImGui::MenuItem("Item #3")) { }
            if (ImGui::MenuItem("Item #4")) { }
            if (ImGui::MenuItem("Item #5")) { }
            if (ImGui::MenuItem("Item #6")) { }

            ImGui::EndMenu();
        }
    }

    void HeaderBar::render_components_menu() const
    {
        if (ImGui::BeginMenu("Components"))
        {
            if (ImGui::MenuItem("Item #1")) { }
            if (ImGui::MenuItem("Item #2")) { }
            if (ImGui::MenuItem("Item #3")) { }
            if (ImGui::MenuItem("Item #4")) { }
            if (ImGui::MenuItem("Item #5")) { }
            if (ImGui::MenuItem("Item #6")) { }

            ImGui::EndMenu();
        }
    }
}