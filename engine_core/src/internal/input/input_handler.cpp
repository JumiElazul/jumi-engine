#include "internal/input/input_handler.h"
#include "engine_core/core/logger.h"

namespace jumi
{

    input_handler::input_handler()
    {
        JUMI_INFO("Constructing input_handler...");
    }

    input_handler::~input_handler()
    {
        JUMI_INFO("Destructing input_handler...");
    }

    void input_handler::init()
    {
        JUMI_INFO("Initializing input_handler...");
    }

    void input_handler::new_frame()
    {
        _previous_frame_key_states = _current_frame_key_states;
    }

    bool input_handler::is_keydown(JUMI_KEY key)
    {
        return _current_frame_key_states[key] && !_previous_frame_key_states[key];
    }

    bool input_handler::is_keyup(JUMI_KEY key)
    {
        return !_current_frame_key_states[key] && _previous_frame_key_states[key];
    }

    bool input_handler::is_keyheld(JUMI_KEY key)
    {
        return _current_frame_key_states[key] && _previous_frame_key_states[key];
    }

    void input_handler::key_callback(int key, int scancode, int action, int mods)
    {
        _current_frame_key_states[key] = (action == JUMI_PRESS ? true : false);
    }

}