#pragma once
#include "imgui_window.h"

namespace jumi
{
	class PropertiesInspector : public ImGuiComponent
	{
	public:
		PropertiesInspector();
		~PropertiesInspector();

		virtual void render();

	private:

	};
}
