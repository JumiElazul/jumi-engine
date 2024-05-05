#ifndef JUMI_ENGINE_RENDERER_I_OPENGL_RESOURCE_H
#define JUMI_ENGINE_RENDERER_I_OPENGL_RESOURCE_H

namespace jumi
{

    class i_opengl_resource
    {
    public:
        virtual ~i_opengl_resource() = default;
        virtual void release_opengl_resource() = 0;
    };

}

#endif
