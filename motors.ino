#include "motors.h"

void motors_init(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  
  for(int i=0; i<NUM_MOTORS;) {
    ledcAttach(MOTORS[i].forward_pin, MOTOR_PWM_FREQ, MOTOR_PWM_BITS);
    ledcAttach(MOTORS[i].reverse_pin, MOTOR_PWM_FREQ, MOTOR_PWM_BITS);
    motor_stop(i);
    i++;
  }
}

void motors_update(bt_commands_t *bt_readings) {

  // Max value from application is 99 + 60 = 159 (positive or negative)
  // Application min 39
  // Value is mapped to PWM range in motor_x functions

  switch(bt_readings->command) {
    case 'F': // Forward
      motor_forward(MOTOR_RIGHT_IDX, BT_COMM_MAX);
      motor_forward(MOTOR_LEFT_IDX, BT_COMM_MAX);
      break;

    case 'B': // Backward
      motor_reverse(MOTOR_RIGHT_IDX, BT_COMM_MAX);
      motor_reverse(MOTOR_LEFT_IDX, BT_COMM_MAX);
      break;

    case 'L': // Left
      motor_forward(MOTOR_RIGHT_IDX, BT_COMM_MAX);
      motor_reverse(MOTOR_LEFT_IDX, BT_COMM_MAX);
      break;

    case 'R': // Right
      motor_reverse(MOTOR_RIGHT_IDX, BT_COMM_MAX);
      motor_forward(MOTOR_LEFT_IDX, BT_COMM_MAX);
      break;

    case 'G': // Forward-Left
      motor_forward(MOTOR_RIGHT_IDX, BT_COMM_MAX);
      motor_forward(MOTOR_LEFT_IDX, BT_COMM_MIN);
      break;

    case 'H': // Forward-Right
      motor_forward(MOTOR_RIGHT_IDX, BT_COMM_MIN);
      motor_forward(MOTOR_LEFT_IDX, BT_COMM_MAX);
      break;

    case 'I': // Backward-Left
      motor_reverse(MOTOR_RIGHT_IDX, BT_COMM_MAX);
      motor_reverse(MOTOR_LEFT_IDX, BT_COMM_MIN);
      break;

    case 'J': // Backward-Right
      motor_reverse(MOTOR_RIGHT_IDX, BT_COMM_MIN);
      motor_reverse(MOTOR_LEFT_IDX, BT_COMM_MAX);
      break;

    case 'S': // Stop
      motor_stop(MOTOR_RIGHT_IDX);
      motor_stop(MOTOR_LEFT_IDX);
      break;

    default: 
      motor_stop(MOTOR_RIGHT_IDX);
      motor_stop(MOTOR_LEFT_IDX);
  }

  /*
  Right Motor
  ------------
  +Throttle(Forward)
    +Yaw(Right)
      Throttle - Yaw
    -Yaw(Left)
      Throttle - Yaw
    
    ** Throttle - Yaw**

  -Throttle(Reverse)
    +Yaw(Right)
      Throttle - Yaw
    -Yaw(Left)
      Throttle - Yaw

    ** Throttle - Yaw**

  **********************************
  +Throttle ---> Throttle - Yaw
  -Throttle ---> -(Throttle - Yaw)
  **********************************
  */

  /* Advanced BT Control
  float right_motor_command = abs(bt_readings->throttle_val) - bt_readings->yaw_val;

  // Serial.print("Right Motor Value: ");
  if (bt_readings->throttle_val > 0) { // +Throttle (Forward)
    motor_forward(MOTOR_RIGHT_IDX, right_motor_command);
    // Serial.print("Forward: ");

  } else if (bt_readings->throttle_val < 0) {  // -Throttle (Reverse)
    motor_reverse(MOTOR_RIGHT_IDX, right_motor_command);
    // Serial.print("Reverse: ");

  } else {  // 0 Throttle
    if (bt_readings->yaw_val > 0) { // +Yaw (Right)
      // Serial.print("Turn Right: ");
      motor_reverse(MOTOR_RIGHT_IDX, bt_readings->yaw_val);

    } else if (bt_readings->yaw_val < 0) { // -Yaw (Left)
      // Serial.print("Turn Left: ");
      motor_forward(MOTOR_RIGHT_IDX, abs(bt_readings->yaw_val));

    } else { // Motors Stop
      // Serial.print("Stop Motors");
      motor_stop(MOTOR_RIGHT_IDX);
    }
  }
  */

}

void motor_forward(int motor_idx, int speed) {
  speed = constrain(map(speed, 39, 159, MOTOR_PWM_MIN, MOTOR_PWM_MAX), MOTOR_PWM_MIN, MOTOR_PWM_MAX);
  Serial.print("Forward: ");
  Serial.println(speed);
  ledcWrite(MOTORS[motor_idx].reverse_pin, 0);
  ledcWrite(MOTORS[motor_idx].forward_pin, speed);
}

void motor_reverse(int motor_idx, int speed) {
  speed = constrain(map(speed, 39, 159, MOTOR_PWM_MIN, MOTOR_PWM_MAX), MOTOR_PWM_MIN, MOTOR_PWM_MAX);
  Serial.print("Reverse: ");
  Serial.println(speed);
  ledcWrite(MOTORS[motor_idx].forward_pin, 0);
  ledcWrite(MOTORS[motor_idx].reverse_pin, speed);
}

void motor_stop(int motor_idx) {
  ledcWrite(MOTORS[motor_idx].forward_pin, 0);
  ledcWrite(MOTORS[motor_idx].reverse_pin, 0);
}
