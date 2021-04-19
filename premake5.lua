workspace "Nut"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nut"
    location "Nut"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NUT_PLATFORM_WINDOWS",
            "NUT_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "NUT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NUT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NUT_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Nut/vendor/spdlog/include",
        "Nut/src"
    }

    links
    {
        "Nut"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NUT_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "NUT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NUT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NUT_DIST"
        optimize "On"