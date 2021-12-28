#include "Dive.h"

#include <sstream>

Dive::Dive(DiveSensorType s_type, unsigned int depth, DiveMoveType d_type)
        : _s_type(s_type), _depth(depth), _d_type(d_type) {
    Mission::TYPE = MissionType::DIVE;
}

bool Dive::Check() {
    static const unsigned int MaxDepth = 100;
    static const unsigned int MinDepth = 0;
    return MinDepth <= _depth && _depth <= MaxDepth;
}

string Dive::Stringify() {
    stringstream result;
    result << "Dive Mission:\n";
    switch (_s_type) {
        case DepthSensor:
            result << "\tSetting the depth using a depth sensor\n";
            result << "\tImmersion depth: " << _depth << "\n";
            break;
        case Echo:
            result << "\tDepth setting by echo sounder\n";
            result << "\tDistance: " << _depth << "\n";
            break;
    }

    switch (_d_type) {
        case Spiral:
            result << "\tSpiral dive\n";
            break;
        case VerticalMove:
            result << "\tDiving due to vertical prop\n";
            break;
    }
    return result.str();
}
