#pragma once

#include "Mission.h"

class Dive : public Mission {
public:
    enum DiveSensorType : int { DepthSensor = 0, Echo };

    enum DiveMoveType : int { Spiral = 0, VerticalMove };

public:
    Dive() = delete;
    Dive(DiveSensorType s_type, unsigned int depth, DiveMoveType d_type);
    ~Dive() override = default;

    bool Check() override;

    string Stringify() override;

private:
    DiveSensorType _s_type;
    unsigned int _depth;
    DiveMoveType _d_type;
};

