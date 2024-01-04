#pragma once
#include <imgui.h>

namespace jumi
{
    class ImGuiComponent
    {
    public:
        virtual ~ImGuiComponent() = default;
        virtual void render() = 0;
    };
}
