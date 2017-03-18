// file     Nil_L9110S_Demo.ino v0.1
// by nil (nil.baltimore@gmail.com)
// provide some useful function make it easy to control car with DC motors use L9110s
// Copyright (c) 2017 Nil Baltimore
// MIT License

#include <Nil_L9110S.h>

// pin = leftSpeed (PWM), leftDir, rightSpeed (PWM), rightDir
Nil_L9110S motor (11,12,10,8);


void setup () {
	Serial.begin(9600);
	delay (5000); 
	Serial.println("start");
	
}

void loop () {
	Serial.println("TURN RIGHT 150,150");
	motor.changeDir(Direction::FORWARD, Direction::REVERSE);
	motor.control(150,150);
	delay (8000);
	motor.brake();
	delay (3000);
	Serial.println("TURN LEFT 150,150");
	motor.changeDir(Direction::REVERSE, Direction::FORWARD);
	motor.control(150,150);
	delay (8000);
	motor.brake();
	delay (3000);
	Serial.println("GO 200,200");
	motor.changeDir(Direction::FORWARD, Direction::FORWARD);
	motor.control(200,200);
	delay (8000);
	motor.brake();
	delay (3000);
	Serial.println("REVERSE 150,150");
	motor.changeDir(Direction::REVERSE, Direction::REVERSE);
	motor.control(150,150);
	delay (8000);
	motor.brake();
	delay (3000);
}

