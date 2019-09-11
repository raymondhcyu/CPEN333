#pragma once

#ifndef   __CSwitch__
#define   __CSwitch__

class CSwitch {
private:
	int state;

public:
	CSwitch(); // default constructor
	void turnOn(); // turn on
	void turnOff();
	int getState();
	void print(); // status
	~CSwitch();
};

#endif 