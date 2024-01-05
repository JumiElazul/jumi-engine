#pragma once
#include "editor/imgui_component.h"

namespace jumi
{
    class SceneView : public ImGuiComponent
    {
    public:
        SceneView();
        ~SceneView();

        virtual void set_window_flags() override;
        virtual void render() override;

    private:

    };
}
