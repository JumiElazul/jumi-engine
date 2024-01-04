#include "editor/scene_hierarchy.h"
#include <imgui.h>

namespace jumi
{
    SceneHierarchy::SceneHierarchy() { }
    SceneHierarchy::~SceneHierarchy() { }

    void SceneHierarchy::render()
    {
        if (ImGui::Begin("Scene Hierarchy", nullptr))
        {
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
            ImGui::PopStyleVar();
            ImGui::End();
        }
    }
}