cmake_minimum_required(VERSION 3.10)
project(SEngineProject)

# Добавляем директорию с Google Test
# add_subdirectory(../googletest ${CMAKE_BINARY_DIR}/googletest)

# Указываем директорию с заголовками Google Test
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Добавляем тесты
# add_executable(runTests tests/core/GameLoopTest.cpp tests/graphics/RendererTest.cpp)
# target_link_libraries(runTests gtest gtest_main)

# Добавляем флаг для компиляции тестов
# enable_testing()
# add_test(AllTests runTests)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Указываем директории с заголовочными файлами
include_directories(include)

# Указываем исходные файлы
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Создаем исполняемый файл
add_executable(SEngine ${SOURCES})

# Подключаем сторонние библиотеки
# target_link_libraries(SEngine SDL2 OpenGL Bullet)

# Опции для отладки
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(SEngine PRIVATE DEBUG)
endif()