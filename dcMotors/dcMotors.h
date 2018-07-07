//Author : Tanishq Manuja
//Date Created : March 2 2018

#ifndef dcMotors_h
#define dcMotors_h

#include "arduino.h"

class dcMotors{
	public:
		dcMotors(int pinRF,int pinRB,int pinLF,int pinLB);
		void set(int lspeed,int rspeed);
		void forward(int rspeed,int lspeed);
		void backward(int rspeed,int lspeed);
		void turnleft(int rspeed,int lspeed);
		void turnright(int rspeed,int lspeed);
		void stop();
		
	private:
		int motorRfPin ;
		int motorRbPin ;
		int motorLfPin ;
		int motorLbPin ;
};

#endif