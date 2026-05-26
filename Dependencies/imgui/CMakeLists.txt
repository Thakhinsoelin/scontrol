# Create a static library for ImGui
add_library(imgui STATIC
    imgui.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui_demo.cpp
    backend/imgui_impl_glfw.cpp
    backend/imgui_impl_opengl3.cpp
)

# Tell anyone linking to 'imgui' that they must include this folder
target_include_directories(imgui PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backend
)

# Link against GLFW because the backend needs it
target_link_libraries(imgui PUBLIC glfw)