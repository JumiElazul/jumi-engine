#ifndef JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_BUS_H
#define JUMI_ENGINE_ENGINE_CORE_EVENTS_EVENT_BUS_H

#include "engine_core/events/event_types.h"
#include <functional>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

namespace jumi
{

    class event_function
    {
    friend class event_bus;
    public:
        event_function(const std::function<void(const event&)>& event_func);
        void operator()(const event& event);
        std::uint32_t id() const;

    private:
        std::uint32_t _id;
        std::function<void(const event&)> _event_func;

        int assign_id();
    };

    using event_listeners = std::vector<event_function>;

    class event_bus
    {
    public:
        static event_bus& instance();

        void poll_events();
        void push_event(std::unique_ptr<event> event_ptr);
        void dispatch_events();
        std::uint32_t register_to_event(const char* event_description, const std::function<void(const event&)>& callback);
        bool deregister_from_event(const char* event_description, std::uint32_t id);

    private:
        event_bus();
        ~event_bus();
        event_bus(const event_bus&) = delete;
        event_bus& operator=(const event_bus&) = delete;
        event_bus(event_bus&&) = delete;
        event_bus& operator=(event_bus&&) = delete;

        std::queue<std::unique_ptr<event>> _event_queue;
        std::unordered_map<const char*, event_listeners> _event_listener_map;
    };

}

#endif

