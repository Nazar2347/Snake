project (UnitTests)

file (GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")

include (FetchContent)

FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v3.8.1 
)
FetchContent_MakeAvailable(Catch2)

add_executable (${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries( ${PROJECT_NAME}
	PRIVATE Catch2::Catch2WithMain
	PRIVATE ExternalLibrary
	PRIVATE SnakeCoreLib
)

list (APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

enable_testing()
include (CTest)
include (Catch)
catch_discover_tests(${PROJECT_NAME})

add_custom_target(AllTests ALL
    COMMAND ${CMAKE_CTEST_COMMAND} ${CMAKE_BINARY_DIR}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Running tests"
) # Makes program run Unit testing during build procces