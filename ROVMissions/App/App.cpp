#include "App.h"

#include "Dive.h"
#include "Lift.h"
#include "Move.h"
#include "Return.h"

int App::Run() {
    cout << "Launching Mission Configurator" << endl;
    cout << "Enter a name for the new file: " << endl;
    string file_name;
    cin >> file_name;
    cout << "New file created: " << _pool.CreateNewFile(file_name) << endl;

    int action_type;

    while (true) {
        cout << "\nChoose one of the possible actions: \n"
                "\t0 - New mission \n"
                "\t1 - Delete mission \n"
                "\t2 - Change mission \n"
                "\t3 - Reorder Missions \n"
                "\t4 - Show missions \n"
                "\t5 - Restore mission \n"
                "\t6 - Finish mission \n \n";
        cin >> action_type;
        switch (action_type) {
            case NEW_MISSION:
                InsertNewMission();
                break;
            case DELETE_MISSION:
                DeleteMission();
                break;
            case CHANGE_MISSION:
                ChangeMission();
                break;
            case SWAP_MISSIONS:
                SwapMissions();
                break;
            case SHOW_MISSIONS:
                ShowMissions();
                break;
            case REPAIR_MISSION:
                RepairMission();
                break;
            case STOP:
                if (Stop()) {
                    return 0;
                }
                break;
            default:
                cout << "Unknown action, enter again:\n\n";
                break;
        }
    }
}

unique_ptr<Mission> App::CreateNewMission() {
    std::cout << "Select the type of mission to add:\n"
                 "\t0 - Dive\n"
                 "\t1 - Lift\n"
                 "\t2 - Move\n"
                 "\t3 - Return\n\n";
    int tmp;
    MissionType mission_type;
    while (true) {
        cin >> tmp;
        mission_type = static_cast<MissionType>(tmp);
        switch (mission_type) {
            case MissionType::DIVE:
                return CreateDiveMission();
            case MissionType::LIFT:
                return CreateLiftMission();
            case MissionType::MOVE:
                return CreateMoveMission();
            case MissionType::RETURN:
                return CreateReturnMission();
            default:
                cout << "Unknown mission, enter again:\n\n";
        }
    }
}

void App::InsertNewMission() { _pool.InsertNewMission(CreateNewMission()); }

std::unique_ptr<Mission> App::CreateDiveMission() {
    unique_ptr<Mission> dive_mission;
    while (true) {
        int tmp;
        Dive::DiveSensorType dive_sensor_type;
        cout << "Enter depth setting method: \n "
                "\t0 - depth sensor \n"
                "\t1 - echo sounder\n\n";
        while (true) {
            cin >> tmp;
            dive_sensor_type = static_cast<Dive::DiveSensorType>(tmp);
            if (dive_sensor_type == Dive::DiveSensorType::DepthSensor ||
                dive_sensor_type == Dive::DiveSensorType::Echo) {
                break;
            }
            cout << "Wrong way to set depth, enter again:\n\n";
        }

        int depth = 0;
        cout << "Enter the immersion depth (distance): " << endl;
        cin >> depth;

        Dive::DiveMoveType dive_move_type;
        cout << "Enter dive type \n "
                "\t0 - in a spiral \n"
                "\t1 - vertical propellers\n\n";
        while (true) {
            cin >> tmp;
            dive_move_type = static_cast<Dive::DiveMoveType>(tmp);
            if (dive_move_type == Dive::DiveMoveType::Spiral || dive_move_type == Dive::DiveMoveType::VerticalMove) {
                break;
            }
            cout << "Wrong dive type, enter again:\n\n";
        }
        dive_mission = make_unique<Dive>(dive_sensor_type, depth, dive_move_type);
        if (dive_mission->Check()) {
            break;
        }
        cout << "Invalid parameters entered, please enter again\n\n";
    }
    return dive_mission;
}

unique_ptr<Mission> App::CreateLiftMission() {
    unique_ptr<Mission> lift_mission;
    while (true) {
        int tmp;
        Lift::LiftSensorType dive_sensor_type;
        cout << "Enter depth setting method: \n "
                     "\t0 - depth sensor \n"
                     "\t1 - echo sounder\n\n";
        while (true) {
            cin >> tmp;
            dive_sensor_type = static_cast<Lift::LiftSensorType>(tmp);
            if (dive_sensor_type == Lift::LiftSensorType::DepthSensor ||
                dive_sensor_type == Lift::LiftSensorType::Echo) {
                break;
            }
            cout << "Wrong way to set depth, enter again:\n\n";
        }

        int depth = 0;
        cout << "Enter the immersion depth (distance): " << endl;
        cin >> depth;

        Lift::LiftMoveType dive_move_type;
        cout << "Enter dive type \n "
                "\t0 - in a spiral \n"
                "\t1 - vertical propellers\n\n";
        while (true) {
            cin >> tmp;
            dive_move_type = static_cast<Lift::LiftMoveType>(tmp);
            if (dive_move_type == Lift::LiftMoveType::Spiral || dive_move_type == Lift::LiftMoveType::VerticalMove) {
                break;
            }
            cout << "Wrong dive type, enter again:\n\n";
        }

        lift_mission = std::make_unique<Lift>(dive_sensor_type, depth, dive_move_type);
        if (lift_mission->Check()) {
            break;
        }
        cout << "Invalid parameters entered, please enter again\n\n";
    }
    return lift_mission;
}

