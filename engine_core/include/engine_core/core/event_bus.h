#ifndef JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_BUS_H
#define JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_BUS_H

#include "engine_core/events/event_types.h"
#include <memory>
#include <queue>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace jumi
{
    using event_listeners = std::vector<std::function<void(const event&)>>;

    class event_bus
    {
    public:
        static event_bus& instance();
        static void poll_events();

        void push_event(std::unique_ptr<event> event);


    private:
        event_bus();
        ~event_bus();
        event_bus(const event_bus&) = delete;
        event_bus& operator=(const event_bus&) = delete;
        event_bus(event_bus&&) = delete;
        event_bus& operator=(event_bus&&) = delete;

        std::queue<std::unique_ptr<event>> _event_queue;
        std::unordered_map<std::type_index, event_listeners> _listeners;
    };

}

#endif

