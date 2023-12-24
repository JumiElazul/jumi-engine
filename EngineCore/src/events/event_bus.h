#pragma once

#include "core/core.h"
#include "input/keycodes.h"
#include <functional>
#include <queue>
#include <string>
#include <unordered_map>

namespace jumi
{
    class Event;
    using EventCallback = std::function<void(const Event&)>;

    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        KeyHeld,
        MouseMoved,
    };

    class Event
    {
    public:
        Event(EventType type, std::string name);
        virtual ~Event() = default;
        virtual EventType type() const;
        virtual std::string name() const;

    protected:
        EventType _type = EventType::None;
        std::string _name;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent();
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int32 width, int32 height);
        int32 width() const;
        int32 height() const;

    private:
        int32 _width;
        int32 _height;
    };

    class WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent();
    };

    class WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent();
    };

    class WindowMovedEvent : public Event
    {
    public:
        WindowMovedEvent(int32 x, int32 y);
        int32 x() const;
        int32 y() const;

    private:
        int32 _x;
        int32 _y;
    };

    class AppTickEvent : public Event
    {
    public:
        AppTickEvent(uint64 tick_count);
        uint64 tick_count() const;

    private:
        uint64 _tick_count;
    };

    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent();
    };

    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent();
    };

    class KeyPressedEvent : public Event
    {
    public:
        KeyPressedEvent(JUMI_KEYCODE keycode);
        JUMI_KEYCODE keycode() const;

    private:
        JUMI_KEYCODE _keycode;
    };

    class KeyReleasedEvent : public Event
    {
    public:
        KeyReleasedEvent(JUMI_KEYCODE keycode);
        JUMI_KEYCODE keycode() const;

    private:
        JUMI_KEYCODE _keycode;
    };

    class KeyHeldEvent : public Event
    {
    public:
        KeyHeldEvent(JUMI_KEYCODE keycode);
        JUMI_KEYCODE keycode() const;

    private:
        JUMI_KEYCODE _keycode;
    };

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(int32 x, int32 y);
        int32 x() const;
        int32 y() const;

    private:
        int32 _x;
        int32 _y;
    };

    class EventBus
    {
    public:
        static EventBus& instance();

        void push_to_event_queue(Scope<Event> event);
        void dispatch_events();
        void subscribe(EventType event_type, EventCallback callback);

    private:
        EventBus() = default;
        ~EventBus() = default;
        EventBus(const EventBus&) = delete;
        EventBus& operator=(const EventBus&) = delete;
        EventBus(EventBus&&) = delete;
        EventBus& operator=(EventBus&&) = delete;

        std::queue<Scope<Event>> _event_queue;
        std::unordered_map<EventType, std::vector<EventCallback>> _event_subscriptions;
    };
}
