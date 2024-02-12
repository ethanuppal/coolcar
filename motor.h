// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#pragma once

#include "component.h"

class Motor : public Component {
public:
    /** The direction that the motor is spinning in with reference to my
     * vehicle. */
    enum class State { FORWARD, BACKWARD, OFF };

private:
    /** IN1 pin for the motor driver. */
    pin_t in1;

    /** IN2 pin for the motor driver. */
    pin_t in2;

public:
    /** Constructs a new motor with control pins `in1` and `in2`. */
    Motor(pin_t in1, pin_t in2);

    void configure();

    /** Places the motor in the given `state`. */
    void set(State state);
};
