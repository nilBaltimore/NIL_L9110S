// file     Nil_L9110S.h v0.1
// by nil (nil.baltimore@gmail.com)
// provide some useful function make it easy to control car with DC motors use L9110s
// Copyright (c) 2017 Nil Baltimore
// MIT License

#ifndef NIL_L9110S_H 
#define NIL_L9110S_H 

#include <Arduino.h>

enum class Direction : bool
{
	FORWARD = true,
	REVERSE = false
};

class Nil_L9110S {
	private:
		uint8_t _pinLeftSpeed; //PWM A_1A
		uint8_t _pinLeftDir; //DIR A_1B --> true = FORWARD
		uint8_t _pinRightSpeed; //PWM B_1A
		uint8_t _pinRightDir; //DIR B_1B --> true = FORWARD

		Direction _leftDir; //true = fordward
		Direction _rightDir; //true = fordward

		
	public:
		Nil_L9110S(uint8_t pinLeftSpeed, uint8_t pinLeftDir, 
			uint8_t pinRightSpeed, uint8_t pinRigthDir);
		
		void control(uint8_t leftSpeed, uint8_t rightSpeed); 
		void changeDir(Direction leftDir, Direction rightDir);
		void brake ();

		
};

#endif
