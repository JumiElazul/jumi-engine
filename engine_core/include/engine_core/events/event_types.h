#ifndef JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_TYPES_H
#define JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_TYPES_H

#include "engine_core/input/keycodes.h"

#define EVENT_FUNCTIONS(name)                                                   \
public:                                                                         \
    virtual inline const char* type() const override { return _descriptor; }    \
private:                                                                        \
    static constexpr const char* _descriptor = #name

namespace jumi
{

    class event
    {
    public:
        virtual ~event() = default;
        virtual const char* type() const = 0;
    };

    class key_event : public event
    {
    EVENT_FUNCTIONS(key_event);
    public:
        key_event(JUMI_KEY key, int state);
        JUMI_KEY get_key() const;
        int get_state() const;

    private:
        JUMI_KEY _key;
        int _state;
    };

    class window_resize_event : public event
    {
    EVENT_FUNCTIONS(window_resize_event);
    public:
        window_resize_event(int width, int height);
        int get_width() const;
        int get_height() const;

    private:
        int _width;
        int _height;
    };

}

#endif

