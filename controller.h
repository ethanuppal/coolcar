// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#pragma once

#include "base.h"
#include "motor.h"

class Controller {
    enum class State {
        IDLE,     ///< Stop the car.
        DRIVING,  ///< Move the car at a specified speed.
        OVERCOME  ///< Need to overcome static friction by quickly driving at
                  ///< full speed.
    };

    /** Millisecond delay after being stationary when a boost is needed to
     * overcome static friction. */
    const static int STOP_DELAY = 100;

    bool is_driving;

    /** Time since the motor was continuously driven, i.e., time since the robot
     * has stopped moving. Will *not* be updated when `Controller::is_driving`
     * is `true`. */
    int last_continuous_drive = -STOP_DELAY;

    /** The requested percentage of full speed for the motor. Not all possible
     * percents can be realized. */
    float requested_percent;

public:
    void run();

    /** `percent` must be inclusively between `0` and `1`. */
    void speed(float percent);
};
