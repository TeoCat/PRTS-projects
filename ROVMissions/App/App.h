#pragma once

#include <iostream>

#include "MissionEditor.h"


enum Actions {
    NEW_MISSION = 0,
    DELETE_MISSION,
    CHANGE_MISSION,
    SWAP_MISSIONS,
    SHOW_MISSIONS,
    REPAIR_MISSION,
    STOP
};

class App {
public:
    App() = default;
    ~App() = default;
    int Run();

private:
    void InsertNewMission();
    void DeleteMission();
    void ChangeMission();
    void SwapMissions();
    void RepairMission();
    void ShowMissions();
    bool Stop();

    unique_ptr<Mission> CreateNewMission();

    unique_ptr<Mission> CreateDiveMission();
    unique_ptr<Mission> CreateLiftMission();
    unique_ptr<Mission> CreateMoveMission();
    unique_ptr<Mission> CreateReturnMission();



private:
    MissionEditor _pool;
};

