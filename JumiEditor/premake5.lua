project "JumiEditor"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files
   {
       "src/application/main.cpp",
       "src/editor/imgui_component.h",
       "src/editor/imgui_component.cpp",
       "src/editor/imgui_core.cpp",
       "src/editor/imgui_core.h",
       "src/editor/scene_hierarchy.cpp",
       "src/editor/scene_hierarchy.h",
       "src/editor/properties_inspector.cpp",
       "src/editor/properties_inspector.h",
       "src/editor/header_bar.cpp",
       "src/editor/header_bar.h",
       "src/editor/scene_view.cpp",
       "src/editor/scene_view.h",
   }

   includedirs
   {
       "src",
       "../EngineCore/include/",
       "../vcpkg_installed/%{triplet}/include/"
   }

   libdirs
   {
       "../vcpkg_installed"
   }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

   filter "configurations:Debug"
      symbols "On"
      libdirs { "../vcpkg_installed/%{triplet}/debug/lib" }
      links { "EngineCore", "imguid" }

   filter "configurations:Release"
      optimize "On"
      libdirs { "../vcpkg_installed/%{triplet}/lib" }
      links { "EngineCore", "imgui" }

