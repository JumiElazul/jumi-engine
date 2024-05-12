#ifndef JUMI_ENGINE_INTERNAL_INTERFACES_I_REQUIRES_INIT_H
#define JUMI_ENGINE_INTERNAL_INTERFACES_I_REQUIRES_INIT_H

namespace jumi
{

    class i_requires_init
    {
    public:
        virtual ~i_requires_init() = default;
        virtual void init() = 0;

    protected:
        bool _initialized = false;
    };

}

#endif