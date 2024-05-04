#include "engine_core/core/timers.h"
#include <glfw/glfw3.h>

namespace jumi
{

    timers& timers::instance()
    {
        static timers instance;
        return instance;
    }

    timers::timers()
        : _last_frame_time()
        , _current_frame_time()
        , _delta_time()
    {

    }

    void timers::calculate_deltatime()
    {
        _current_frame_time = static_cast<float>(glfwGetTime());
        _delta_time = _current_frame_time - _last_frame_time;
        _last_frame_time = _current_frame_time;
    }

    float timers::delta_time() const
    {
        return _delta_time;
    }

    float timers::time_since_app_start()
    {
        return glfwGetTime();
    }
}
