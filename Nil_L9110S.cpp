// file     Nil_L9110S.cpp v0.1
// by nil (nil.baltimore@gmail.com)
// provide some useful function make it easy to control car with DC motors use L9110s
// Copyright (c) 2017 Nil Baltimore
// MIT License


#include <Arduino.h>
#include "Nil_L9110S.h"

Nil_L9110S::Nil_L9110S(uint8_t pinLeftSpeed, uint8_t pinLeftDir, uint8_t pinRightSpeed, uint8_t pinRightDir) {
	
	_pinLeftSpeed = pinLeftSpeed;
	_pinLeftDir = pinLeftDir;
	_pinRightSpeed = pinRightSpeed;
	_pinRightDir = pinRightDir;

	pinMode (_pinLeftSpeed, OUTPUT);
	pinMode (_pinLeftDir, OUTPUT);
	pinMode (_pinRightSpeed, OUTPUT);
	pinMode (_pinRightDir, OUTPUT);

	//initial FORWARD 
	_leftDir = Direction::FORWARD;
	_rightDir = Direction::FORWARD;
	
}

void Nil_L9110S::brake () {
	
	digitalWrite( _pinLeftSpeed, LOW );
    digitalWrite( _pinLeftDir, LOW );

    digitalWrite( _pinRightSpeed, LOW );
    digitalWrite( _pinRightDir, LOW );

}


void Nil_L9110S::control (uint8_t leftSpeed, uint8_t rightSpeed) {
	brake();

	if (_leftDir == Direction::FORWARD) {
		digitalWrite( _pinLeftDir, HIGH );
		analogWrite(_pinLeftSpeed, 255-leftSpeed); // PWM speed
	}
	else {
		digitalWrite( _pinLeftDir, LOW );
		analogWrite(_pinLeftSpeed, leftSpeed); // PWM speed
	}
	

	if (_rightDir == Direction::FORWARD) {
		digitalWrite( _pinRightDir, HIGH );
		analogWrite(_pinRightSpeed, 255-rightSpeed); // PWM speed
	}
	else {
		digitalWrite( _pinRightDir, LOW );
		analogWrite(_pinRightSpeed, rightSpeed); // PWM speed
	}
	
}

void Nil_L9110S::changeDir(Direction leftDir, Direction rightDir) {
	brake();

	_leftDir = leftDir;
	_rightDir = rightDir;
}






