/*==============================LDR===============================*/
int sensorPins[5] = {A1, A2, A3, A4, A5};
int sensorValues[5] = {0, 0, 0, 0, 0};
int avgSensorValues[5] = {0, 0, 0, 0, 0};
int minSensorValues[5] = {1023, 1023, 1023, 1023, 1023};
int maxSensorValues[5] = {0, 0, 0, 0, 0};
int sensorState = B00100;


int colorDetect(int i) {
  int sensorValue = analogRead(sensorPins[i]);
  if (sensorValue > avgSensorValues[i]) {
    return BLACK;
  }
  else {
    return WHITE;
  }
}

void sensorUpdate() {
  for (int i = 0; i < 5; i++) {
    bitWrite(sensorState, i, colorDetect(i));
    sensorValues[i] = colorDetect(i);
  }
}

/*==========================UltraSonic============================*/
#include <Ultrasonic.h>
#define echoPin 3
#define trigPin 2


bool usPreState = 0;
Ultrasonic ultrasonic(trigPin, echoPin);

void usFunction(int min , int max) {
  if (ultrasonic.distanceRead() > min && ultrasonic.distanceRead() < max ) {
    motor.stop();
    usPreState = 1;
  }
  else {
    if (usPreState == 1) {
      motor.forward(right_basespeed, left_basespeed);
      delay(4);
      usPreState = 0;
    }
  }
}

