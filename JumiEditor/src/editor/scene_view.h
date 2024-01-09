#pragma once
#include "editor/imgui_component.h"
#include "EngineCore/renderer/renderer.h"

namespace jumi
{
    enum class AspectRatio
    {
        SixteenxNine,
        SixteenxTen,
        FourxThree,
    };

    class SceneView : public ImGuiComponent
    {
    public:
        SceneView();
        ~SceneView();

        virtual void set_window_flags() override;
        virtual void render() override;
        ViewportTarget calculate_render_target_area();
        void set_aspect_ratio(AspectRatio ratio);

    private:
        AspectRatio _aspect_ratio = AspectRatio::SixteenxNine;
    };
}
