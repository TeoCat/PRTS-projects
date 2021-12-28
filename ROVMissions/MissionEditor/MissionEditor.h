#pragma once

#include "Mission.h"

#include <fstream>
#include <memory>
#include <vector>

class MissionEditor {
public:
    MissionEditor()  = default;
    ~MissionEditor() = default;

    string CreateNewFile(const string& path);

    bool InsertNewMission(unique_ptr<Mission> new_mission);
    bool RemoveMission(unsigned int id);

    bool RepairRemovedMission(unsigned int removed_id, unsigned int insert_id);

    bool SwapMissions(unsigned int l_id, unsigned int r_id);

    bool ChangeMission(unsigned int id, unique_ptr<Mission> new_mission);

    bool ShowMission(unsigned int id);
    void ShowAllMissions();
    void ShowDeletedMissions();

    bool IsLastMissionIsReturn();

private:
    void DropInFileAllMissions();
    void DropInFileLastMission();

private:
    vector<unique_ptr<Mission>> _pool;
    vector<unique_ptr<Mission>> _delete_pool;
    string _filename;
    fstream _file;
};

