cmake_minimum_required(VERSION 3.16)
project(Mission)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB Dive.cpp Lift.cpp Move.cpp Return.cpp)

add_library(Mission STATIC ${SOURCE_LIB})
target_include_directories(Mission PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})