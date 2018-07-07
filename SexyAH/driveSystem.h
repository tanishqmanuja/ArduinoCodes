#include <dcMotors.h>
#define motorRfPin 5
#define motorRbPin 6
#define motorLfPin 10
#define motorLbPin 9
dcMotors motor(motorRfPin, motorRbPin, motorLfPin, motorLbPin);

//Drive Control
#define right_basespeed 165
#define left_basespeed 160
#define right_maxspeed 255
#define left_maxspeed 250
float right_speed = 165;
float left_speed = 160;

//Angular Control
#define angular_rspeed 120
#define angular_lspeed 120
#define delay90 1123

