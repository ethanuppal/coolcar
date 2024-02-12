// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "led.h"

Led::Led(pin_t pin): state(false), pin(pin) {}

void Led::configure() {
    pinMode(pin, OUTPUT);
}

void Led::set(bool state) {
    this->state = state;
    digitalWrite(pin, state ? HIGH : LOW);
}

bool Led::is_on() const {
    return state;
}
