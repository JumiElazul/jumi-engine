#pragma once

#include "editor/imgui_window.h"

namespace jumi
{
    class SceneHierarchy : public ImGuiWindow
    {
    public:
        SceneHierarchy();
        ~SceneHierarchy();

        virtual void open() override;
        virtual void close() override;
        virtual void render() override;
    };
}
