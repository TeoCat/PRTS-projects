#pragma once

#include "Mission.h"

class Return : public Mission {
public:
    Return();
    ~Return() override = default;

    bool Check() override;

    string Stringify() override;
};

