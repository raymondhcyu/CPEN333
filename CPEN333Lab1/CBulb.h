/* Raymond Yu
 * 17 September 2019
 * 11298149
 */

#pragma once

#ifndef   __CBulb__
#define   __CBulb__

class CBulb {
private: // private var unaccessible
	int state; // onoff condition of bulb
	int watts; // power of bulb

public:
	CBulb(); // constructor to pre-initialize state and watts to 0
	CBulb(int setWatt); // constructor to change wattage
	~CBulb(); // destructor, auto call after end

	void printState();
	void turnOn();
	void turnOff();
	void setState(int changeState);
	int getState(); // get onoff state
	void setWatts(int setWatt);
	int getPower() const; // get power use
};

#endif 
