#pragma once
#ifndef ultraSonic_h
#define ultraSonic_h

#include "Arduino.h"

class ultraSonic {
public:
	ultraSonic(int signalPin);
	double calculateDistanceCM();
	//double calculateDistanceIN();
	long measure();
private:
	void setPin();
	int _pin;
};

#endif