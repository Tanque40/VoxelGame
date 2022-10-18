workspace "VoxelGame"
    architecture "x64"

    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories
IncludeDirs = {}
IncludeDirs["GLFW"] = "VoxelGame/vendor/GLFW/include"

-- Search for other projects
include "VoxelGame/vendor/GLFW"

project "VoxelGame"
    location "VoxelGame"
    kind "consoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    systemversion "latest"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDirs.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        symbols "On"