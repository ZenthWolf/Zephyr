--The Solution
workspace "Zephyr"
	architecture "x64"
	configurations { "Debug", "Release", "Dist"}
	startproject "Sandbox"

--Ex: "Windows-x64-Debug"
outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

--Include directories
IncludeDir = {}
IncludeDir["GLFW"] = "Zephyr/vendor/GLFW/include"

include "Zephyr/vendor/GLFW"

--Project in Solution
project "Zephyr"
	location "Zephyr"
	--SharedLib is DynamicLib
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "ZephyrPCH.h"
	pchsource "Zephyr/src/ZephyrPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	--Platform specifics
	filter "system:windows"
		cppdialect "C++14"
		--Static linking of libraries
		staticruntime "On"
		--Windows SDK version
		systemversion "latest"

		defines
		{
			"ZW_WINDOWS_PLATFORM",
			"ZW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	-- Note: Only one "filter" applied at once
	-- Use {cond1, cond2} for multiple filter conditions
	filter "configurations:Debug"
		defines "ZW_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "ZW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZW_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Zephyr/vendor/spdlog/include",
		"Zephyr/src"
	}

	links
	{
		"Zephyr"
	}

	--Platform specifics
	filter "system:windows"
		cppdialect "C++14"
		--Static linking of libraries
		staticruntime "On"
		--Windows SDK version
		systemversion "latest"

		defines
		{
			"ZW_WINDOWS_PLATFORM"
		}

	-- Note: Only one "filter" applied at once
	-- Use {cond1, cond2} for multiple filter conditions
	filter "configurations:Debug"
		defines "ZW_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "ZW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZW_DIST"
		optimize "On"