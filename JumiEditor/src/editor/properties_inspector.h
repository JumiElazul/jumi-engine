#pragma once
#include "imgui_window.h"

namespace jumi
{
	class PropertiesInspector : public ImGuiWindow
	{
	public:
		PropertiesInspector();
		~PropertiesInspector();

		virtual void open();
		virtual void close();
		virtual void render();

	private:

	};
}
