//PWM Pins : 3,5,6,9,10,11

#include <PS2X_lib.h>
#include <dcMotors.h>

PS2X ps2x;

//dcMotor(Rf,Rb,Lf,Lb)
dcMotors motor(10, 9, 5, 6);

int maxspeed = 256;

void changespeed() {
  if (maxspeed > 128)
    maxspeed = 128;
  else
    maxspeed = 256;
}

int error = 0;
byte type = 0;
byte vibrate = 0;

#define CLK 11
#define CMD 3
#define ATT 8
#define DAT 7 //pullup

void setup() {
  Serial.begin(9600);

  //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?)
  error = ps2x.config_gamepad(CLK, CMD, ATT, DAT, false, false);

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug.");

  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }
}

void loop() {
  ps2x.read_gamepad();

  //Select to select speed
  if (ps2x.ButtonPressed(PSB_SELECT)) {
    changespeed();
  }

  //Cross to move Forward
  if (ps2x.Button(PSB_BLUE)) {
    motor.set(maxspeed, maxspeed);
    delay(10);
  }

  //Square to move Backward
  if (ps2x.Button(PSB_PINK)) {
    motor.set(-maxspeed, -maxspeed);
    delay(10);
  }

  //D-PAD for direction
  if (ps2x.Button(PSB_PAD_UP)) {
    motor.set(maxspeed, maxspeed);
    delay(10);
  }
  if (ps2x.Button(PSB_PAD_DOWN)) {
    motor.set(-maxspeed, -maxspeed);
    delay(10);
  }
  if (ps2x.Button(PSB_PAD_LEFT)) {
    motor.set(0, maxspeed);
    delay(10);
  }
  if (ps2x.Button(PSB_PAD_RIGHT)) {
    motor.set(maxspeed, 0);
    delay(10);
  }

  //L1 for 360 left
  if (ps2x.Button(PSB_L1)) {
    motor.set(-maxspeed, maxspeed);
    delay(10);
  }

  //R1 for 360 right
  if (ps2x.Button(PSB_R1)) {
    motor.set(maxspeed, -maxspeed);
    delay(10);
  }

  //Else
  else {
    motor.stop();
  }
}
