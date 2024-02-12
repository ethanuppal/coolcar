// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#pragma once

#include "component.h"

class PullupSwitch : public Component {
    pin_t pin;

public:
    PullupSwitch(pin_t pin);

    void configure();

    bool is_on() const;
};
