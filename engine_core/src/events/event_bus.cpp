#include "engine_core/events/event_bus.h"
#include <GLFW/glfw3.h>
#include <queue>
#include <unordered_map>

namespace jumi
{

    event_function::event_function(const std::function<void(const event&)>& event_func)
        : _id(assign_id())
        , _event_func(event_func)
    {

    }

    void event_function::operator()(const event& event)
    {
        _event_func(event);
    }

    int event_function::id() const
    {
        return _id;
    }

    int event_function::assign_id()
    {
        static int id = 0;
        return id++;
    }

    event_bus::event_bus()
        : _event_queue()
        , _event_listener_map()
    {

    }

    event_bus::~event_bus()
    {

    }

    event_bus& event_bus::instance()
    {
        static event_bus instance;
        return instance;
    }

    void event_bus::poll_events()
    {
        glfwPollEvents();
    }

    void event_bus::push_event(std::unique_ptr<event> event)
    {
        _event_queue.push(std::move(event));
    }

    void event_bus::dispatch_events()
    {
        while (!_event_queue.empty())
        {
            std::unique_ptr<event> event_ptr = std::move(_event_queue.front());
            const char* event_descriptor = event_ptr->type();
            event_listeners& listeners = _event_listener_map[event_descriptor];

            for (event_function& listener_func : listeners)
            {
                listener_func(*event_ptr);
            }

            _event_queue.pop();
        }
    }

    std::uint32_t event_bus::register_to_event(const char* event_description, const std::function<void(const event&)>& callback)
    {
        event_listeners& listeners = _event_listener_map[event_description];
        listeners.emplace_back(callback);
        return listeners.at(listeners.size() - 1).id();
    }

    bool event_bus::deregister_from_event(const char* event_description, std::uint32_t id)
    {
        event_listeners& listeners = _event_listener_map[event_description];

        auto it = std::remove_if(listeners.begin(), listeners.end(), [&](const event_function& func) {
            return func.id() == id;
        });

        if (it != listeners.end())
        {
            listeners.erase(it, listeners.end());
            return true;
        }

        return false;
    }

}