#include "Move.h"

#include <sstream>

Move::Move(unsigned int x, unsigned int y, Move::MoveType m_type, Move::DeepMoveType d_m_type, unsigned int accuracy)
        : _x(x), _y(y), _m_type(m_type), _d_m_type(d_m_type), _accuracy(accuracy) {
    Mission::TYPE = MissionType::MOVE;
}

bool Move::Check() {
    static const unsigned int MaxX = 10000;
    static const unsigned int MinX = 0;
    static const unsigned int MaxY = 10000;
    static const unsigned int MinY = 0;
    return (MinX <= _x && _x <= MaxX) && (MinY <= _y && _y <= MaxY);
}

string Move::Stringify() {
    stringstream result;
    result << "Move Mission:\n";
    switch (_m_type) {
        case Point:
            result << "\tExit to the point\n";
            break;
        case Line:
            result << "\tMovement along a straight line\n";
            break;
    }
    switch (_d_m_type) {
        case ConstDepth:
            result << "\tDiving at constant depth\n";
            break;
        case ConstDistanceToBottom:
            result << "\tMovement at a constant distance from the bottom\n";
            break;
    }

    result << "\tExit to the point: \n";
    result << "\t\tx = " << _x << ";\n";
    result << "\t\ty = " << _y << ";\n";
    result << "\tWith precision - " << _accuracy << "\n";

    return result.str();
}

