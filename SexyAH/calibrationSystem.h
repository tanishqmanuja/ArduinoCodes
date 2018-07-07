void manualSensorCalibrate(unsigned int ctime) {
  Serial.println();
  Serial.println("Calibrating...");
  for (int i = 0; i < ctime; i++) {
    for (int j = 0; j < 5; j++) {
      int sensorValue = analogRead(sensorPins[j]);
      if (sensorValue > maxSensorValues[j]) {
        maxSensorValues[j] = sensorValue;
      }
      if (sensorValue < minSensorValues[j]) {
        minSensorValues[j] = sensorValue;
      }
    }
    delay(1);
  }
  for (int i = 0; i < 5; i++) {
    avgSensorValues[i] = (minSensorValues[i] + maxSensorValues[i]) / 2;
  }
}

bool once = 0;
unsigned long startTime = 0;
unsigned long currentTime = 0;
bool autoSensorCalibrate(unsigned int ctime) {
  if (once == 0) {
    startTime = millis();
    once = 1;
    Serial.println("autoCalibration Started....");
  }
  else {
    currentTime = millis();
    if ((currentTime - startTime) < ctime) {
      motor.turnleft(200, 200);
      for (int i = 0; i < 5; i++) {
        int sensorValue = analogRead(sensorPins[i]);
        if (sensorValue > maxSensorValues[i]) {
          maxSensorValues[i] = sensorValue;
        }
        if (sensorValue < minSensorValues[i]) {
          minSensorValues[i] = sensorValue;
        }
      }
    }
    else {
      for (int i = 0; i < 5; i++) {
        avgSensorValues[i] = (minSensorValues[i] + maxSensorValues[i]) / 2;
      }
      sensorUpdate();
      if (sensorState != B000) {
        return 1;
      }
      else if (millis() - startTime < 3 * ctime) {
        //do nothing
      }
      else {
        motor.stop();
        return 1;
      }
    }
  }
  return 0;
}

void calibration() {
  digitalWrite(ledPin, HIGH);

  //Calibration Start
  if (calib_mode == "m") {
    manualSensorCalibrate(5000);
  }
  else if (calib_mode == "a") {
    while (!autoSensorCalibrate(9400)) {}
  }
  //Calibration End

  digitalWrite(ledPin, LOW);

  //Average Sensor Values
  if (print_avg == true) {
    Serial.print(">>");
    for (int i = 0; i < 5 ; i++ ) {
      Serial.print(avgSensorValues[i]);
    }
    Serial.println("<<");
  }
}
