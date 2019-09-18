/* Raymond Yu
 * 17 September 2019
 * 11298149
 */

#include <stdio.h>
#include "CBulb.h"

// REMEMBER: State is already defined in CBulb.h so don't have to pass it in

CBulb::CBulb() { // constructor to preinitialize state to 0
	state = 0;
	watts = 0;
	printf("Default CBulb constructor called.\n");
}

CBulb::CBulb(int setWatt) {
	state = 0;
	watts = setWatt;
	printf("Setwatt constructor called.\n");
}

CBulb::~CBulb() { // destructor automatically called when object ends
	printf("CBulb destructor called.\n");
}

void CBulb::printState() {
	if (state == 0)
		printf("State is off\n");
	else
		printf("State is on with a wattage of: %iW\n", watts);
		//printf("State is on with a wattage of: %iW\n", CBulb.getPower());
}

void CBulb::setState(int changeState) {
	state = changeState;
}

int CBulb::getState() {
	return state;
}

void CBulb::setWatts(int setWatt) {
	watts = setWatt;
}

int CBulb::getPower() const {
	if (state == 0)
		return 0;
	else
		return watts;
}