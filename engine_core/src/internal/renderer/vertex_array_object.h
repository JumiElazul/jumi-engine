#ifndef JUMI_ENGINE_RENDERER_VERTEX_ARRAY_OBJECT_H
#define JUMI_ENGINE_RENDERER_VERTEX_ARRAY_OBJECT_H

#include "engine_core/renderer/i_opengl_resource.h"

namespace jumi
{

    class vertex_array_object : public i_opengl_resource
    {
    public:
        vertex_array_object();
        ~vertex_array_object();
        vertex_array_object(const vertex_array_object& other) = delete;
        vertex_array_object operator=(const vertex_array_object& other) = delete;
        vertex_array_object(vertex_array_object&& other) noexcept;
        vertex_array_object& operator=(vertex_array_object&& other) noexcept;

        [[nodiscard]] const unsigned int& opengl_id() const;
        void bind() const;
        static void unbind();

    private:
        unsigned int _opengl_id;

        virtual void release_opengl_resource() override;
    };

}

#endif
