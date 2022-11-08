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
IncludeDirs["GLAD"] = "VoxelGame/vendor/Glad/include"

-- Search for other projects
include "VoxelGame/vendor/GLFW"
include "VoxelGame/vendor/Glad"

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
        "%{IncludeDirs.GLAD}",
        "%{IncludeDirs.GLFW}"
    }

    links {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    defines {
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        symbols "On"