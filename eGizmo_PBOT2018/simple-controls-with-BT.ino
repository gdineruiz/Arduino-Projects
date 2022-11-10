#include "eGizmo_PBOT2018.h"
#include <Wire.h>

eGizmo_PBOT2018 PBOT;

int FULL_SPEED = 150;
int NORMAL_SPEED = 75;
int FULL_STOP = 0;
char t;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  PBOT.BEGIN();
  stopBot();
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
  if (t == 'u' || t == 'y') {
    forward();
  }
  else if (t == 'd') {
    backward();
  }
  else if (t == 'r') {
    turnRight();
  }
  else if (t == 'l') {
    turnLeft();
  }
  else if (t == 'x') {
    stopBot();
  }
}

void forward() {
  PBOT.DIRECTION(MOTOR_BOTH, MOTOR_FWD);
  PBOT.SPEED(MOTOR_BOTH, FULL_SPEED);
}

void backward() {
  PBOT.DIRECTION(MOTOR_BOTH, MOTOR_REV);
  PBOT.SPEED(MOTOR_BOTH, FULL_SPEED);
}

void turnRight() {
  PBOT.DIRECTION(MOTOR_A, MOTOR_FWD);
  PBOT.DIRECTION(MOTOR_B, MOTOR_REV);
  PBOT.SPEED(MOTOR_BOTH, NORMAL_SPEED);
}

void turnLeft() {
  PBOT.DIRECTION(MOTOR_B, MOTOR_FWD);
  PBOT.DIRECTION(MOTOR_A, MOTOR_REV);
  PBOT.SPEED(MOTOR_BOTH, NORMAL_SPEED);
}

void stopBot() {
  PBOT.SPEED(MOTOR_BOTH, FULL_STOP);
}
