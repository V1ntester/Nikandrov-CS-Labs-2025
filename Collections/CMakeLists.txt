cmake_minimum_required(VERSION 3.20)

set(project "Collections")
project(${project})

set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Set.h
)

set(SOURCE_LIST 
    ${HEADERS}
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_library(${project} INTERFACE ${SOURCE_LIST})

if(ENABLE_DEBUG)
    target_compile_options(${project} INTERFACE -g)
endif()
