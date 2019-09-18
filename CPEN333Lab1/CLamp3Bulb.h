#pragma once

#ifndef   __CLamp3Bulb__
#define   __CLamp3Bulb__

#include "CBulb.h"
#include "CSwitch.h"

class CLamp3Bulb {
private:
	CSwitch *mainSwitch;
	CBulb *mainBulbs[3]; // initialize 3 CBulb objects as pointers

public:
	CLamp3Bulb(int w1, int w2, int w3); // default constructor
	void lampOn(); // turn on all lights
	void lampOff(); // turn off all lights
	int getState() const; // return state of switch
	void print(); // print state of lamp, on or off
	int getPower() const; // return power consumed by lamp

	// Function to exchange bulbs; returns pointer to old bulb
	// "take ownership of new bulb and returns pointer to old bulb
	CBulb* exchangeBulb(CBulb* newBulb, int bulbNumber); 

	// Copy constructor
	CLamp3Bulb(const CLamp3Bulb& lampToCopy);

	~CLamp3Bulb(); // destructor
};

#endif