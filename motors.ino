#include "motors.h"

void motors_init(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTORS[MOTOR_FORWARD], OUTPUT);
  pinMode(MOTORS[MOTOR_REVERSE], OUTPUT);
  pinMode(MOTOR_BUTTON_FORWARD, INPUT);
  pinMode(MOTOR_BUTTON_REVERSE, INPUT);
}
void motors_update(void) {
  if(digitalRead(MOTOR_BUTTON_FORWARD) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(MOTORS[MOTOR_FORWARD], HIGH);
    digitalWrite(MOTORS[MOTOR_REVERSE], LOW);

  } else if (digitalRead(MOTOR_BUTTON_REVERSE) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(MOTORS[MOTOR_FORWARD], LOW);
    digitalWrite(MOTORS[MOTOR_REVERSE], HIGH);

  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(MOTORS[MOTOR_FORWARD], LOW);
    digitalWrite(MOTORS[MOTOR_REVERSE], LOW);

  }
}