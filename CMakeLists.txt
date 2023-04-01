cmake_minimum_required(VERSION 3.24)

project(GAME_DEVELOPMENT_PROJECT)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DFUELENGINE_WINDOWS)
elseif(APPLE)
	add_definitions(-DFUELENGINE_MACOS)
else()
	add_definitions(-DFUELENGINE_LINUX)
endif()

add_subdirectory(FuelEngine)
add_subdirectory(GAME_DEVELOPMENT)
add_subdirectory(glfw)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SPRING_GAME)