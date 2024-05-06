engine_core_name = "engine_core"
jumi_math_name = "jumi_math"
editor_name = "jumi_editor"

workspace "jumi_engine"
   configurations { "Debug", "Release" }
   architecture "x64"
   platforms "x64"
   cppdialect "C++20"
   flags { "MultiProcessorCompile" }
   staticruntime "On"
   startproject(editor_name)

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

   include(engine_core_name .. "/premake5.lua")
   include(jumi_math_name .. "/premake5.lua")
   include(editor_name .. "/premake5.lua")
