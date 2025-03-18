cmake_minimum_required(VERSION 3.20)

set(project "Test")
project(${project})

set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
)

add_subdirectory(Library)

set(SOURCE_LIST 
    ${SOURCES}
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_executable(${project} ${SOURCE_LIST})

if(ENABLE_DEBUG)
    target_compile_options(${project} PRIVATE -g)
endif()

target_link_libraries(${project} Patient)
