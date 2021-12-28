cmake_minimum_required(VERSION 3.16)
project(ROVMissions)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Mission)
add_subdirectory(MissionEditor)
add_subdirectory(App)


add_executable(ROVMissions main.cpp)
target_link_libraries(ROVMissions PUBLIC App)

#add_executable(ROVMissions main.cpp Mission/Mission.cpp Mission/Mission.h Mission/Dive.cpp Mission/Dive.h Mission/Lift.cpp Mission/Lift.h Mission/Move.cpp Mission/Move.h Mission/Return.cpp Mission/Return.h MissionEditor/MissiobEditor.cpp MissionEditor/MissiobEditor.h App/App.cpp App/App.h)