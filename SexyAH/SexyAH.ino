/*----------------------------< 5 Sensor LFR >--------------------------*/
/*==========================<  TanishqManuja  >=========================*/

//PWM Pins --> 3,5,6,9,10,11

//LED
#define ledPin 13

//Other Definitions
#define WHITE 0
#define BLACK 1

//Include Systems
#include "driveSystem.h"
#include "sensorSystem.h"
#include "debugSystem.h"
#include "calibrationSystem.h"
#include "controlSystem.h"
#include "feedbackSystem.h"


void setup() {
  //Serial Communication
  if (serial_comm == true)
    Serial.begin(9600);
  //LED SETUP
  pinMode(ledPin, OUTPUT);
  //LDR SETUP
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  calibration();
}

void loop() {
  if (debug_mode == true)
    debug();

  sensorUpdate();
  checkWhite();
  pidUpdate();
  botControl();
  //usFunction(2, 15);
}
