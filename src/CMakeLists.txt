file(GLOB_RECURSE SOURCES "./*.cpp")
include_directories("../include", "../vendor/SDL/include/SDL3")
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
endif()