#include "engine_core/events/event_types.h"

namespace jumi
{

    key_event::key_event(JUMI_KEY key, int state) : _key(key), _state(state) { }
    JUMI_KEY key_event::get_key() const { return _key; }
    int key_event::get_state() const { return _state; }

}