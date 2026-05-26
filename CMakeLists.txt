cmake_minimum_required(VERSION 3.31)
project(SControl LANGUAGES C CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_subdirectory(Dependencies/glfw)
add_subdirectory(Dependencies/imgui)
set(MY_CUSTOM_BIN_DIR "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>-$<PLATFORM_ID>")

# Force all executable targets to compile into this specific directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${MY_CUSTOM_BIN_DIR}")

add_subdirectory(src)



