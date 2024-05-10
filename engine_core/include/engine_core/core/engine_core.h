#ifndef JUMI_ENGINE_ENGINE_CORE_CORE_ENGINE_CORE_H
#define JUMI_ENGINE_ENGINE_CORE_CORE_ENGINE_CORE_H

namespace jumi
{

    class engine_core
    {
    public:
        static engine_core& instance();
        void print(const char* str) const;

    private:
        engine_core() = default;
        ~engine_core() = default;
        engine_core(const engine_core& other) = delete;
        engine_core& operator=(const engine_core& other) = delete;
        engine_core(engine_core&& other) = delete;
        engine_core& operator=(engine_core&& other) = delete;
    };

}

#endif

