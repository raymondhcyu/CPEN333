#pragma once

#ifndef   __CPullLamp__
#define   __CPullLamp__

#include "CLamp3Bulb.h"

class CPullLamp : public CLamp3Bulb
{
private:
	void lampOn() {}; // empty function to disable call
	void lampOff() {};
public:
	CPullLamp(int w1, int w2, int w3); // default constructor
	void toggle(); // toggle on/off switch
};

#endif