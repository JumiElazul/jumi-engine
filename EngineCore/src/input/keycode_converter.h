#pragma once

#include "input/keycodes.h"
#include <string>

namespace jumi
{

	// These are hard coded to the same as the Jumi keycodes for now just so we don't have to include
	// glfw in this header file just for the keycodes.  This works because the keycodes are currently the same.
	constexpr int MIN_GLFW_KEYCODE = JUMI_KEY_SPACE;
	constexpr int MAX_GLFW_KEYCODE = JUMI_KEY_MENU;
	constexpr int MIN_JUMI_KEYCODE = JUMI_KEY_SPACE;
	constexpr int MAX_JUMI_KEYCODE = JUMI_KEY_MENU;

	constexpr int KEYMAP_ARRAY_SIZE = MAX_GLFW_KEYCODE + 1;
	constexpr int ACTIONMAP_ARRAY_SIZE = 3;
	constexpr int KEYMAP_TOSTR_ARRAY_SIZE = MAX_JUMI_KEYCODE + 1;
	constexpr int ACTIONMAP_TOSTR_ARRAY_SIZE = 3;

	class KeyCodeConverter
	{
	public:
		static void init();
		static bool is_initialized();

		static int glfw_to_jumi_keycode(int keycode);
		static int glfw_to_jumi_keyaction(int action);
		static std::string keycode_to_string(JUMI_KEYCODE keycode);
		static std::string keyaction_to_string(JUMI_KEYACTION action);

	private:
		KeyCodeConverter();
		~KeyCodeConverter() = default;

		static bool s_initialized;
		static JUMI_KEYCODE s_glfw_to_jumi_keymap[KEYMAP_ARRAY_SIZE];
		static JUMI_KEYACTION s_glfw_to_jumi_actionmap[ACTIONMAP_ARRAY_SIZE];
		static std::string s_keycode_to_string[KEYMAP_TOSTR_ARRAY_SIZE];
		static std::string s_keyaction_to_string[ACTIONMAP_TOSTR_ARRAY_SIZE];

		static void initialize_key_mappings();
		static void initialize_key_actions();
		static void initialize_keycode_tostr_array();
		static void initialize_keyaction_tostr_array();
	};

}
