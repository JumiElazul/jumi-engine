#pragma once
#include "editor/imgui_component.h"

namespace jumi
{
	class PropertiesInspector : public ImGuiComponent
	{
	public:
		PropertiesInspector();
		~PropertiesInspector();

		virtual void set_window_flags() override;
		virtual void render();

	private:

	};
}
