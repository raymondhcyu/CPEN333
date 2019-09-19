/* Raymond Yu
 * 17 September 2019
 * 11298149
 */

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
	lightBulb.turnOn();
	lightBulb.printState();
	lightBulb.setWatts(200);
	lightBulb.printState();

	lightBulb.turnOff();
	printf("Power used: %iW\n", lightBulb.getPower());
	lightBulb.turnOn();
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

	// Pull lamp testing (inherited)
	printf("\n");
	CPullLamp L1(100, 100, 100); // initialize three new bulbs to 100W

	L1.toggle();
	printf("Power of Lamp = %d\n", L1.getPower());	// print power
	CBulb* bulb1 = new CBulb(50);	// create new 50 watt bulb
	bulb1 = L1.exchangeBulb(bulb1, 0);	// swap bulb 0 for 50 watt bulb
	delete bulb1; // delete to free memory
	printf("Power of Lamp = %d\n", L1.getPower());	// print power

	L1.toggle();
	printf("Power of Lamp = %d\n", L1.getPower());	// print power

	// Linked list with ints
	cout << "\n\n\n";
	LinkedList<int> theList; // LinkedList is a template now taking int data
	theList.Insert(5);
	theList.Insert(4);
	theList.Insert(3);
	printf("The 3rd value in the LL is %i\n", theList.GetVal(2));
	cout << "The length of LL is: " << theList.GetLen() << endl;
	theList.ListData();
	theList.DelVal(); 
	cout << "The length of LL is: " << theList.GetLen() << endl;
	theList.ListData();

	// Linked list with bulbs
	cout << "\n\n\n";
	CBulb b1(100); // create 100W bulb
	CBulb b2(120); // create 120W bulb
	LinkedList<CBulb*> L2; // LL which holds CBulb pointers
	L2.Insert(&b1); // insert node pointing to b1
	L2.Insert(&b2); // insert node pointing to b2
	L2.ListData(); // list data in L2 (shows memory addresses)
	printf("The power of the 1st value of L2 is %i\n", L2.GetVal(0)->getPower());
	printf("The power of the 2nd value of L2 is %i\n", L2.GetVal(1)->getPower());
	b1.turnOn(); // turn states on to get power
	b2.turnOn();
	cout << "The power of the 1st value of L2 is: " << L2.GetVal(0)->getPower() << endl;
	cout << "The power of the 2nd value of L2 is: " << L2.GetVal(1)->getPower() << endl;
	cout << "The length of L2 is: " << L2.GetLen() << endl;

	//L2.Insert(5);		// Error cannot add an int to a list that only accepts CBulb pointers
	//L2.Insert(&s1);		// Error cannot add a switch pointer to this list 
	return 0;
}