#include "engine_core/events/event_bus.h"
#include <GLFW/glfw3.h>
#include <queue>
#include <unordered_map>

namespace jumi
{

    event_bus::event_bus()
        : _event_queue()
        , _listeners()
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
        _event_queue.emplace(std::move(event));
    }

}