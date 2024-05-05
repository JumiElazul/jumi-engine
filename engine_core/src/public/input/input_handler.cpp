#include "engine_core/input/input_handler.h"
#include "engine_core/input/keycodes.h"
#include "engine_core/core/logger.h"
#include "keycodes.cpp"
#include <glfw/glfw3.h>
#include <fmt/format.h>

namespace jumi
{
    input_handler::input_handler()
        : _previous_frame_keymap()
        , _current_frame_keymap()
    {
        JUMI_DEBUG("Initializing input_handler...");
    }

    input_handler::~input_handler()
    {
        JUMI_DEBUG("Destructing input_handler...");
    }

    bool input_handler::key_pressed(jumi_key key)
    {
        return _current_frame_keymap[key] && !_previous_frame_keymap[key];
    }

    bool input_handler::key_released(jumi_key key)
    {
        return !_current_frame_keymap[key] && _previous_frame_keymap[key];
    }

    bool input_handler::key_held(jumi_key key)
    {
        return _previous_frame_keymap[key] && _current_frame_keymap[key];
    }

    void input_handler::init()
    {

    }

    void input_handler::new_frame_keymap()
    {
        _previous_frame_keymap = _current_frame_keymap;
    }

    void input_handler::key_callback(int key, int scancode, int action, int mods)
    {
        jumi_keyaction key_action = glfw_keyaction_to_jumi(action);
        jumi_key keycode = glfw_key_to_jumi(key);

        switch (key_action)
        {
            case (jumi_keyaction::press):
            case (jumi_keyaction::repeat):
            {
                _current_frame_keymap[keycode] = true;
                break;
            }
            case (jumi_keyaction::release):
            {
                _current_frame_keymap[keycode] = false;
                break;
            }
        }
    }

}
