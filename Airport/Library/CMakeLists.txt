cmake_minimum_required(VERSION 3.20)

set(project "Airport")
project(${project})

set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Airport.cpp
)

set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/Airport.h
)

set(SOURCE_LIST 
    ${SOURCES}
    ${HEADERS}
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

if(ENABLE_DEBUG)
    target_compile_options(${project} PRIVATE -g)
endif()

add_library(${project} STATIC ${SOURCE_LIST})
