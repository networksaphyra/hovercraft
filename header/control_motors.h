#include <Servo.h>

Servo BM1, BM2, BM3;
Servo motors = {BM1, BM2, BM3};

const int MOTOR_NUMBER=3;
int motor_pins[]={9, 10, 11};

void configure_motors() {
  for (int motor=0; motor<MOTOR_NUMBER; ++motor) {
    motors[motor].attach(motor_pins[motor]);
  }
}

void trigger_motors(int speed) {
  for (int motor=0; motor<MOTOR_NUMBER; ++motor) {
    int mappedValue=map(speed, 0, 255, 1000, 2000);
    motors[motor].writeMicroseconds(mappedValue);
  }
}