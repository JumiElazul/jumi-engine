#include "editor/properties_inspector.h"
#include <imgui.h>

namespace jumi
{
    PropertiesInspector::PropertiesInspector() { set_window_flags(); }

	PropertiesInspector::~PropertiesInspector() { }

	void PropertiesInspector::set_window_flags()
	{
        //_flags |= ImGuiWindowFlags_NoTitleBar;
        //_flags |= ImGuiWindowFlags_NoResize;
        //_flags |= ImGuiWindowFlags_NoMove;
        //_flags |= ImGuiWindowFlags_NoScrollbar;
        //_flags |= ImGuiWindowFlags_NoScrollWithMouse;
        //_flags |= ImGuiWindowFlags_NoCollapse;
        //_flags |= ImGuiWindowFlags_AlwaysAutoResize;
        //_flags |= ImGuiWindowFlags_NoBackground;
        //_flags |= ImGuiWindowFlags_NoSavedSettings;
        //_flags |= ImGuiWindowFlags_NoMouseInputs;
        //_flags |= ImGuiWindowFlags_MenuBar;
        //_flags |= ImGuiWindowFlags_HorizontalScrollbar;
        //_flags |= ImGuiWindowFlags_NoFocusOnAppearing;
        //_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        //_flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
        //_flags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
        //_flags |= ImGuiWindowFlags_AlwaysUseWindowPadding;
        //_flags |= ImGuiWindowFlags_NoNavInputs;
        //_flags |= ImGuiWindowFlags_NoNavFocus;
        //_flags |= ImGuiWindowFlags_UnsavedDocument;
        //_flags |= ImGuiWindowFlags_NoDocking;
	}

	void PropertiesInspector::render()
	{
        if (ImGui::Begin("Properties Inspector", &_is_open, _flags))
        {

        }
        ImGui::End();
	}

}