unique_ptr<Mission> App::CreateMoveMission() {
    unique_ptr<Mission> move_mission;
    while (true) {
        int tmp = 0;

        cout << "Please enter exit type \n"
                "\t0 - exit to point \n"
                "\t1 - movement along a straight line \n\n"
                  << endl;
        Move::MoveType move_type;
        while (true) {
            cin >> tmp;
            move_type = static_cast<Move::MoveType>(tmp);
            if (move_type == Move::MoveType::Point || move_type == Move::MoveType::Line) {
                break;
            }
            cout << "Invalid exit type, enter again:\n\n";
        }

        cout << "Enter output type: \n"
                "\t0 - at constant depth \n"
                "\t1 - at a constant distance from the bottom\n\n";
        Move::DeepMoveType deep_type;
        while (true) {
            cin >> tmp;
            deep_type = static_cast<Move::DeepMoveType>(tmp);
            if (deep_type == Move::DeepMoveType::ConstDepth || deep_type == Move::DeepMoveType::ConstDistanceToBottom) {
                break;
            }
            cout << "Invalid exit type, enter again:\n\n";
        }

        unsigned int x;
        unsigned int y;
        unsigned int accuracy;

        cout << "Enter the X coordinate:" << endl;
        cin >> x;

        cout << "Enter the Y coordinate:" << endl;
        cin >> y;

        cout << "Enter Accuracy: \n"
                "\t0 - no \n"
                "\t1 - yes\n\n";
        int is_position;
        cin >> is_position;
        if (is_position == 1) {
            cout << "Positioning Accuracy:" << endl;
            cin >> accuracy;
            move_mission = make_unique<Move>(x, y, move_type, deep_type, accuracy);
            if (move_mission->Check()) {
                break;
            }
            std::cout << "The entered parameters are not correct, please enter again\n\n";
        }
        else {
            move_mission = make_unique<Move>(x, y, move_type, deep_type);
            if (move_mission->Check()) {
                break;
            }
            std::cout << "The entered parameters are not correct, please enter again\n\n";
        }
    }
    return move_mission;
}

unique_ptr<Mission> App::CreateReturnMission() { return make_unique<Return>(); }

void App::ShowMissions() {
    cout << "Choose one of the actions: \n"
            "\t0 - Show one mission \n"
            "\t1 - Show all missions \n"
            "\t2 - Show deleted missions \n";
    int act;
    cin >> act;
    if (act == 0) {
        std::cout << "Enter id mission: ";
        int id;
        cin >> id;
        _pool.ShowMission(id);
    } else if (act == 1) {
        _pool.ShowAllMissions();
    } else if (act == 2) {
        _pool.ShowDeletedMissions();
    }
}

void App::DeleteMission() {
    cout << "View all missions: \n"
            "\t0 - no \n"
            "\t1 - yes\n\n";
    int is_show_mission;
    cin >> is_show_mission;
    if (is_show_mission == 1) {
        _pool.ShowAllMissions();
    }

    cout << "Enter the id of the mission you want to delete: ";
    unsigned int id;
    while (true) {
        cin >> id;
        if (_pool.RemoveMission(id)) {
            break;
        }
        cout << "Invalid id entered, enter again: ";
    }
}

void App::ChangeMission() {
    cout << "View all missions: \n"
            "\t0 - no \n"
            "\t1 - yes\n\n";
    int is_show_mission;
    cin >> is_show_mission;
    if (is_show_mission == 1) {
        _pool.ShowAllMissions();
    }

    cout << "Enter the id of the mission you want to change: ";
    unsigned int id;
    cin >> id;
    auto new_mission = CreateNewMission();
    while (!_pool.ChangeMission(id, move(new_mission))) {
        cout << "You entered a wrong id, enter again: ";
        cin >> id;
    }
}

void App::SwapMissions() {
    cout << "View all missions: \n"
            "\t0 - no \n"
            "\t1 - yes\n\n";
    int is_show_mission;
    cin >> is_show_mission;
    if (is_show_mission == 1) {
        _pool.ShowAllMissions();
    }

    cout << "Enter the 2 id of the missions you want to rearrange: ";
    unsigned int id_l;
    unsigned int id_r;
    while (true) {
        cin >> id_l >> id_r;
        if (_pool.SwapMissions(id_l, id_r)) {
            break;
        }
        cout << "Invalid id entered, enter again: ";
    }
}

void App::RepairMission() {
    cout << "View all deleted missions: \n"
            "\t0 - no \n"
            "\t1 - yes \n\n";
    int is_show_mission;
    cin >> is_show_mission;
    if (is_show_mission == 1) {
        _pool.ShowDeletedMissions();
    }

    while (true) {
        cout << "Enter the id of the missions you want to restore: ";
        unsigned int deleted_id;
        cin >> deleted_id;
        cout << "Enter the id where to insert: ";
        unsigned int insert_id;
        cin >> insert_id;
        if (_pool.RepairRemovedMission(deleted_id, insert_id)) {
            break;
        }
        cout << "You entered a wrong id, enter it again\n";
    }
}

bool App::Stop() {
    if (_pool.IsLastMissionIsReturn()) {
        return true;
    }
    cout << "The last mission should be Return. Do you want to add it \n"
            "\t0 - no (continue) \n"
            "\t1 - yes (program termination)\n";
    int finish;
    cin >> finish;
    if (finish == 0) {
        return false;
    }
    _pool.InsertNewMission(make_unique<Return>());
    return true;
}

