cmake_minimum_required(VERSION 3.20)

set(project "Persons")
project(${project})

set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Person.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Employee.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Worker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engineer.cpp
)

set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/Person.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Employee.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Worker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engineer.h
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
