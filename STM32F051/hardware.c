
#include "hardware.h"

/*
pin[0].pinPort = GPIOA;
pin[0].pinNumber = 0;
pin[0].pinOptions = INPUT | OUTPUT |ADC |DAC |UART;
*/


#define INPUT 0x01
#define OUTPUT 0x02
#define ADC 0x04
#define DAC 0x08
#define UART 0x10
#define SPI 0x20
#define I2C 0x40
#define PWM 0x80


int hardwareSetPins(int pinsToBeUsed, int mode)
{
	switch (mode)
	{
		case INPUT:
			break;
		case OUTPUT:
			break;
		case ADC:
			break;
		case DAC:
			break;
		case UART:
			break;
		case SPI:
			break;
		case I2C:
			break;
		case PWM:
			break;
	
	}

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
