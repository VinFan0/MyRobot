#include "servo.h"

void servo_init(void) {
  servo.attach(SERVO_PIN);
}

void servo_update(bt_commands_t *bt_readings) {
  if(millis() - servoLastStep > SERVO_UPDATE_FREQ_MS) {
    servoLastStep = millis();
    switch(bt_readings->command) {
      case 'L': // Left
        servo.write(SERVO_TURN_LEFT);
        break;

      case 'R': // Right
        servo.write(SERVO_TURN_RIGHT);
        break;

      case 'G': // Forward-Left
        servo.write(SERVO_TURN_LEFT);
        break;

      case 'H': // Forward-Right
        servo.write(SERVO_TURN_RIGHT);
        break;  

      case 'I': // Backward-Left
        servo.write(SERVO_TURN_LEFT);
        break;

      case 'J': // Backward-Right
        servo.write(SERVO_TURN_RIGHT);
        break;

      case 'S': // Stop
        servo.write(SERVO_CENTER);
        break;

      default: 
        servo.write(SERVO_CENTER);
    }

    /* TEST Servo Code
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
    */
  }
}