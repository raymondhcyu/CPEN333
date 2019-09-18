#include <stdio.h>
#include <iostream> // to get cout cin
#include "CBulb.h"
#include "CSwitch.h"
#include "CLamp3Bulb.h"
#include "CPullLamp.h"
#include "linkedList.h"

using namespace std;

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
	CBulb* newBulb = new CBulb(500); // newBulb to replace
	newBulb = tripleBulbs.exchangeBulb(newBulb, 0); // newBulb is actually now oldBulb
	printf("Power of old bulb: %iW\n", newBulb->getPower()); // should state 10W
	delete newBulb; // clear memory
	tripleBulbs.print();
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());
	tripleBulbs.lampOff();
	tripleBulbs.print();
	printf("Triple bulbs are consuming %iW\n", tripleBulbs.getPower());
	//delete newBulb; // if uncomment, invalid address heap error; does deconstructor delete all objects anyways

	// Pull lamp testing (inherited)
	printf("\n");
	CPullLamp L1(100, 100, 100); // initialize three new bulbs to 100W

	//L1.lampOn(); // changed to private void
	L1.toggle();
	printf("Power of Lamp = %d\n", L1.getPower());	// print power
	CBulb* bulb1 = new CBulb(50);	// create new 50 watt bulb
	bulb1 = L1.exchangeBulb(bulb1, 0);	// swap bulb 0 for 50 watt bulb
	printf("Power of Lamp = %d\n", L1.getPower());	// print power

	//L1.lampOff(); // changed to private void
	L1.toggle();
	printf("Power of Lamp = %d\n", L1.getPower());	// print power

	// Linked lists
	cout << "\n\n\n";
	LinkedList theList;
	theList.AddNode(5);
	theList.AddNode(4);
	theList.AddNode(3);
	printf("The 3rd value in the LL is %i\n", theList.GetVal(2));
	cout << "The length of LL is: " << theList.GetLen() << endl;
	theList.ListData();
	cout << "\n\n\n";

	return 0;
}