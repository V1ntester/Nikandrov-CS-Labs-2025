cmake_minimum_required(VERSION 3.20)

set(project "lab_5")
project(${project})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Handler.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Handler.h
)

add_subdirectory(Collections)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

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

target_link_libraries(${project} Collections)
