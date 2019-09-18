#include <stdio.h>
#include "CLamp3Bulb.h"

CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3) {

	// Create new variables since they're pointers
	mainSwitch = new CSwitch();
	mainBulbs[0] = new CBulb(w1);
	mainBulbs[1] = new CBulb(w2);
	mainBulbs[2] = new CBulb(w3);

	//// Set wattages of mainbulbs
	//mainBulbs[0]->setState(mainBulbs[0]->getState());
	//mainBulbs[1]->setState(mainBulbs[1]->getState());
	//mainBulbs[2]->setState(mainBulbs[2]->getState());

	printf("Default CLamp3Bulb constructor, setting wattages!\n");
}

void CLamp3Bulb::lampOn() {
	mainSwitch->turnOn();
	for (int i = 0; i < 3; i++) { // mainBulbs.size()
		mainBulbs[i]->setState(1);
	}
}

void CLamp3Bulb::lampOff() {
	mainSwitch->turnOff();
	for (int i = 0; i < 3; i++) {
		mainBulbs[i]->setState(0);
	}
}

int CLamp3Bulb::getState() const {
	return mainSwitch->getState();
}

void CLamp3Bulb::print() {
	mainSwitch->print();
}

int CLamp3Bulb::getPower() const {
	int sum = 0; // sum of power
	for (int i = 0; i < 3; i++) {
		sum += mainBulbs[i]->getPower();
	}
	return sum;
}

CBulb* CLamp3Bulb::exchangeBulb(CBulb* newBulb, int bulbNumber) {
	printf("Exchange constructor called.\n");
	CBulb* oldBulb = new CBulb(); // create a pointer to an oldbulb object
	oldBulb = mainBulbs[bulbNumber]; // point to the bulb to be replaced
	mainBulbs[bulbNumber] = newBulb; // replace the bulb
	newBulb->setState(1); // turn it on

	return oldBulb; // pointer to the oldbulb
}

CLamp3Bulb::CLamp3Bulb(const CLamp3Bulb &lampToCopy) { // need const as copy constructor
	mainSwitch = new CSwitch(); // copy switch

	if (lampToCopy.getState() == 1) // copy switch setting
		mainSwitch->turnOn();
	else
		mainSwitch->turnOff();

	mainBulbs[0] = new CBulb(lampToCopy.getPower()); // copy bulbs and power
	mainBulbs[1] = new CBulb(lampToCopy.getPower());
	mainBulbs[2] = new CBulb(lampToCopy.getPower());

	mainBulbs[0]->setState(lampToCopy.getState()); // copy state of lamps
	mainBulbs[0]->setState(lampToCopy.getState());
	mainBulbs[0]->setState(lampToCopy.getState());

	printf("CLamp3Bulb copy constructor called.\n");
}


CLamp3Bulb::~CLamp3Bulb() {
	delete mainSwitch; // delete pointers
	delete mainBulbs[0];
	delete mainBulbs[1];
	delete mainBulbs[2];
	printf("CLamp3Bulb destructor called.\n");
}