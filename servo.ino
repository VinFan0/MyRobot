#include "servo.h"

void servo_init(void) {
  servo.attach(SERVO_PIN);
}

void servo_update(void) {
  if(millis() - servoLastStep > SERVO_UPDATE_FREQ_MS) {
    servoLastStep = millis();
    switch (servoState) {
      case 0b00:
        servo.write(0);
        break;

      case 0b01:
        servo.write(90);
        break;

      case 0b10:
        servo.write(180);
        break;

      default:
        servo.write(0);
        break;
    }
    if(servoState >= 2)
      servoState = 0;
    else
      servoState++;
  }
}