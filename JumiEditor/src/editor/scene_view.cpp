#include "editor/scene_view.h"
#include "EngineCore/core/engine_core.h"
#include "EngineCore/renderer/renderer.h"
#include <imgui.h>

namespace jumi
{
    SceneView::SceneView() { set_window_flags(); }

    SceneView::~SceneView() { }

    void SceneView::set_window_flags()
    {
        //_flags |= ImGuiWindowFlags_NoTitleBar;
        //_flags |= ImGuiWindowFlags_NoResize;
        //_flags |= ImGuiWindowFlags_NoMove;
        //_flags |= ImGuiWindowFlags_NoScrollbar;
        //_flags |= ImGuiWindowFlags_NoScrollWithMouse;
        //_flags |= ImGuiWindowFlags_NoCollapse;
        //_flags |= ImGuiWindowFlags_AlwaysAutoResize;
        _flags |= ImGuiWindowFlags_NoBackground;
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

    void SceneView::render()
    {
        if (ImGui::Begin("Scene View", &_is_open, _flags))
        {
            ImVec2 pos = ImGui::GetWindowPos();
            int x = static_cast<int>(pos.x);
            int y = static_cast<int>(pos.y);
            ImVec2 size = ImGui::GetWindowSize();
            int width = static_cast<int>(size.x);
            int height = static_cast<int>(size.y);

            EngineCore& core = EngineCore::instance();
            Renderer& renderer = core.get_renderer();
            renderer.set_viewport_target({ x, y, width, height });
        }
        ImGui::End();
    }
}
