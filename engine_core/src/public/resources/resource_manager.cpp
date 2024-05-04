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
        resource_manager_impl()
        {
            construct_resource_paths();
            initialize_default_resources();
        }

        ~resource_manager_impl()
        {

        }

        std::string asset_path() const
        {
            return _asset_path;
        }

        std::string shader_path() const
        {
            return _shader_path;
        }

    private:
        shader_library _shader_library;
        std::string _asset_path;
        std::string _shader_path;

        void construct_resource_paths()
        {
            _asset_path = std::filesystem::current_path().string() + "\\assets\\";

            _shader_path = _asset_path + "shaders\\";
        }

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
    std::string resource_manager::resource_path() const
    {
        return _resource_manager_impl->asset_path();
    }

    std::string resource_manager::shader_path() const
    {
        return _resource_manager_impl->shader_path();
    }

    resource_manager::resource_manager()
        : _resource_manager_impl(std::make_unique<resource_manager_impl>())
    {

    }

    resource_manager::~resource_manager()
    {

    }

}