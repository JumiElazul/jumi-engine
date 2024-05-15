#ifndef JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_TYPES_H
#define JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_TYPES_H

#include "engine_core/input/keycodes.h"

namespace jumi
{

    class event
    {
    public:
        virtual ~event() = default;
    };

    class key_event : public event
    {
    public:
        key_event(JUMI_KEY key, int state);
        JUMI_KEY get_key() const;
        int get_state() const;

    private:
        JUMI_KEY _key;
        int _state;
    };

}

#endif
