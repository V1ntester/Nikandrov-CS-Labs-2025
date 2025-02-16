cmake_minimum_required(VERSION 3.20)

set(project "lab_2")
project(${project})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DataBase.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/DataBase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/List.h
)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Planet)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Planet.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project} ${SOURCES} ${HEADERS})
target_compile_options(${project} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(${project} PRIVATE -g)
endif()

target_link_libraries(${project} Planet)
