cmake_minimum_required(VERSION 3.16)
project(MissionEditor)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB MissionEditor.cpp)

add_library(MissionEditor STATIC ${SOURCE_LIB})

target_include_directories(MissionEditor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MissionEditor PUBLIC Mission)
