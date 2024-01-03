project "EngineCore"
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files
   {
       "src/components/camera.cpp",
       "src/components/camera.h",
       "src/components/component_interface.h",
       "src/components/directional_light.cpp",
       "src/components/directional_light.h",
       "src/components/scene.cpp",
       "src/components/scene.h",
       "src/components/scene_object.cpp",
       "src/components/scene_object.h",
       "src/components/transform.cpp",
       "src/components/transform.h",

       "src/core/core.h",
       "src/core/engine_core.cpp",

       "src/events/event_bus.cpp",
       "src/events/event_bus.h",

       "src/input/input_handler.cpp",
       "src/input/input_handler.h",
       "src/input/keycodes.cpp",
       "src/input/keycodes.h",

       "src/log/logger.cpp",
       "src/log/logger.h",

       "src/math/functions.cpp",
       "src/math/functions.h",
       "src/math/matrix.cpp",
       "src/math/matrix.h",
       "src/math/vector.cpp",
       "src/math/vector.h",

       "src/renderer/mesh.cpp",
       "src/renderer/mesh.h",
       "src/renderer/renderer.cpp",
       "src/renderer/renderer.h",
       "src/renderer/shader.cpp",
       "src/renderer/shader.h",
       "src/renderer/vertex_array_object.cpp",
       "src/renderer/vertex_array_object.h",

       "src/resources/resource_library.cpp",
       "src/resources/resource_library.h",

       "src/window/window_handler.cpp",
       "src/window/window_handler.h",
   }

   includedirs
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include"
   }

   libdirs
   {
       "../vcpkg_installed/%{triplet}/lib",
       "../vcpkg_installed/%{triplet}/debug/lib"
   }

   filter "system:windows"
      defines { "JUMI_WINDOWS", "GLFW_INCLUDE_NONE" }

   filter "configurations:Debug"
      symbols "On"
      links { "fmtd", "glad", "glfw3", "spdlogd" }

   filter "configurations:Release"
      optimize "On"
      links { "fmt", "glad", "glfw3", "spdlog" }

