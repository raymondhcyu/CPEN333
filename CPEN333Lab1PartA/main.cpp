#include <stdio.h>
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
	tripleBulbs.lampOn();
	tripleBulbs.print();
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());

	return 0;
}