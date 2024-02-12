// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "motor.h"

Motor::Motor(pin_t in1, pin_t in2): in1(in1), in2(in2) {}

void Motor::configure() {
    // we want to write to both of these pins
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
}

void Motor::set(State state) {
    // the LOW, HIGH configuration was determined via testing
    // they are also dependent on how the physical vehicle is assembled
    switch (state) {
        case State::FORWARD: {
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            break;
        }
        case State::BACKWARD: {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            break;
        }
        case State::OFF: {
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            break;
        }
    }
}
