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
   }

   libdirs
   {

   }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

   filter "configurations:Debug"
      symbols "On"
      links { "EngineCore" }

   filter "configurations:Release"
      optimize "On"
      links { "EngineCore" }

