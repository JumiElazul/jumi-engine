#pragma once
#include <imgui.h>

namespace jumi
{
    class ImGuiWindow
    {
    public:
        virtual ~ImGuiWindow() = default;
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void render() = 0;
    };
}
