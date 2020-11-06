#pragma once
#ifndef lineFollower_h
#define lineFollower_h

#include "Arduino.h"

class lineFollower {
public:
	lineFollower(int pin1, int pin2);
	int readSensors();
	bool readSensor1();
	bool readSensor2();
private:
	
	void setPin();
	int _pin1;
	int _pin2;
};

#endif