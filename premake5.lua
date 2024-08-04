

-- SOLUTION Template
workspace "test"


	configurations 
	{	
		"Debug", 
		"Release" 
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"  


-- PROJECT: DLL
project "test_dll"
location "test_dll"
kind	"SharedLib" 
language "C"
cdialect "C11"
fatalwarnings { "4700"; "6001" }
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )	
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )	
	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.c"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs	
	{
		"%{wks.location}/%{prj.name}/src"
	}


	filter "system:Windows"
	 	systemversion "latest"
		architecture "x86_64"
		cdialect "C11"
		pchheader "pch.h"
		pchsource "%{prj.name}/src/pch.c"


	filter "system:macosx"
		architecture "ARM64"
		cdialect "C11"
        pchheader "src/pch.h"

	filter "configurations:Debug"
			defines	"test_DEBUG"
			symbols  "On"

	filter "configurations:Release"
			defines	"test_RELEASE"
			optimize "On"
			intrinsics "off"
			inlining "Auto"

