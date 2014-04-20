#include "ch.h"
#include "chprintf.h"
#include "hal.h"
#include "hardware.h"
#include "ctype.h"
pinSetting hwPin[9];
extern ADCConversionGroup adcSettings;

void hello(void)
{
        chprintf((BaseSequentialStream*)&SD1, "HelloWorld");
	chThdSleepMilliseconds(1000);
}


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

//sets mode for pin

int hardwareSetupPin(int pinToBeUsed, int mode)
{
	int pinLocation = pinToBeUsed;
	if (pinLocation !=ERR_PIN)
	{

		switch (mode)
		{
			case HW_NONE:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_UNCONNECTED);      /*  unconnected      */
				break;
			case HW_INPUT:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT);      /*  INPUT      */
				break;
			case HW_PP:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_OUTPUT_PUSHPULL);      /*  INPUT      */
				break;
			case HW_ADC:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
				break;
			case HW_DAC:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
				break;
			case HW_UART:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
				break;
			case HW_SPI:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
				break;
			case HW_I2C:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
				break;
			case HW_PWM:
				palSetPadMode(hwPin[pinLocation].pinPort, hwPin[pinLocation].pinNumber, PAL_MODE_INPUT_ANALOG);      /* ADC       */
				break;
			default:
				return FALSE;
				//error mode dne
		}
		//setting current mode, returning true
                hwPin[pinLocation].currentSetting =mode;
		 return TRUE;

	}

}




//sets hardware mode of pins , returns 
int hardwareSetupPins(int * arrayOfPinLocations, int mode)
{
	if(!hardwareCheckPins(arrayOfPinLocations,mode))
	{
		return FALSE;

	}
	int i = 1;
	int pinSetSuccess;
	while(arrayOfPinLocations[i] !=END_PIN)
	{
		pinSetSuccess =hardwareSetupPin(arrayOfPinLocations[i],mode);
		if (pinSetSuccess ==FALSE)
		{

			return FALSE;
			//setting pin failed, either due to pin location  fail or function or otherwise


		}
		i++;
	}
	//all pins to be set were set
	return TRUE;

}


int hardwareCheckPins(int * arrayOfPinLocations, int mode)
{
	int i =1;
	while(arrayOfPinLocations[i] !=END_PIN)
	{
		if(!hardwareCheckPin(arrayOfPinLocations[i],mode))
		{

			return FALSE;
		//trying to set a function which does not exist on that pin.
		}
	i++;

	}
	return TRUE;

}
int hardwareCheckPin(int pinLocation,int mode)
{

	if((hwPin[pinLocation].pinOptions & mode) != mode)
	{

		return FALSE;
	}
	return TRUE;

}

int hardwareCheckCurrentModes(char * pinsToBeUsed)
{
	int pinValue =0;
	int arrayOfPinLocations[8];
	hardwareGetPinLocations(pinsToBeUsed, arrayOfPinLocations);

	if(pinValue == 255)
	{
		return FALSE;
                // pin does not exist in mapping
	}
	return hwPin[pinValue].currentSetting;
}

//converts char to location
//rerurns adc loation
int hardwareSetAdcCircular(int circular)
{
	adcSettings.circular =circular;
	return 0;
}


int hardwareGetAdcLocation(int pinToBeUsed)
{
	return hwPin[pinToBeUsed].pinAdcAddress;

}


int hardwareSetAdcChannels(int * pinsToBeUsed)
{
	int chselr =0; //channel select
	int num_channels =0; //number of selected channels
	adcSettings.chselr =0;
	adcSettings.num_channels =0;
	int i = 0;

	while (pinsToBeUsed[i] != END_PIN)
	{
		num_channels++;
		int tempCh = hwPin[pinsToBeUsed[i]].pinAdcAddress;
		if ((tempCh & chselr) ==tempCh)
		{
			//channel has already beed selected
			num_channels--;
		}
		chselr |=tempCh;
		i++;
	}
	adcSettings.chselr = chselr;
	adcSettings.num_channels =num_channels;
	return TRUE;
}

int * hardwareGetIoPort(int pinToBeUsed)
{
	return hwPin[pinToBeUsed].pinPort;
}
int hardwareGetIoPin(int pinToBeUsed)
{
	return hwPin[pinToBeUsed].pinNumber;

}

int hardwareGetPinLocations(char * pins,int * arrayToBeFilled)
{
	hardwareParseDecimalPins(pins,arrayToBeFilled);
	return 0;

}

int  hardwareParseDecimalPins(char * pinsToBeUsed, int * arrayToBeFilled)
{
	int i = 1;
	while(pinsToBeUsed[i] !='\0')
	{
        	switch (pinsToBeUsed[i])
        	{
                	case '0':
				arrayToBeFilled[i]= PIN_0;
				break;
			case '1':
				arrayToBeFilled[i]= PIN_1;
				break;
			case '2':
				arrayToBeFilled[i]= PIN_2;
				break;
			case '3':
				arrayToBeFilled[i]= PIN_3;
				break;
			case '4':
				arrayToBeFilled[i]= PIN_4;
				break;
                	case '5':
				arrayToBeFilled[i]= PIN_5;
				break;
			case '6':
				arrayToBeFilled[i]= PIN_6;
				break;
			case '7':
				arrayToBeFilled[i]= PIN_7;
				break;
			default:
                        	//pin not found
				arrayToBeFilled[i]= ERR_PIN;
				break;
		}

	i++;
	}
	arrayToBeFilled[i]=END_PIN;
	return 0;


}

int hardwareParseHex(char *pinsToBeUsed)
{
	return 0;
}


int hardwareReadPins(int *arrayOfPinLocations)
{
	(void)arrayOfPinLocations;
	return 0;	
}
