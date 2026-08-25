#ifndef SERVO_H
#define SERVO_H

#include <ESP32Servo.h>

#define SERVO_PIN 4
#define SERVO_UPDATE_FREQ_MS 100
#define SERVO_TURN_LEFT 130
#define SERVO_TURN_RIGHT 50
#define SERVO_CENTER 90

Servo servo;
uint32_t servoLastStep = 0;
uint8_t servoState = 0b00;

void servo_init(void);
void servo_update(bt_commands_t *bt_readings);

#endif // SERVO_H