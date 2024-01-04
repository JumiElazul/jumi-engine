#pragma once

#include "editor/imgui_window.h"

namespace jumi
{
    class SceneHierarchy : public ImGuiComponent
    {
    public:
        SceneHierarchy();
        ~SceneHierarchy();

        virtual void render() override;
    };
}
