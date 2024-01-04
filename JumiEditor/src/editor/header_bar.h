#pragma once

#include "editor/imgui_window.h"

namespace jumi
{
    class HeaderBar : public ImGuiWindow
    {
    public:
        HeaderBar();
        ~HeaderBar();
        HeaderBar(const HeaderBar& other) = delete;
        HeaderBar& operator=(const HeaderBar& other) = delete;
        HeaderBar(HeaderBar&& other) = delete;
        HeaderBar& operator=(HeaderBar&& other) = delete;

        virtual void open() override;
        virtual void close() override;
        virtual void render() override;
    };
}
