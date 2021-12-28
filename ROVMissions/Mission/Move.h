#pragma once

#include "Mission.h"

class Move : public Mission {
public:
    enum MoveType { Point = 0, Line };

    enum DeepMoveType { ConstDepth = 0, ConstDistanceToBottom };

public:
    Move() = delete;
    Move(unsigned int x, unsigned int y, MoveType m_type, DeepMoveType d_m_type, unsigned int accuracy = 100);
    ~Move() override = default;

    bool Check() override;

    string Stringify() override;

private:
    unsigned int _x;
    unsigned int _y;
    MoveType _m_type;
    DeepMoveType _d_m_type;
    unsigned int _accuracy;
};

