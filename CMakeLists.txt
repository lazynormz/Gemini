# CMakeLists.txt : Top-level CMake project file for global configuration
cmake_minimum_required(VERSION 3.10)

# Set C++ standard globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subprojects
add_subdirectory(engine)
add_subdirectory(executer)
