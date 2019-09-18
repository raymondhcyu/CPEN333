/* Raymond Yu
 * 17 September 2019
 * 11298149
 */

#include <stdio.h>
#include "CPullLamp.h"

/*REVIEW CONTENT; how to inherit function & syntax*/
/*Note: Only constructors have ClassName::ClassName() {}, else void ClassName::FuncName() {}*/

CPullLamp::CPullLamp(int w1, int w2, int w3) 
	: CLamp3Bulb(w1, w2, w3) // need member initialization list b/c calling another class
{
	printf("CPullLamp default constructor called.\n");
}

void CPullLamp::toggle() {
	if (getState())
		CLamp3Bulb::lampOff();
	else
		CLamp3Bulb::lampOn();
}