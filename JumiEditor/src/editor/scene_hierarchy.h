#pragma once

#include "editor/imgui_component.h"

namespace jumi
{
    class SceneHierarchy : public ImGuiComponent
    {
    public:
        SceneHierarchy();
        ~SceneHierarchy();

        virtual void set_window_flags() override;
        virtual void render() override;
    };
}
