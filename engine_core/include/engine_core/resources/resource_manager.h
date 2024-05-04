#ifndef JUMI_ENGINE_RESOURCES_RESOURCE_MANAGER_H_
#define JUMI_ENGINE_RESOURCES_RESOURCE_MANAGER_H_

#include <memory>
#include <string>

namespace jumi
{
    class resource_manager_impl;

    class resource_manager
    {
    friend class engine_core;
    public:

    private:
        std::unique_ptr<resource_manager_impl> _resource_manager_impl;

        std::string resource_path() const;
        std::string shader_path() const;

        resource_manager();
        ~resource_manager();
        resource_manager(const resource_manager& other) = delete;
        resource_manager& operator=(const resource_manager& other) = delete;
        resource_manager(resource_manager&& other) = delete;
        resource_manager& operator=(resource_manager&& other) = delete;
    };

}

#endif
