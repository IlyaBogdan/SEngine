cmake_minimum_required(VERSION 3.10)
project(SEngineProject)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "D:/programming/SFML-2.6.1/lib/cmake/SFML")
set(SFML_LIB_DIR "D:/programming/SFML-2.6.1/lib")
set(SFML_INCLUDE_DIR "D:/programming/SFML-2.6.1/include")

include_directories(include ${SFML_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(GameEngine ${SOURCES})

find_package(SFML COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
  include_directories(${SFML_LIB_DIR})
  target_link_libraries(GameEngine sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(GameEngine PRIVATE DEBUG)
endif()