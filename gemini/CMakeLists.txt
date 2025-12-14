cmake_minimum_required(VERSION 3.12)

project(Engine LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ENGINE_SRC
	src/engine.cpp
	src/graphics/window.cpp
	../external/glad/src/glad.c
)

add_library(Engine STATIC
	${ENGINE_SRC}
)

target_include_directories(Engine PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	../external/glad/include
	../external/glm-1.0.2
	../external/SDL3-3.2.28/include
)

# Link SDL3 and glad (adjust .lib/.a names as needed for your platform)
target_link_libraries(Engine
	PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/../external/SDL3-3.2.28/lib/x64/SDL3.lib
)

