// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include "Arduino.h"
#include "base.h"
#include "motor.h"
#include "led.h"
#include "pullup_switch.h"
#include "timer.h"

#define LED_SCL_PIN 6
#define LED_SDA_PIN 7
#define LED_PIN 3
#define SWITCH_PIN 2

#define MOTOR_A_IN1_PIN 8
#define MOTOR_A_IN2_PIN 9
#define MOTOR_B_IN1_PIN 10
#define MOTOR_B_IN2_PIN 11

Timer blink_timer(500);
Timer motor_timer(20);
PullupSwitch pullup_switch(SWITCH_PIN);
Led flashing_led(LED_PIN);
Motor motor_left(MOTOR_A_IN1_PIN, MOTOR_A_IN2_PIN);
Motor motor_right(MOTOR_B_IN1_PIN, MOTOR_B_IN2_PIN);

bool motors_on = true;

void setup() {
    pinMode(LED_SCL_PIN, OUTPUT);
    pinMode(LED_SDA_PIN, OUTPUT);

    pullup_switch.configure();
    flashing_led.configure();
    motor_left.configure();
    motor_right.configure();

    // digitalWrite(LED_SCL_PIN, HIGH);
    // digitalWrite(LED_SDA_PIN, HIGH);

    Serial.begin(9600);
}

void loop() {
    if (blink_timer.fire()) {
        flashing_led.set(!flashing_led.is_on());
    }

    if (pullup_switch.is_on() && motors_on) {
        motor_left.set(Motor::State::FORWARD);
        motor_right.set(Motor::State::FORWARD);
    } else {
        motor_left.set(Motor::State::OFF);
        motor_right.set(Motor::State::OFF);
    }

    // if (motor_timer.fire()) {
    //     motors_on = !motors_on;
    // }
}
