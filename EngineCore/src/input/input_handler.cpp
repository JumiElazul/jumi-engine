#include "input/input_handler.h"
#include "input/keycode_converter.h"
#include "core/engine_core.h"
#include "logging/logger.h"

namespace jumi
{

	bool InputHandler::is_key_down(JUMI_KEYCODE keycode)
	{
		return _keymap[keycode] == JUMI_KEYACTION_PRESS;
	}

	bool InputHandler::is_key_up(JUMI_KEYCODE keycode)
	{
		return _keymap[keycode] == JUMI_KEYACTION_RELEASE;
	}

	bool InputHandler::is_key_held(JUMI_KEYCODE keycode)
	{
		return _keymap[keycode] == JUMI_KEYACTION_REPEAT || _keymap[keycode] == JUMI_KEYACTION_PRESS;
	}

	void InputHandler::on_key_pressed(JUMI_KEYCODE keycode, JUMI_KEYACTION action)
	{
		JUMI_TRACE("Key: [{}] with keycode [{}] was [{}]", KeyCodeConverter::keycode_to_string(keycode), keycode, KeyCodeConverter::keyaction_to_string(action));
		update_keymap(keycode, action);
	}

	void InputHandler::update_keymap(JUMI_KEYCODE keycode, JUMI_KEYACTION action)
	{
		_keymap[keycode] = action;
	}

}
