#ifndef JUMI_ENGINE_ENGINE_CORE_RENDERER_DIRECT3D_RENDERER_H
#define JUMI_ENGINE_ENGINE_CORE_RENDERER_DIRECT3D_RENDERER_H

#include <internal/interfaces/i_renderer.h>

namespace jumi
{

    class direct3d_renderer : public i_renderer
    {
    public:
        direct3d_renderer();
        ~direct3d_renderer();

        virtual void clear_color_buffer() const override;
        virtual void clear_depth_buffer() const override;

    private:

    };

}

#endif
