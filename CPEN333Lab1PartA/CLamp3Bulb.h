#pragma once

#ifndef   __CLamp3Bulb__
#define   __CLamp3Bulb__

#include "CBulb.h"
#include "CSwitch.h"

class CLamp3Bulb {
private:
	CSwitch mainSwitch;
	CBulb mainBulbs[3]; // initialize 3 CBulb objects

public:
	CLamp3Bulb(int w1, int w2, int w3); // default constructor
	void lampOn(); // turn on all lights
	void lampOff(); // turn off all lights
	int getState(); // return state of switch
	void print(); // print state of lamp, on or off
	int getPower(); // return power consumed by lamp
	~CLamp3Bulb(); // destructor
};

#endif