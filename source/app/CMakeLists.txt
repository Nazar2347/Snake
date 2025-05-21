project(SnakeMain)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} 
	PUBLIC ./
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC SnakeCoreLib
	PUBLIC SnakeRenderLib
)