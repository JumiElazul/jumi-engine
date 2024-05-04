#include "engine_core/resources/resource_manager.h"
#include "internal/resources/shader_library.h"
#include <filesystem>
#include <string>

namespace jumi
{

    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    //                                             IMPLEMENTATION
    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    class resource_manager_impl
    {
    public:
        // TODO: The way we construct the _base_resource_path is a total hack.  Will work for now for debugging purposes,
        // but will implement a more robust solution later.
        resource_manager_impl()
            : _base_resource_path(std::filesystem::current_path().parent_path().string() + "\\engine_core\\resources\\")
            , _shader_resource_path(_base_resource_path + "shaders\\")
            , _shader_library(_shader_resource_path)
        {
            initialize_default_resources();
        }

        ~resource_manager_impl()
        {

        }

        const std::string& base_resource_path() const
        {
            return _base_resource_path;
        }

        const std::string& shader_resource_path() const
        {
            return _shader_resource_path;
        }

    private:
        const std::string _base_resource_path;
        const std::string _shader_resource_path;
        shader_library _shader_library;

        void initialize_default_resources()
        {
            _shader_library.initialize_default_shaders();
        }

    };


    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    //                                             INTERFACE
    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    const std::string& resource_manager::base_resource_path() const
    {
        return _resource_manager_impl->base_resource_path();
    }

    const std::string& resource_manager::shader_resource_path() const
    {
        return _resource_manager_impl->shader_resource_path();
    }

    resource_manager::resource_manager()
        : _resource_manager_impl(std::make_unique<resource_manager_impl>())
    {

    }

    resource_manager::~resource_manager()
    {

    }

}