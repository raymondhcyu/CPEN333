#include <stdio.h>
#include "CSwitch.h"

CSwitch::CSwitch() {
	state = 0; // default off
	printf("Default CSwitch constructor called.\n");
}

void CSwitch::turnOn() {
	state = 1;
}

void CSwitch::turnOff() {
	state = 0;
}

int CSwitch::getState() const {
	return state;
}

void CSwitch::print() {
	if (state == 0)
		printf("Switch is off.\n");
	else
		printf("Switch is on.\n");
}

CSwitch::~CSwitch() {
	printf("CSwitch destructor called.\n");
}