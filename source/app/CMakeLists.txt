project(SnakeMain)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} 
	PUBLIC ./
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC SnakeCoreLib
	PUBLIC SnakeRenderLib
)
# === Custom target to copy assets folder ===
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/Assets
    COMMENT "Copying Assets to output directory"
)

