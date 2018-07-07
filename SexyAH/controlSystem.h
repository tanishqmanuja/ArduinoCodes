void botControl() {
  //EX-RIGHT
  if (sensorState == B00001) {
    motor.turnright(0, left_speed);
  }
  //EX-LEFT
  else if (sensorState == B10000) {
    motor.turnleft(right_speed, 0);
  }
  //ACUTE-RIGHT
  else if (sensorState == B00011) {
    motor.turnright(right_speed, left_speed);
  }
  //ACUTE-LEFT
  else if (sensorState == B11000) {
    motor.turnleft(right_speed, left_speed);
  }
  //T-POINT
  else if (sensorState == B01010) {
    motor.turnright(0, left_speed);
  }
  //PLUS-POINT
  else if (sensorState == B01110) {
    motor.forward(right_speed, left_speed);
  }
  //90-RIGHT
  else if (sensorState == B00010) {
    motor.turnright(0, left_speed);
  }
  //90-LEFT
  else if (sensorState == B01000) {
    motor.turnleft(right_speed, 0);
  }
  //CURVE-RIGHT
  else if (sensorState == B00111) {
    motor.turnright(right_speed, left_speed);
  }
  //CURVE-LEFT
  else if (sensorState == B11100) {
    motor.turnleft(right_speed, left_speed);
  }
  //90-RIGHT
  else if (sensorState == B00010) {
    motor.turnright(0, left_speed);
  }
  //STRAIGHT
  else if (sensorState == B00100) {
    motor.forward(right_speed, left_speed);
  }
  //UNKNOWN
//  else {
//    motor.forward(0.5 * right_basespeed, 0.5 * left_basespeed);
//  }
}
