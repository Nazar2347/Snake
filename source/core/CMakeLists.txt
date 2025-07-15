project (SnakeCoreLib)
include (CMakePrintHelpers)
file (GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "./include/*.h")
file (GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "./src/*.cpp")

add_library(${PROJECT_NAME} STATIC
	${CORE_HEADERS}
	${CORE_SOURCES}
)

target_include_directories (${PROJECT_NAME} 
	PUBLIC ./include 
	PRIVATE ./src
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC ExternalLibrary)

