#include <stdio.h>
#include <iostream> // to get cout cin
#include "CBulb.h"
#include "CSwitch.h"
#include "CLamp3Bulb.h"

int main() {

	CBulb lightBulb; // cannot have () if no input arguments for class
	CSwitch lightSwitch;
	CLamp3Bulb tripleBulbs(10, 20, 30);

	// Bulb testing
	lightBulb.printState();

	lightBulb.setState(1);
	lightBulb.printState();

	lightBulb.setWatts(200);
	lightBulb.printState();

	lightBulb.setState(0);
	printf("Power used: %iW\n", lightBulb.getPower());

	lightBulb.setState(1);
	printf("Power used: %iW\n", lightBulb.getPower());

	// Switch testing
	lightSwitch.print();

	// Lamp3Bulb testing
	tripleBulbs.print();
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());
	tripleBulbs.lampOn();
	tripleBulbs.print(); // calls getState
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());

	// Exchange testing
	CBulb* newBulb = new CBulb(500);
	tripleBulbs.exchangeBulb(newBulb, 0);
	tripleBulbs.print();
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());
	tripleBulbs.lampOff();
	tripleBulbs.print();
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());
	//delete newBulb; // if uncomment, invalid address heap error; does deconstructor delete all objects anyways

	return 0;
}