project(engine_core_name)
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   dependson(jumi_math_name)

   files 
   {
       "src/**.cpp",
       "src/**.h",
       "include/**.h",
   }

   includedirs
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include",
       "../" .. jumi_math_name .. "/include",
   }

   filter "system:windows"
      defines { "JUMI_WINDOWS", "JUMI_EXPORT_API", "GLFW_INCLUDE_NONE" }

   filter "configurations:Debug"
      symbols "On"
      targetname(engine_core_name .. "d")
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/debug/lib",
      }
      links { "fmtd", "glfw3", "glad", "spdlogd" }

   filter "configurations:Release"
      optimize "On"
      targetname(engine_core_name)
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/lib" 
      }
      links { "fmt", "glfw3", "glad", "spdlog" }
