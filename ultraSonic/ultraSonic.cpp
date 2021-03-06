#include "Arduino.h"
#include "ultraSonic.h"

ultraSonic::ultraSonic(int signalPin) {
	this->_pin = signalPin;
	this->setPin();
}

double ultraSonic::calculateDistanceCM() {
	/*
	long microS = this->measure();

	return 340 * microS / 2; // Provided that the transmission speed of a sonic wave in the air is 340m/s.
	*/
	long distance = measure();

	if ((((double)distance / 58.0) >= 400.0) || (distance == 0)) {
		return ((double)400.0);
	}
	else {
		return ((double)distance / 58.0);
	}
}

/*
double ultraSonic::calculateDistanceIN() {

}
*/

long ultraSonic::measure() {
	digitalWrite(this->_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(this->_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(this->_pin, LOW);

	pinMode(this->_pin, INPUT);
	long dur = pulseIn(this->_pin, HIGH);
	return dur;
}

void ultraSonic::setPin() {
	pinMode(this->_pin, OUTPUT);
}



