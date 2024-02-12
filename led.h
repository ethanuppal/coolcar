// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#pragma once

#include "component.h"

class Led : public Component {
    pin_t pin;
    bool state;

public:
    /** Constructs a new LED at the given pin. */
    Led(pin_t pin);

    void configure();

    /** Enables the LED light if `state` is `true`, and disables it otherwise.
     */
    void set(bool state);

    /** Whether the LED is on. */
    bool is_on() const;
};
