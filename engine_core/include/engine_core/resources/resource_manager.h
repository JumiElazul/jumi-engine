#ifndef JUMI_ENGINE_RESOURCES_RESOURCE_MANAGER_H_
#define JUMI_ENGINE_RESOURCES_RESOURCE_MANAGER_H_

#include <memory>
#include <string>

namespace jumi
{
    class resource_manager_impl;
    class shader;

    class resource_manager
    {
    friend class engine_core;
    public:
        void init();

        const std::string& base_resource_path() const;
        const std::string& shader_resource_path() const;
        const std::string& default_shader_name() const;
        std::shared_ptr<shader> get_shader(const std::string& shader_name) const;

    private:
        std::unique_ptr<resource_manager_impl> _resource_manager_impl;

        resource_manager();
        ~resource_manager();
        resource_manager(const resource_manager& other) = delete;
        resource_manager& operator=(const resource_manager& other) = delete;
        resource_manager(resource_manager&& other) = delete;
        resource_manager& operator=(resource_manager&& other) = delete;
    };

}

#endif
