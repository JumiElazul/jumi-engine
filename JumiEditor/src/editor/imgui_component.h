#pragma once
#include <imgui.h>

namespace jumi
{
    class ImGuiComponent
    {
    public:
        virtual ~ImGuiComponent() = default;
        virtual void set_window_flags() = 0;
        virtual void render() = 0;
        bool is_open() const;

    protected:
        bool _is_open = false;
        ImGuiConfigFlags _flags = ImGuiWindowFlags_None;
    };
}
