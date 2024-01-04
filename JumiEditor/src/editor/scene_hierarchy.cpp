#include "editor/scene_hierarchy.h"
#include <imgui.h>

namespace jumi
{
    SceneHierarchy::SceneHierarchy() { }
    SceneHierarchy::~SceneHierarchy() { }

    void SceneHierarchy::open()
    {

    }

    void SceneHierarchy::close()
    {

    }

    void SceneHierarchy::render()
    {
        if (ImGui::Begin("Scene Hierarchy", nullptr))
        {
            ImGui::End();
        }
    }
}