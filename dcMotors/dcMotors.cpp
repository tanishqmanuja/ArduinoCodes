//Author : Tanishq Manuja
//Date Created : March 2 2018

#include "arduino.h"
#include "dcMotors.h"

dcMotors :: dcMotors(int pinRF,int pinRB,int pinLF,int pinLB){
	pinMode(pinRF,OUTPUT);
	pinMode(pinRB,OUTPUT);
	pinMode(pinLF,OUTPUT);
	pinMode(pinLB,OUTPUT);
	
	motorRfPin = pinRF;
	motorRbPin = pinRB;
	motorLfPin = pinLF;
	motorLbPin = pinLB;
}

void dcMotors :: set(int lspeed,int rspeed){
	lspeed=constrain(lspeed,-255,255);
	rspeed=constrain(rspeed,-255,255);
	if(rspeed>0 && lspeed>0){
		analogWrite(motorRfPin,rspeed);
		analogWrite(motorRbPin,0);
		analogWrite(motorLfPin,lspeed);
		analogWrite(motorLbPin,0);
	}
	if(rspeed<0 && lspeed<0){
		analogWrite(motorRfPin,0);
		analogWrite(motorRbPin,abs(rspeed));
		analogWrite(motorLfPin,0);
		analogWrite(motorLbPin,abs(lspeed));
	}
	if(rspeed>0 && lspeed<=0){
		analogWrite(motorRfPin,rspeed);
		analogWrite(motorRbPin,0);
		analogWrite(motorLfPin,0);
		analogWrite(motorLbPin,abs(lspeed));  
	}
	if(rspeed<=0 && lspeed>0){
		analogWrite(motorRfPin,0);
		analogWrite(motorRbPin,abs(rspeed));
		analogWrite(motorLfPin,lspeed);
		analogWrite(motorLbPin,0); 
	}
	if(rspeed==0 && lspeed==0){
		analogWrite(motorRfPin,0);
		analogWrite(motorRbPin,0);
		analogWrite(motorLfPin,0);
		analogWrite(motorLbPin,0); 
	}
}

void dcMotors :: forward(int rspeed,int lspeed){
	analogWrite(motorRfPin,rspeed);
	analogWrite(motorRbPin,0);
	analogWrite(motorLfPin,lspeed);
	analogWrite(motorLbPin,0);  
}

void dcMotors :: backward(int rspeed,int lspeed){
	analogWrite(motorRfPin,0);
	analogWrite(motorRbPin,rspeed);
	analogWrite(motorLfPin,0);
	analogWrite(motorLbPin,lspeed);  
}

void dcMotors :: turnright(int rspeed,int lspeed){
	analogWrite(motorRfPin,0);
	analogWrite(motorRbPin,rspeed);
	analogWrite(motorLfPin,lspeed);
	analogWrite(motorLbPin,0);  
}

void dcMotors :: turnleft(int rspeed,int lspeed){
	analogWrite(motorRfPin,rspeed);
	analogWrite(motorRbPin,0);
	analogWrite(motorLfPin,0);
	analogWrite(motorLbPin,lspeed);  
}

void dcMotors :: stop(){
	analogWrite(motorRfPin,0);
	analogWrite(motorRbPin,0);
	analogWrite(motorLfPin,0);
	analogWrite(motorLbPin,0);  
}