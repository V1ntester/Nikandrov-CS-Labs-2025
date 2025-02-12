cmake_minimum_required(VERSION 3.20)

set(project "lab_2")
project(${project})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Planet)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_executable(${project} ${SOURCES})
target_compile_options(${project} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(main PRIVATE -g)
endif()

target_link_libraries(${project} Planet)
