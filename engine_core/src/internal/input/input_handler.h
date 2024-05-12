#ifndef JUMI_ENGINE_INTERNAL_INPUT_INPUT_HANDLER_H
#define JUMI_ENGINE_INTERNAL_INPUT_INPUT_HANDLER_H

#include "internal/interfaces/i_requires_init.h"
#include "engine_core/input/keycodes.h"
#include <unordered_map>

namespace jumi
{

    class input_handler : public i_requires_init
    {
    public:
        input_handler() = default;
        ~input_handler() = default;

        virtual void init() override;

    private:
        std::unordered_map<JUMI_KEY, JUMI_KEY_STATE> _current_frame_key_states;
        std::unordered_map<JUMI_KEY, JUMI_KEY_STATE> _previous_frame_key_states;

        void set_callbacks();
    };

}

#endif

