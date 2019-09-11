#include <stdio.h>
#include "CLamp3Bulb.h"

CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3) {

	// Set wattages of mainbulbs
	mainBulbs[0].setWatts(w1);
	mainBulbs[1].setWatts(w2);
	mainBulbs[2].setWatts(w3);

	printf("Default CLamp3Bulb constructor, setting wattages!\n");
}

void CLamp3Bulb::lampOn() {
	mainSwitch.turnOn();
	for (int i = 0; i < 3; i++) { // mainBulbs.size()
		mainBulbs[i].setState(0);
	}
}

void CLamp3Bulb::lampOff() {
	mainSwitch.turnOff();
	for (int i = 0; i < 3; i++) {
		mainBulbs[i].setState(1);
	}
}

int CLamp3Bulb::getState() {
	return mainSwitch.getState();
}

void CLamp3Bulb::print() {
	mainSwitch.print();
}

int CLamp3Bulb::getPower() {
	int sum = 0; // sum of power
	for (int i = 0; i < 3; i++) {
		mainBulbs[i].setState(1);
		sum += mainBulbs[i].getPower();
	}
	return sum;
}

CLamp3Bulb::~CLamp3Bulb() {
	printf("CLamp3Bulb destructor called.\n");
}