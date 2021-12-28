cmake_minimum_required(VERSION 3.16)
project(App)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB App.cpp)

add_library(App STATIC ${SOURCE_LIB})

target_include_directories(App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(App PUBLIC MissionEditor)