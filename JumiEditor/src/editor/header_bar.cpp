#include "editor/header_bar.h"
#include <imgui.h>

namespace jumi
{
    HeaderBar::HeaderBar()
    {
    }

    HeaderBar::~HeaderBar()
    {
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