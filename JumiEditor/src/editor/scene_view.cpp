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
            ViewportTarget target = calculate_render_target_area();

            EngineCore& core = EngineCore::instance();
            Renderer& renderer = core.get_renderer();
            renderer.set_viewport_target(target);
        }
        ImGui::End();
    }

    ViewportTarget SceneView::calculate_render_target_area()
    {
        ImVec2 pos = ImGui::GetWindowPos();
        int x = static_cast<int>(pos.x);
        int y = static_cast<int>(pos.y);
        ImVec2 size = ImGui::GetWindowSize();
        float windowWidth = size.x;
        float windowHeight = size.y;

        float viewportWidth = 0.0f;
        float viewportHeight = 0.0f;
        float viewportX = 0.0f;
        float viewportY = 0.0f;
        float aspectRatio = 0.0f;

        switch (_aspect_ratio)
        {
            case AspectRatio::SixteenxNine:
            {
                aspectRatio = 16.0f / 9.0f;
                break;
            }
            case AspectRatio::SixteenxTen:
            {
                aspectRatio = 16.0f / 10.0f;
                break;
            }
            case AspectRatio::FourxThree:
            {
                aspectRatio = 4.0f / 3.0f;
                break;
            }
            default:
            {
                aspectRatio = 16.0f / 9.0f;
                break;
            }
        }

        if ((windowWidth / windowHeight) > aspectRatio) 
        {
            viewportHeight = windowHeight;
            viewportWidth = viewportHeight * aspectRatio;
        }
        else 
        {
            viewportWidth = windowWidth;
            viewportHeight = viewportWidth / aspectRatio;
        }

        viewportX = x + (windowWidth - viewportWidth) / 2.0f;
        viewportY = y + (windowHeight - viewportHeight) / 2.0f;

        return ViewportTarget
        {
            static_cast<int>(viewportX),
            static_cast<int>(viewportY),
            static_cast<int>(viewportWidth),
            static_cast<int>(viewportHeight)
        };
    }

    void SceneView::set_aspect_ratio(AspectRatio ratio) { _aspect_ratio = ratio; }

}
