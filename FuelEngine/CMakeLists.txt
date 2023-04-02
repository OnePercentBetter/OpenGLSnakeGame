set(HEADER_FILES
	src/FuelEngineUtil.h
	src/FuelEngineApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWImplementation.h


)

set(SOURCE_FILES
	src/FuelEngineApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWImplementation.cpp
)

add_library(FuelEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(FuelEngine PRIVATE src/pch.h)

target_link_libraries(FuelEngine glfw)

add_definitions(-DFUELENGINE_LIB)
add_definitions(-DFUELENGINE_GLFW)