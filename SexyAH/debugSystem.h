/*------------------------------------DEBUGGING PANEL-------------------------------------*/
#define debug_mode false
#define motor_balance false
#define rotation_balance false
#define serial_comm false
#define print_ss false
#define print_avg false
#define calib_mode "a"
/*----------------------------------------------------------------------------------------*/


void debug() {
  while (true) {
    if (print_ss == true) {
      sensorUpdate();
      Serial.print(">>  ");
      Serial.print(sensorValues[0]);
      Serial.print(sensorValues[1]);
      Serial.print(sensorValues[2]);
      Serial.print(sensorValues[3]);
      Serial.print(sensorValues[4]);
      Serial.println("  <<");
    }
    if (motor_balance == true) {
      motor.forward(right_basespeed, left_basespeed);
    }
    else if (rotation_balance == true) {
      motor.set(angular_rspeed, -angular_lspeed);
      delay(delay90);
      motor.stop();
      delay(delay90 * 2);
    }
  }
}

