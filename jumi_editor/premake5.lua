project(editor_name)
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   dependson "engine_core"

   files 
   {
       "src/**.cpp",
       "src/**.h",
   }

   includedirs 
   {
       "src",
       "../vcpkg_installed/%{triplet}/include",
       "../" .. engine_core_name .. "/include",
       "../" .. jumi_math_name .. "/include",
   }

   prebuildcommands { }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

      filter "configurations:Debug"
      symbols "On"
      libdirs 
      {
          "../" .. engine_core_name .. "/bin/Debug",
          "../" .. jumi_math_name .. "/bin/Debug",
          "../vcpkg_installed/%{triplet}/debug/lib",
      }
      links { engine_core_name .. "d", "imguid" }

      filter "configurations:Release"
      optimize "On"
      libdirs 
      {
          "../" .. engine_core_name .. "/bin/Release",
          "../" .. jumi_math_name .. "/bin/Release",
          "../vcpkg_installed/%{triplet}/lib",
      }
      links { engine_core_name, "imgui" }

