#pragma once

#include <string>
using namespace std;

enum class MissionType { DIVE = 0, LIFT, MOVE, RETURN, UNDEFINED };

class Mission {
public:
    MissionType TYPE = MissionType::UNDEFINED;

    virtual ~Mission() = default;

    virtual bool Check() = 0;

    virtual string Stringify() = 0;
};

