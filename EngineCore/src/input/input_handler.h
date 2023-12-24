#pragma once

#include "core/core.h"
#include "input/keycodes.h"
#include <unordered_map>

struct GLFWwindow;
class WindowUserPointer;

namespace jumi
{
	using Keymap = std::unordered_map<JUMI_KEYCODE, bool>;

	class JUMI_API InputHandler
	{
	friend class WindowUserPointer;
	friend class EngineCore;

	public:
		InputHandler() = default;
		~InputHandler() = default;

		bool is_key_down(JUMI_KEYCODE keycode);
		bool is_key_up(JUMI_KEYCODE keycode);
		bool is_key_held(JUMI_KEYCODE keycode);
        void poll_input_events();

	private:
		Keymap _curr_keymap;
		Keymap _prev_keymap;

		void on_key_pressed(JUMI_KEYCODE keycode, JUMI_KEYACTION action);
		void update_keymap(JUMI_KEYCODE keycode, JUMI_KEYACTION action);
	};

}
