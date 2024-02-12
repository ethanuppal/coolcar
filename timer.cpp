// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "timer.h"

Timer::Timer(int ms): last(0), ms(ms) {}

bool Timer::fire() {
    if (millis() - last > ms) {
        last = millis();
        return true;
    }
    return false;
}
