#ifndef JUMI_ENGINE_ENGINE_CORE_RENDERER_OPENGL_RENDERER_H
#define JUMI_ENGINE_ENGINE_CORE_RENDERER_OPENGL_RENDERER_H

#include <internal/interfaces/i_renderer.h>

namespace jumi
{

    class opengl_renderer : public i_renderer
    {
    public:
        opengl_renderer();
        ~opengl_renderer();

        virtual void init() override;
        virtual void set_clear_color(const vec3& color) override;
        virtual void clear_color_buffer() const override;
        virtual void clear_depth_buffer() const override;

    private:

    };

}

#endif
