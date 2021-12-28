#include "Return.h"

bool Return::Check() { return true; }

string Return::Stringify() {
    static const string result = "Return Mission:\n"
                                      "\tMoving to the starting position:\n"
                                      "\t\tx = 0\n"
                                      "\t\ty = 0\n";
    return result;
}

Return::Return() {
    Mission::TYPE = MissionType::RETURN;
}

