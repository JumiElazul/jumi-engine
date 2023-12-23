#include "input/input_handler.h"
#include "input/keycode_converter.h"
#include "core/engine_core.h"
#include "logging/logger.h"
#include <GLFW/glfw3.h>

namespace jumi
{

	bool InputHandler::is_key_down(JUMI_KEYCODE keycode)
	{
        bool key_down = _curr_keymap[keycode] && !_prev_keymap[keycode];
        return key_down;
	}

	bool InputHandler::is_key_up(JUMI_KEYCODE keycode)
	{
        bool key_up = !_curr_keymap[keycode] && _prev_keymap[keycode];
        return key_up;
	}

	bool InputHandler::is_key_held(JUMI_KEYCODE keycode)
	{
        bool key_held = _curr_keymap[keycode] && _prev_keymap[keycode];
        return key_held;
	}

	void InputHandler::on_key_pressed(JUMI_KEYCODE keycode, JUMI_KEYACTION action)
	{
		update_keymap(keycode, action);
	}

	void InputHandler::update_keymap(JUMI_KEYCODE keycode, JUMI_KEYACTION action)
	{
        bool key_state = (action == JUMI_KEYACTION_PRESS || action == JUMI_KEYACTION_REPEAT) ? true : false;
		_curr_keymap[keycode] = key_state;
	}

    void InputHandler::poll_events()
    {
#ifdef JUMI_INPUT_LOGGING
        for (const auto& key_state : _curr_keymap)
        {
            JUMI_KEYCODE keycode = key_state.first;

            if (is_key_down(keycode))
            {
                JUMI_TRACE("Key down: {}", keycode);
            }
            else if (is_key_up(keycode))
            {
                JUMI_TRACE("Key up: {}", keycode);
            }
            else if (is_key_held(keycode))
            {
                JUMI_TRACE("Key held: {}", keycode);
            }
        }
#endif

        _prev_keymap = _curr_keymap;
        glfwPollEvents();
    }

}
