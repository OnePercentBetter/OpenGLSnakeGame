set(HEADER_FILES
	src/FuelEngineUtil.h
	src/FuelEngineApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWImplementation.h
	src/Renderer.h
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/RendererTypes.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h
	src/Unit.h
	src/RendererTypes.h
	src/FuelEngineEvents.h
	src/FuelEngineKeys.h
)

set(SOURCE_FILES
	src/FuelEngineApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWImplementation.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/OpenGLCode/OpenGLImage.cpp
	src/Image.cpp
	src/Renderer.cpp
	src/Unit.cpp
	src/FuelEngineEvents.cpp
	
)

add_library(FuelEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(FuelEngine PRIVATE src/pch.h)

target_link_libraries(FuelEngine glfw glad stbi)

add_definitions(-DFUELENGINE_LIB)
add_definitions(-DFUELENGINE_GLFW)
add_definitions(-DFUELENGINE_OPENGL)
add_definitions(-DFULENGINE_DEBUG=2)
add_definitions(-DFUELENGINE_WINDOWS)