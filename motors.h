#ifndef MOTORS_H
#define MOTORS_H

#define MOTOR_FORWARD 0
#define MOTOR_REVERSE 1
#define MOTOR_BUTTON_FORWARD 34
#define MOTOR_BUTTON_REVERSE 35

const uint8_t MOTORS[] = {32, 33};

void motors_init(void);
void motors_update(void);

#endif // MOTORS_H