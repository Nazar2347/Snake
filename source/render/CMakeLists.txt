project (SnakeRenderLib)

file (GLOB_RECURSE RENDER_HEADERS CONFIGURE_DEPENDS "./public/*.h")
file (GLOB_RECURSE RENDER_SOURCES CONFIGURE_DEPENDS "./private/*.cpp")

add_library (${PROJECT_NAME} STATIC
	${RENDER_HEADERS}
	${RENDER_SOURCES}
)

target_include_directories(${PROJECT_NAME} 
	PUBLIC ./public
	PRIVATE ./private
)
target_link_libraries(${PROJECT_NAME} 
	PUBLIC ExternalLibrary
	PRIVATE SnakeCoreLib)

