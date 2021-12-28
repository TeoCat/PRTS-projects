#pragma once

#include "Mission.h"

class Lift : public Mission {
public:
    enum LiftSensorType { DepthSensor = 0, Echo };

    enum LiftMoveType { Spiral = 0, VerticalMove };

public:
    Lift() = delete;
    Lift(LiftSensorType s_type, unsigned int depth, LiftMoveType d_type);
    ~Lift() override = default;

    bool Check() override;

    string Stringify() override;

private:
    LiftSensorType _s_type;
    unsigned int _depth;
    LiftMoveType _d_type;
};
