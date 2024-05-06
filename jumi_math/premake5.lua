project(jumi_math_name)
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

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
   }

   prebuildcommands { }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

      filter "configurations:Debug"
      symbols "On"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/debug/lib",
      }
      links { "glm" }

      filter "configurations:Release"
      optimize "On"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/lib",
      }
      links { "glm" }

