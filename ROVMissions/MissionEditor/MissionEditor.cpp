#include "MissionEditor.h"

#include "Mission.h"

#include <iostream>

string MissionEditor::CreateNewFile(const string& path) {
    _filename =  "Missions" + path + ".txt";
    _file.open(_filename, ios::out);
    _file.close();
    return "Missions" + path + ".txt";
}

bool MissionEditor::InsertNewMission(unique_ptr<Mission> new_mission) {
    _pool.emplace_back(move(new_mission));
    DropInFileLastMission();
    return true;
}

bool MissionEditor::RemoveMission(unsigned int id) {
    if (id >= _pool.size()) {
        return false;
    }
    _delete_pool.emplace_back(move(_pool[id]));
    _pool.erase(_pool.begin() + id);
    DropInFileAllMissions();
    return true;
}

bool MissionEditor::SwapMissions(unsigned int l_id, unsigned int r_id) {
    if (l_id >= _pool.size() || r_id >= _pool.size()) {
        return false;
    }
    iter_swap(_pool.begin() + l_id, _pool.begin() + r_id);
    DropInFileAllMissions();
    return true;
}

bool MissionEditor::ChangeMission(unsigned int id, unique_ptr<Mission> new_mission) {
    if (id >= _pool.size()) {
        return false;
    }
    _pool[id] = move(new_mission);
    DropInFileAllMissions();
    return true;
}

bool MissionEditor::ShowMission(unsigned int id) {
    if (id >= _pool.size()) {
        return false;
    }
    cout << _pool[id]->Stringify() << endl;
    return true;
}

void MissionEditor::ShowAllMissions() {
    for (size_t id = 0; id < _pool.size(); ++id) {
        cout << "Id: " << id << endl;
        cout << _pool[id]->Stringify() << endl;
    }
}

void MissionEditor::DropInFileAllMissions() {
    _file.open(_filename, ios::out | ios::trunc);
    for (auto& id : _pool) {
        _file << id->Stringify() << endl;
    }
    _file.close();
}

void MissionEditor::DropInFileLastMission() {
    _file.open(_filename, ios::out | ios::app);
    _file << _pool.back()->Stringify() << endl;
    _file.close();
}

bool MissionEditor::RepairRemovedMission(unsigned int removed_id, unsigned int insert_id) {
    if (removed_id >= _delete_pool.size() || insert_id > _pool.size() + 1) {
        return false;
    }

    _pool.insert(_pool.begin() + insert_id, move(_delete_pool[removed_id]));
    _delete_pool.erase(_delete_pool.begin() + removed_id);
    DropInFileAllMissions();
    return true;
}

void MissionEditor::ShowDeletedMissions() {
    for (size_t id = 0; id < _delete_pool.size(); ++id) {
        cout << "Id: " << id << endl;
        cout << _delete_pool[id]->Stringify() << endl;
    }
}

bool MissionEditor::IsLastMissionIsReturn() { return _pool.back()->TYPE == MissionType::RETURN; }
