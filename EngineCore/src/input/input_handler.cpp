#include "EngineCore/input/input_handler.h"
#include "EngineCore/core/core.h"
#include "EngineCore/core/engine_core.h"
#include "EngineCore/input/keycodes.h"
#include "EngineCore/events/event_bus.h"
#include "EngineCore/log/logger.h"
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

    void InputHandler::poll_input_events()
    {
        _prev_keymap = _curr_keymap;
        glfwPollEvents();

        for (const auto& key_state : _curr_keymap)
        {
            JUMI_KEYCODE keycode = key_state.first;

            if (is_key_down(keycode))
            {
#ifdef JUMI_INPUT_LOGGING
                JUMI_TRACE("Key down: {}", KeyCodeConverter::keycode_to_string(keycode));
#endif
                Scope<KeyPressedEvent> event = CreateScope<KeyPressedEvent>(keycode);
                EventBus::instance().push_to_event_queue(std::move(event));
            }
            else if (is_key_up(keycode))
            {
#ifdef JUMI_INPUT_LOGGING
                JUMI_TRACE("Key up: {}", KeyCodeConverter::keycode_to_string(keycode));
#endif
                Scope<KeyReleasedEvent> event = CreateScope<KeyReleasedEvent>(keycode);
                EventBus::instance().push_to_event_queue(std::move(event));
            }
            else if (is_key_held(keycode))
            {
#ifdef JUMI_INPUT_LOGGING
                JUMI_TRACE("Key held: {}", KeyCodeConverter::keycode_to_string(keycode));
#endif
                Scope<KeyHeldEvent> event = CreateScope<KeyHeldEvent>(keycode);
                EventBus::instance().push_to_event_queue(std::move(event));
            }
        }
    }

}
