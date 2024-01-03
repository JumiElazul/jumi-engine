#include "EngineCore/events/event_bus.h"
#include "EngineCore/input/keycodes.h"

namespace jumi
{

    // ----------------------------------------
    //                  Events
    // ----------------------------------------

    Event::Event(EventType type, std::string name)
        : _type(type), _name(name) { }

    EventType Event::type() const { return _type; }
    std::string Event::name() const { return _name; }

    WindowCloseEvent::WindowCloseEvent() : Event(EventType::WindowClose, "WindowClose") { }

    WindowResizeEvent::WindowResizeEvent(int32 width, int32 height) : Event(EventType::WindowResize, "WindowResize"), _width(width), _height(height) { }
    int32 WindowResizeEvent::width() const { return _width; }
    int32 WindowResizeEvent::height() const { return _height; }

    WindowFocusEvent::WindowFocusEvent() : Event(EventType::WindowFocus, "WindowFocus") { }

    WindowLostFocusEvent::WindowLostFocusEvent() : Event(EventType::WindowLostFocus, "WindowLostFocus") { }

    WindowMovedEvent::WindowMovedEvent(int32 x, int32 y) : Event(EventType::WindowMoved, "WindowMoved"), _x(x), _y(y) { }
    int32 WindowMovedEvent::x() const { return _x; }
    int32 WindowMovedEvent::y() const { return _y; }

    AppTickEvent::AppTickEvent(uint64 tick_count) : Event(EventType::AppTick, "AppTick"), _tick_count(tick_count) { }
    uint64 AppTickEvent::tick_count() const { return _tick_count; }

    AppUpdateEvent::AppUpdateEvent() : Event(EventType::AppUpdate, "AppUpdate") { }

    AppRenderEvent::AppRenderEvent() : Event(EventType::AppRender, "AppRender") { }

    KeyPressedEvent::KeyPressedEvent(JUMI_KEYCODE keycode) : Event(EventType::KeyPressed, "KeyPressed"), _keycode(keycode) { }

    KeyReleasedEvent::KeyReleasedEvent(JUMI_KEYCODE keycode) : Event(EventType::KeyReleased, "KeyReleased"), _keycode(keycode) { }

    KeyHeldEvent::KeyHeldEvent(JUMI_KEYCODE keycode) : Event(EventType::KeyHeld, "KeyHeld"), _keycode(keycode) { }

    MouseMovedEvent::MouseMovedEvent(int32 x, int32 y) : Event(EventType::MouseMoved, "MouseMoved"), _x(x), _y(y) { }
    int32 MouseMovedEvent::x() const { return _x; }
    int32 MouseMovedEvent::y() const { return _y; }



    // ----------------------------------------
    //                 EventBus
    // ----------------------------------------

    EventBus& EventBus::instance()
    {
        static EventBus instance;
        return instance;
    }

    void EventBus::push_to_event_queue(Scope<Event> event)
    {
        _event_queue.push(std::move(event));
    }

    void EventBus::dispatch_events()
    {
        while (!_event_queue.empty())
        {
            Scope<Event> event = std::move(_event_queue.front());
            _event_queue.pop();

            const std::vector<EventCallback>& event_subscriptions = _event_subscriptions[event->type()];

            for (const EventCallback& callback : event_subscriptions)
            {
                callback(*event);
            }
        }
    }

    void EventBus::subscribe(EventType event_type, EventCallback callback)
    {
        _event_subscriptions[event_type].push_back(callback);
    }

}
