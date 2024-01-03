project "JumiEditor"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files
   {
       "src/application/main.cpp",
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

