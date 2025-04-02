cmake_minimum_required(VERSION 3.20)

set(project "Stack")
project(${project})

set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/Stack.h
)

set(SOURCE_LIST 
    ${SOURCES}
    ${HEADERS}
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_library(${project} STATIC ${SOURCE_LIST})

if(ENABLE_DEBUG)
    target_compile_options(${project} PRIVATE -g)
endif()
