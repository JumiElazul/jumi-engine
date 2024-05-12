#ifndef JUMI_ENGINE_INTERNAL_INPUT_INPUT_HANDLER_H
#define JUMI_ENGINE_INTERNAL_INPUT_INPUT_HANDLER_H

#include "internal/interfaces/i_requires_init.h"
#include "engine_core/input/keycodes.h"
#include <unordered_map>

namespace jumi
{

    class input_handler : public i_requires_init
    {
    friend class engine_callback_context;
    public:
        input_handler();
        ~input_handler();

        virtual void init() override;
        void new_frame();
        [[nodiscard]] JUMI_KEY_STATE is_keydown(JUMI_KEY key);
        [[nodiscard]] JUMI_KEY_STATE is_keyup(JUMI_KEY key);
        [[nodiscard]] JUMI_KEY_STATE is_keyheld(JUMI_KEY key);

    private:
        std::unordered_map<JUMI_KEY, JUMI_KEY_STATE> _current_frame_key_states;
        std::unordered_map<JUMI_KEY, JUMI_KEY_STATE> _previous_frame_key_states;

        void key_callback(int key, int scancode, int action, int mods);
    };

}

#endif

