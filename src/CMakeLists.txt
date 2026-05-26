set(CMD cmdprogram)

# 2. Define the executable (using the project name from root)
add_executable(${PROJECT_NAME} 
                main.cpp
                )

add_executable(${CMD}
                ${CMAKE_CURRENT_SOURCE_DIR}/cmdprogram/cmdMain.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/cmdprogram/Cmd.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/cmdprogram/Cmd.h
                ${CMAKE_CURRENT_SOURCE_DIR}/cmdprogram/Commands.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/cmdprogram/Commands.h
                
            )

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>-$<PLATFORM_ID>"
)
set_target_properties(${CMD} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>-$<PLATFORM_ID>"
)
# 3. Include directories
# We use PARENT_SCOPE or absolute paths to find the Dependencies folder
target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_SOURCE_DIR}/Dependencies"
)
target_include_directories(${CMD} PRIVATE 
    "${CMAKE_SOURCE_DIR}/Dependencies"
)

find_package(OpenGL REQUIRED)
# 4. Link everything
target_link_libraries(${PROJECT_NAME} PRIVATE 
    imgui
    glfw
    OpenGL::GL
)

### might necessary later
# add_custom_target(copy_assets ALL
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#             "${CMAKE_SOURCE_DIR}/textures"
#             "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>-$<PLATFORM_ID>/textures"

#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#             "${CMAKE_SOURCE_DIR}/models"
#             "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>-$<PLATFORM_ID>/models"
# )

# add_dependencies(${PROJECT_NAME} CompileShaders copy_assets)