#ifndef JUMI_ENGINE_ENGINE_CORE_INTERFACES_I_RENDERER_H
#define JUMI_ENGINE_ENGINE_CORE_INTERFACES_I_RENDERER_H

#include "internal/interfaces/i_requires_init.h"
#include "internal/math/math_types.h"

namespace jumi
{

    class i_renderer : public i_requires_init
    {
    public:
        virtual ~i_renderer() = default;
        virtual void init() override = 0;
        virtual void clear_color_buffer() const = 0;
        virtual void clear_depth_buffer() const = 0;
        virtual void set_clear_color(const vec3& color) = 0;
        virtual vec3 get_clear_color() { return _clear_color; }

    protected:
        vec3 _clear_color;
    };

}

#endif

