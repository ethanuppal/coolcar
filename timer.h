// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#pragma once

#include "base.h"

class Timer {
    int ms;
    int last;

public:
    /** Constructs a new timer to schedule events at least every `ms`
     * milliseconds. */
    Timer(int ms);

    /** Changes the timer interval to `ms`. */
    void set_interval(int new_ms);

    /** Returns `true` once the timer is ready to be fired. If called, the timer
     * resets for the next firing. */
    bool fire();
};
