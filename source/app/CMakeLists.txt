project(SnakeMain)
file (GLOB_RECURSE GAME_HEADERS CONFIGURE_DEPENDS "./Game/*.h")
file (GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "./Game/*.cpp")
add_executable(${PROJECT_NAME} main.cpp
${GAME_SOURCES})

target_include_directories(${PROJECT_NAME} 
	PUBLIC ./
	PUBLIC ./Game
)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE SnakeCoreLib
	PRIVATE SnakeRenderLib
)
# === Custom target to copy assets folder ===
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/Assets
    COMMENT "Copying Assets to output directory"
)

