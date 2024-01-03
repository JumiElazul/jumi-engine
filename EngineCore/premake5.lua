project "EngineCore"
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files
   {
       "src/components/camera.cpp",
       "src/components/directional_light.cpp",
       "src/components/scene.cpp",
       "src/components/scene_object.cpp",
       "src/components/transform.cpp",
       "src/core/engine_core.cpp",
       "src/events/event_bus.cpp",
       "src/input/input_handler.cpp",
       "src/input/keycodes.cpp",
       "src/log/logger.cpp",
       "src/math/functions.cpp",
       "src/math/functions.h",
       "src/math/matrix.cpp",
       "src/math/vector.cpp",
       "src/renderer/mesh.cpp",
       "src/renderer/renderer.cpp",
       "src/renderer/shader.cpp",
       "src/renderer/vertex_array_object.cpp",
       "src/renderer/vertex_array_object.h",
       "src/resources/resource_library.cpp",
       "src/window/window_handler.cpp",

       "include/EngineCore/core/core.h",
       "include/EngineCore/components/camera.h",
       "include/EngineCore/components/component_interface.h",
       "include/EngineCore/components/directional_light.h",
       "include/EngineCore/components/transform.h",
       "include/EngineCore/components/scene.h",
       "include/EngineCore/components/scene_object.h",
       "include/EngineCore/math/matrix.h",
       "include/EngineCore/math/vector.h",
       "include/EngineCore/events/event_bus.h",
       "include/EngineCore/input/keycodes.h",
       "include/EngineCore/input/input_handler.h",
       "include/EngineCore/log/logger.h",
       "include/EngineCore/renderer/mesh.h",
       "include/EngineCore/renderer/renderer.h",
       "include/EngineCore/renderer/shader.h",
       "include/EngineCore/resource_library.h",
       "include/EngineCore/window_handler.h",
   }

   includedirs
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include"
   }

   filter "system:windows"
      defines { "JUMI_WINDOWS", "GLFW_INCLUDE_NONE" }

   filter "configurations:Debug"
      symbols "On"
      libdirs { "../vcpkg_installed/%{triplet}/debug/lib" }
      links { "fmtd", "glad", "glfw3", "spdlogd" }

   filter "configurations:Release"
      optimize "On"
      libdirs { "../vcpkg_installed/%{triplet}/lib" }
      links { "fmt", "glad", "glfw3", "spdlog" }

