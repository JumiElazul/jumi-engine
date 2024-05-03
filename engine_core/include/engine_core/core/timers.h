#ifndef JUMI_ENGINE_CORE_TIMERS_H
#define JUMI_ENGINE_CORE_TIMERS_H

namespace jumi
{

    class timers
    {
    friend class engine_core;
    public:
        [[nodiscard]] static timers& instance();
        [[nodiscard]] float delta_time() const;
        [[nodiscard]] float time_since_app_start();

    private:
        float _last_frame_time;
        float _current_frame_time;
        float _delta_time;

        void calculate_deltatime();

        timers();
        ~timers() = default;
        timers(const timers& other) = delete;
        timers& operator=(const timers& other) = delete;
        timers(timers&& other) = delete;
        timers& operator=(timers&& other) = delete;
    };

}

#endif
