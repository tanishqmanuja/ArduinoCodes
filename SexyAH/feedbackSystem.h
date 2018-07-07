/*------------------------------------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PID Speed Control System >>>>>>>>>>>>>>>>>>>>>>>>>>>>>-------------------------------------*/
float pidPercentage = 70;
float Kp = 4;
float Kd = 1;

int presensorState = B00100;

void pidUpdate() {
  float correction = Kp * (sensorState - B00100) ;
  if (correction < 0) {
    left_speed = constrain(left_basespeed + (int)((pidPercentage / 100) * ( abs(correction) - Kd * (sensorState - presensorState))), left_basespeed, left_maxspeed);
  }
  else if (correction > 0) {
    right_speed = constrain(right_basespeed + (int)((pidPercentage / 100) * ( abs(correction) + Kd * (sensorState - presensorState))), right_basespeed, right_maxspeed);
  }
  presensorState = sensorState;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< White Detection System >>>>>>>>>>>>>>>>>>>>>>>>>>>>>-------------------------------------*/
int whiteTimeLimit = 3000;
int whiteStartTime = 0;
bool onWhite = false;
bool backtrack = false;

void checkWhite() {
  if(onWhite == false && backtrack == false && presensorState==B00000 && sensorState==B00000){
    whiteStartTime = millis();
    onWhite = true;
  }
  else if(sensorState!=B00000){
    onWhite = false;
  }
  else if(onWhite == true && backtrack == false && presensorState==B00000 && sensorState==B00000 && millis()-whiteStartTime>whiteTimeLimit){
    //180degree turn
    motor.set(angular_rspeed, -angular_lspeed);
    delay(2 * delay90);
    motor.stop();
    //move forward
    motor.forward(right_speed, left_speed);
    delay(10);
    //backtrack
    backtrack=true;
  }
}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
      
