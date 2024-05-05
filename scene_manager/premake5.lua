project(scene_manager_name)
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   -- dependson "engine_core"

   files 
   {
       "src/**.cpp",
       "src/**.h",
   }

   includedirs 
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include",
       -- "../" .. engine_core_name .. "/include",
   }

   prebuildcommands { }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

      filter "configurations:Debug"
      symbols "On"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/debug/lib",
          -- "../" .. engine_core_name .. "/bin/Debug",
      }
      links {  }

      filter "configurations:Release"
      optimize "On"
      libdirs 
      {
          -- "../" .. engine_core_name .. "/bin/Release",
          "../vcpkg_installed/%{triplet}/lib",
      }
      links {  }

