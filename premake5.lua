workspace "jumi-engine"
   configurations { "Debug", "Release" }
   startproject "JumiEditor"
   architecture "x64"
   platforms "x64"
   cppdialect "C++20"
   flags { "MultiProcessorCompile" }
   staticruntime "On"

   local function determine_triplet()
       if os.host() == "windows" then
           return "x64-windows-static"
       elseif os.host() == "linux" then
           return "x64-linux"
       else
           return "unsupported"
       end
   end
   triplet = determine_triplet()

   include "EngineCore/premake5.lua"
   include "JumiEditor/premake5.lua"
