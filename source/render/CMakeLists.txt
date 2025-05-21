project (SnakeRenderLib)

file (GLOB_RECURSE RENDER_HEADERS CONFIGURE_DEPENDS "./include/*.h")
file (GLOB_RECURSE RENDER_SOURCES CONFIGURE_DEPENDS "./src/*.cpp")

add_library (${PROJECT_NAME} 
	${RENDER_HEADERS}
	${RENDER_SOURCES}
)

target_include_directories(${PROJECT_NAME} 
	PUBLIC ./include
	PRIVATE ./src
)

