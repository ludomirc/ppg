CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#set(CMAKE_C_COMPILER "/app/Cpp/gcc8.2.0/bin/gcc")
#set(CMAKE_CXX_COMPILER "/app/Cpp/gcc8.2.0/bin/g++")

project(OGLSamples)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/Modules/")

if(CMAKE_CONFIGURATION_TYPES)
    set(CONFIGURATION_TYPE ${CMAKE_CFG_INTDIR})
else()
    set(CONFIGURATION_TYPE ${CMAKE_BUILD_TYPE})
endif()

if(MSVC)
	if (MSVC_VERSION GREATER_EQUAL "1900")
		include(CheckCXXCompilerFlag)
		CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
                if (_cpp_latest_flag_supported)
                        add_compile_options("/std:c++latest")
		endif()
	endif()
	#set(COMPILER_RELEASE_FLAGS "/arch:SSE2 /fp:precise /MP /O2 /Zc:inline /MT /W3 /GL /OPT:ICF /INCREMENTAL:NO")
	set(COMPILER_RELEASE_FLAGS "/arch:SSE2 /fp:precise /MP /O2 /Zc:inline /MD /W3 /OPT:ICF /INCREMENTAL:NO")
	set(COMPILER_DEBUG_FLAGS "/arch:SSE2 /fp:precise /MP /Od /MDd /W4 /OPT:NOICF /INCREMENTAL /DEBUG")
else()
        set(COMPILER_FLAGS "--std=c++17")
        set(COMPILER_RELEASE_FLAGS "-O2")
#        set(COMPILER_DEBUG_FLAGS "--std=c++17")
		if(APPLE)		
			set(LINKER_FLAGS "-framework OpenGL -lglfw -lglbinding -lpthread")
	 	else()		 
        	set(LINKER_FLAGS "--std=c++17 -lGL -lglfw -lpthread")
		endif()
endif()

message("Binary tree path: ${PROJECT_BINARY_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/../Libs/glm/include"
        "${PROJECT_SOURCE_DIR}/../Libs/gli/include"
)

add_subdirectory(OGLSample1)
add_subdirectory(OGLSample2_IB_VBO)
add_subdirectory(buffor1)
add_subdirectory(buffor2)
add_subdirectory(buffor3)
add_subdirectory(uniform1)
add_subdirectory(przeksztalceniaPVM)
