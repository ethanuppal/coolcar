// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#pragma once

#include "base.h"

/** A generic Arduino component. */
class Component {
public:
    /** Initialization routine for this component. */
    virtual void configure() = 0;
};
