cmake_minimum_required(VERSION 3.16)
project(ROVMissions)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Mission)
add_subdirectory(MissionEditor)
add_subdirectory(App)


add_executable(ROVMissions main.cpp)
target_link_libraries(ROVMissions PUBLIC App)
