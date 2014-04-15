#include "hal.h"
#include "hardware.h"
pinSetting hwPin[8];
int adcNumberOfSelectedChannel = 0;
int adcSelectedChannels =0;





void hardwareInitialise(void)
{
	hwPin[PIN_0].pinPort = GPIOA;
	hwPin[PIN_0].pinNumber = 0;
	hwPin[PIN_0].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
	hwPin[PIN_0].pinAdcAddress =ADC_CHSELR_CHSEL0;
	hwPin[PIN_0].pinTimerAddress =0;
	hwPin[PIN_0].currentSetting=HW_NONE;

        hwPin[PIN_1].pinPort = GPIOA;
        hwPin[PIN_1].pinNumber = 1;
        hwPin[PIN_1].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_1].pinAdcAddress =ADC_CHSELR_CHSEL1;
        hwPin[PIN_1].pinTimerAddress =0;
        hwPin[PIN_1].currentSetting=HW_NONE;

        hwPin[PIN_2].pinPort = GPIOA;
        hwPin[PIN_2].pinNumber = 2;
        hwPin[PIN_2].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_2].pinAdcAddress =ADC_CHSELR_CHSEL2;
        hwPin[PIN_2].pinTimerAddress =0;
        hwPin[PIN_2].currentSetting=HW_NONE;

        hwPin[PIN_3].pinPort = GPIOA;
        hwPin[PIN_3].pinNumber = 3;
        hwPin[PIN_3].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_3].pinAdcAddress =ADC_CHSELR_CHSEL3;
        hwPin[PIN_3].pinTimerAddress =0;
        hwPin[PIN_3].currentSetting=HW_NONE;

        hwPin[PIN_4].pinPort = GPIOA;
        hwPin[PIN_4].pinNumber = 4;
        hwPin[PIN_4].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_4].pinAdcAddress =ADC_CHSELR_CHSEL4;
        hwPin[PIN_4].pinTimerAddress =0;
        hwPin[PIN_4].currentSetting=HW_NONE;

        hwPin[PIN_5].pinPort = GPIOA;
        hwPin[PIN_5].pinNumber = 5;
        hwPin[PIN_5].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_5].pinAdcAddress =ADC_CHSELR_CHSEL5;
        hwPin[PIN_5].pinTimerAddress =0;
        hwPin[PIN_5].currentSetting=HW_NONE;

        hwPin[PIN_6].pinPort = GPIOA;
        hwPin[PIN_6].pinNumber = 6;
        hwPin[PIN_6].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_6].pinAdcAddress =ADC_CHSELR_CHSEL6;
        hwPin[PIN_6].pinTimerAddress =0;
        hwPin[PIN_6].currentSetting=HW_NONE;

        hwPin[PIN_7].pinPort = GPIOA;
        hwPin[PIN_7].pinNumber = 7;
        hwPin[PIN_7].pinOptions = HW_INPUT|HW_OUTPUT|HW_UART|HW_ADC;
        hwPin[PIN_7].pinAdcAddress =ADC_CHSELR_CHSEL7;
        hwPin[PIN_7].pinTimerAddress =0;
        hwPin[PIN_7].currentSetting=HW_NONE;

}


/*
#define HW_NONE 0x00
#define HW_INPUT 0x01
#define HW_OUTPUT 0x02
#define HW_ADC 0x04
#define HW_DAC 0x08
#define HW_UART 0x10
#define HW_SPI 0x20
#define HW_I2C 0x40
#define HW_PWM 0x80
*/


//sets hardware mode of pins , returns 
int hardwareSetPins(char * pinsToBeUsed, int mode)
{
	int pinLocation = hardwarePinParse( pinsToBeUsed);
	if(pinLocation !=255)
	{
		switch (mode)
		{
			case HW_NONE:
			case HW_INPUT:
			case HW_OUTPUT:
			case HW_ADC:
			        palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
			case HW_DAC:
			case HW_UART:
			case HW_SPI:
			case HW_I2C:
			case HW_PWM:
			default:
				return FALSE;
				//error mode dne
		}
		//setting current mode, returning true
		hwPin[pinLocation].currentSetting =mode;
		return TRUE;
	}
	//pin loc not found
	return FALSE;
}


int hardwareCheckPins(char * pinToBeUsed, int mode)
{
	int pinValue =0;
	pinValue = hardwarePinParse(pinToBeUsed);
	if(pinValue == 255)
	{
		return FALSE;
		// pin does not exist in mapping
	}
	if((hwPin[pinValue].pinOptions && mode) == mode)
	{
		return TRUE;
	}
	else
	{

		return TRUE;
			//trying to set a function which does not exist on that pin.
	}

}
int hardwareCheckCurrentMode(char * pinToBeUsed)
{
	int pinValue =0;
	pinValue = hardwarePinParse(pinToBeUsed);
	if(pinValue == 255)
	{
		return FALSE;
                // pin does not exist in mapping
	}
	return hwPin[pinValue].currentSetting;
}

//converts char to location
int hardwarePinParse(char * pinToBeUsed)
{
	switch (pinToBeUsed[0])
	{
		case '0':
			return PIN_0;
		case '1':
			return PIN_1;
		case '2':
			return PIN_2;
		case '3':
			return PIN_3;
		case '4':
			return PIN_4;
		case '5':
			return PIN_5;
		case '6':
			return PIN_6;
		case '7':
			return PIN_7;
		default:
                        //pin not found
			return 255;
	}
}
//rerurns adc loation
int hardwareGetAdcAddress(char * pinToBeUsed)
{
	int pinLocation =hardwarePinParse(pinToBeUsed);
	return hwPin[pinLocation].pinAdcAddress;

}

int hardwareGetIoPort(char * pinToBeUsed)
{
	int pinLocation = hardwarePinParse(pinToBeUsed);
	return hwPin[pinLocation].pinPort;
}
int hardwareGetIoPin(char * pinToBeUsed)
{
	int pinLocation = hardwarePinParse(pinToBeUsed);
	return hwPin[pinLocation].pinNumber;

}
