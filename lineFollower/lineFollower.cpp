#include "Arduino.h"
#include "lineFollower.h"
#include "stdint.h"

lineFollower::lineFollower(int pin1, int pin2) {
	this->_pin1 = pin1;
	this->_pin2 = pin2;
	this->setPin();
}

/*
0x00: Both S1, S2 inside the black
0x01: S1 inside black, S2 outside black
0x02: S1 outside black, S2 inside black
0x03: Both S1, S2 outside the black
*/
uint8_t lineFollower::readSensors() {
	uint8_t state = S1_IN_S2_IN;
	bool s1State = readSensor1();
	bool s2State = readSensor2();
	state = ((1 & s1State) << 1) | s2State;
	return(state);
}

/* get current state of sensor1
 * return 0 if the sensor is inside the black (line)
 * return 1 if the sensor is outside the black (line)
*/
bool lineFollower::readSensor1() {
	return digitalRead(this->_pin1);
}

bool lineFollower::readSensor2() {
	return digitalRead(this->_pin2);
}

void lineFollower::setPin() {
	pinMode(this->_pin1, INPUT);
	pinMode(this->_pin2, INPUT);
}