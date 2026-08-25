#ifndef MOTORS_H
#define MOTORS_H

#include "bluetooth.h"

#define NUM_MOTORS 2
#define MOTOR_RIGHT_IDX 0
#define MOTOR_LEFT_IDX 1

#define MOTOR_PWM_FREQ    5000 // 5 KHz
#define MOTOR_PWM_BITS    8    // 0-127
#define MOTOR_PWM_MAX     250
#define MOTOR_PWM_MIN     190
#define BT_COMM_MAX       159
#define BT_COMM_MIN       39

typedef struct motor_s{
  const int forward_pin = NULL;
  const int reverse_pin = NULL;
} motor_t;

motor_t MOTORS[] = {
  {33,32}, // Right Motor Forward 33, Reverse 32
  {25,26}  // Left Motor Forward 26, Reverse 25
};

typedef struct motor_commands_s{
  char command;  
} motor_commands_t;

motor_commands_t motor_commands;

void motors_init(void);
void motors_update(bt_commands_t *bt_readings);
void motor_forward(int motor_idx, int speed);
void motor_reverse(int motor_idx, int speed);
void motor_stop(int motor_idx);

#endif // MOTORS_H
