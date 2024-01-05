#pragma once

#include "editor/imgui_component.h"

namespace jumi
{
    class HeaderBar : public ImGuiComponent
    {
    public:
        HeaderBar();
        ~HeaderBar();
        HeaderBar(const HeaderBar& other) = delete;
        HeaderBar& operator=(const HeaderBar& other) = delete;
        HeaderBar(HeaderBar&& other) = delete;
        HeaderBar& operator=(HeaderBar&& other) = delete;

        virtual void set_window_flags() override;
        virtual void render() override;

    private:
        void render_file_menu() const;
        void render_edit_menu() const;
        void render_components_menu() const;
    };
}
