cmake_minimum_required(VERSION 3.20)

set(project "Tasks")
project(${project})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Tasks.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Inventory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Box.cpp
)

set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/Task.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Tasks.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Inventory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Box.h
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
