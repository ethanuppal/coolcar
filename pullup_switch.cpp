// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "pullup_switch.h"

PullupSwitch::PullupSwitch(pin_t pin): pin(pin) {}

void PullupSwitch::configure() {
    pinMode(pin, INPUT_PULLUP);
}

bool PullupSwitch::is_on() const {
    return digitalRead(pin) == HIGH;
}
