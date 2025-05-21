project (SnakeCoreLib)

file (GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "./include/*.h")
file (GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "./src/*.cpp")

add_library(${PROJECT_NAME} 
	${CORE_HEADERS}
	${CORE_SOURCES}
)

target_include_directories (${PROJECT_NAME} 
	PUBLIC ./include 
	PRIVATE ./src
)

