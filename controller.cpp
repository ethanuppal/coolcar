// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "controller.h"

void Controller::run() {
    if (requested_percent > 0
        && micros() - last_continuous_drive > Controller::STOP_DELAY) {
        // run full speed 20ms
    } else {
        // when you stop requesting speed from motors, start waiting
        if (is_driving && requested_percent == 0) {
            is_driving = false;
            last_continuous_drive = micros();
        } else {
        }
    }
}

void Controller::speed(float percent) {
    requested_percent = percent;
}
