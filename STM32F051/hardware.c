
#include "hardware.h"

/*
pin[0].pinPort = GPIOA;
pin[0].pinNumber = 0;
pin[0].pinOptions = INPUT | OUTPUT |ADC |DAC |UART;
*/

int hardwareSetPins(int pinsToBeUsed, int mode)
{
	// first check pin use against what is possible

	// set pins modes appropraitely

	//
}



int hardwareCheckPins(int pinsToBeUsed, int mode)
{
	int pinValue = 0;
	int pinComparison = 0x01;
	while( pinComparison <= 0x80)
	{
		if((pinCapabilities[pinValue].pinOptions && mode) == mode)
		{
			pinValue++;
			pinComparison =pinComparison <<1;
		}
		else
		{

			//trying to set a function which does not exist on that pin.
		}
	}

}
