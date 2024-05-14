#ifndef JUMI_ENGINE_ENGINE_CORE_RENDERER_VULKAN_RENDERER_H
#define JUMI_ENGINE_ENGINE_CORE_RENDERER_VULKAN_RENDERER_H

#include <internal/interfaces/i_renderer.h>

namespace jumi
{

    class vulkan_renderer : public i_renderer
    {
    public:
        vulkan_renderer();
        ~vulkan_renderer();

        virtual void clear_color_buffer() const override;
        virtual void clear_depth_buffer() const override;

    private:

    };

}

#endif
