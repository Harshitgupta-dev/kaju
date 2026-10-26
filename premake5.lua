workspace "kaju"
architecture "x64"
startproject "sandbox"

configurations {"debug", "release", "dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includedir = {}
includedir["GLFW"] = "kaju/vendor/GLFW/include"
includedir["Glad"] = "kaju/vendor/Glad/include"
includedir["imgui"] = "kaju/vendor/imgui"

include "kaju/vendor/GLFW/premake5.lua"
include "kaju/vendor/Glad/premake5.lua"
include "kaju/vendor/imgui/premake5.lua"

project "kaju"
location "kaju"
kind "SharedLib"
language "C++"
buildoptions "/utf-8"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

pchheader "kpch.h"
pchsource "kaju/src/kpch.cpp"

files {"kaju/src/**.h", "kaju/src/**.cpp", "kaju/platforms/**.h", "kaju/platforms/**.cpp", "kaju/src-app/**.h",
-- temperary files for imgui should be implemented in project imgui
       "kaju/vendor/imgui/backends/imgui_impl_opengl3.cpp"}
filter "files:kaju/vendor/imgui/backends/imgui_impl_opengl3.cpp"
flags {"NoPCH"}
filter {}

includedirs {"kaju/vendor/spdlog/include", "kaju/src", "kaju", "%{includedir.GLFW}", "%{includedir.Glad}",
             "%{includedir.imgui}"}

links {"GLFW", "Glad", "imgui", "opengl32.lib"}

defines {"GLFW_INCLUDE_NONE", "KAJU_ENABLE_ASSERT"}

filter "system:windows"
staticruntime "off"
systemversion "latest"

defines {"KAJU_PLATFORM_WINDOWS", "KAJU_BUILD_DLL"}

postbuildcommands {"{MKDIR} ../bin/" .. outputdir .. "/sandbox",
                   "{COPYFILE} %{cfg.buildtarget.abspath} ../bin/" .. outputdir .. "/sandbox/kaju.dll"}

filter "configurations:debug"
defines "KAJU_DEBUG"
runtime "Debug"
symbols "On"

filter "configurations:release"
defines "KAJU_RELEASE"
runtime "Release"
symbols "On"
optimize "On"

filter "configurations:dist"
defines "KAJU_DIST"
runtime "Release"
symbols "Off"
optimize "On"

project "sandbox"
location "sandbox"
kind "ConsoleApp"
language "C++"
buildoptions "/utf-8"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files {"sandbox/src/**.h", "sandbox/src/**.cpp"}

includedirs {"kaju/vendor/spdlog/include", "kaju/src-app"}

links {"kaju"}

filter "system:windows"
staticruntime "off"
systemversion "latest"
defines {"KAJU_PLATFORM_WINDOWS"}

filter "configurations:debug"
defines "KAJU_DEBUG"
runtime "Debug"
symbols "On"

filter "configurations:release"
defines "KAJU_RELEASE"
runtime "Release"
symbols "On"
optimize "On"

filter "configurations:dist"
defines "KAJU_DIST"
runtime "Release"
symbols "Off"
optimize "On"
