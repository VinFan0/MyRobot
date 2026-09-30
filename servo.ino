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
        if(!bt_readings->oldData) {
          servo.write(SERVO_CENTER);
        }
        break;

      default: {
        // servo.write(SERVO_CENTER);
      }
    }
  }
}
