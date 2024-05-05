#ifndef JUMI_ENGINE_INPUT_INPUT_HANDLER_H
#define JUMI_ENGINE_INPUT_INPUT_HANDLER_H

#include "engine_core/input/keycodes.h"
#include <unordered_map>

namespace jumi
{

    class input_handler
    {
    friend class engine_core;
    friend class glfw_callback_context;
    public:
        bool key_pressed(jumi_key key);
        bool key_released(jumi_key key);
        bool key_held(jumi_key key);

    private:
        std::unordered_map<jumi_key, bool> _previous_frame_keymap;
        std::unordered_map<jumi_key, bool> _current_frame_keymap;

        void init();
        void new_frame_keymap();

        input_handler();
        ~input_handler();
        input_handler(const input_handler& other) = delete;
        input_handler& operator=(const input_handler& other) = delete;
        input_handler(const input_handler&& other) = delete;
        input_handler& operator=(const input_handler&& other) = delete;

        void key_callback(int key, int scancode, int action, int mods);
    };

}

#endif
