cmake_minimum_required(VERSION 3.20)

set(project "Polynomial")
project(${project})

set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Term.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Polynomial.cpp
)

set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/Polynomial.h
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Collections)

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

target_link_libraries(${project} Collections)
