cmake_minimum_required(VERSION 3.20)

set(project "lab_8")
project(${project})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Handler.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Handler.h
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Tasks)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Output.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project} ${SOURCES} ${HEADERS})
target_compile_options(${project} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(${project} PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run
    -Werror
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(${project} Tasks)
