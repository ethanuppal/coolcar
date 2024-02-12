// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "timer.h"

Timer::Timer(int ms): last(0), ms(ms) {}

void Timer::set_interval(int new_ms) {
    this->ms = new_ms;
}

bool Timer::fire() {
    if (millis() - last > ms) {
        last = millis();
        return true;
    }
    return false;
}
