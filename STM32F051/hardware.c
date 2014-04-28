
#include <stdio.h>
#include <string.h>
#include "ch.h"
#include "chprintf.h"
#include "hal.h"
#include "hardware.h"
#include "ctype.h"
#include "shell.h"
pinSetting hwPin[9];

//extern ShellConfig shCfg;
const char* serialValidBaudRates[SERIAL_NUM_BAUD_RATES]={"-9600","-14400","-19200","-38400","-57600","-115200","-230400"};
const char* serialValidEncoding[SERIAL_NUM_ENCODING]={"-8N1"};

extern ADCConversionGroup adcSettings;
extern char breakSequence;
extern Thread * sh;

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
	while(arrayOfPinLocations[i] !=END_PIN && i<NUM_OF_PIN)
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
	while(arrayOfPinLocations[i] !=END_PIN &&i <NUM_OF_PIN)
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
int hardwareGetFreePins(int * arrayToBeReturned)
{
	int j = 0;// arraytobeused incrementer
	int i= 1;//list of pins incrementer
	while(i<=NUM_OF_PIN)
	{
		if(hardwareGetCurrentMode(i) ==HW_NONE)
		{
//			hello();
			arrayToBeReturned[j]=i;
			j++;
		}
		i++;
	}
	if (j<=NUM_OF_PIN)
	{
		arrayToBeReturned[j]=END_PIN;
	}
	return 0;

}
int hardwareGetCurrentMode(int  pinToCheck)
{
	return hwPin[pinToCheck].currentSetting;
}

int hardwareCheckCurrentModes(char * pinsToBeUsed)
{
	int pinValue =0;
	int arrayOfPinLocations[NUM_OF_PIN];
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
int hardwareAdcSetCircular(int circular)
{
	adcSettings.circular =circular;
	return 0;
}


int hardwareAdcGetLocation(int pinToBeUsed)
{
	return hwPin[pinToBeUsed].pinAdcAddress;

}


int hardwareAdcSetChannels(int * pinsToBeUsed)
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

int * hardwareIoGetPort(int pinToBeUsed)
{
	return hwPin[pinToBeUsed].pinPort;
}
int hardwareIoGetPin(int pinToBeUsed)
{
	return hwPin[pinToBeUsed].pinNumber;

}

int hardwareGetPinLocations(char * pins,int * arrayToBeFilled)
{
	if (hardwareParseDecimalPins(pins,&arrayToBeFilled[0]))
	{
		return 1;
	}
	return 0;

}

int  hardwareParseDecimalPins(char * pinsToBeUsed, int * arrayToBeFilled)
{
	int i = 1;
	while(pinsToBeUsed[i] !='\0')
	{
		//	hello();

        	switch (pinsToBeUsed[i])
        	{
                	case '0':
				arrayToBeFilled[i-1]= PIN_0;
				break;
			case '1':
				arrayToBeFilled[i-1]= PIN_1;
				break;
			case '2':
				arrayToBeFilled[i-1]= PIN_2;
				break;
			case '3':
				arrayToBeFilled[i-1]= PIN_3;
				break;
			case '4':
				arrayToBeFilled[i-1]= PIN_4;
				break;
                	case '5':
				arrayToBeFilled[i-1]= PIN_5;
				break;
			case '6':
				arrayToBeFilled[i-1]= PIN_6;
				break;
			case '7':
				arrayToBeFilled[i-1]= PIN_7;
				break;
			default:
                        	//pin not found
				arrayToBeFilled[i-1]= END_PIN;
				return 1;
				break;
		}

	i++;
	}
	arrayToBeFilled[i-1]=END_PIN;
	return 0;


}

int hardwareParseHex(char *pinsToBeUsed)
{
	return 0;
}


int hardwareReadPins(int *arrayOfPinLocations)
{
//	hello();
	int i =0;
	int value =0;
	int logic = 0;
	while(arrayOfPinLocations[i] != END_PIN && i <NUM_OF_PIN)
	{
//		hello();
		logic = palReadPad(hwPin[arrayOfPinLocations[i]].pinPort, hwPin[arrayOfPinLocations[i]].pinNumber);
		if (logic)
		{
			value |= (1U<<(arrayOfPinLocations[i]-1));
		}
		i++;
	}
	return value;	
}

int hardwareSetPins(int *arrayOfPinLocations, int * arrayOfPinsToSet)
{
	int i = 0;
	int logic = FALSE;
	while(arrayOfPinLocations[i] !=END_PIN&&i<NUM_OF_PIN)
	{
		int j = 0;
		logic = FALSE;
		while(arrayOfPinsToSet[j]!=END_PIN &&j<NUM_OF_PIN)
		{
			if(arrayOfPinLocations[i] ==arrayOfPinsToSet[j])
			{
				logic=TRUE;
			}
			j++;
		}
		palWritePad(hwPin[arrayOfPinLocations[i]].pinPort, hwPin[arrayOfPinLocations[i]].pinNumber,logic);
		i++;

	}
}


/*

String compare on inputted baudrate given by uart command
Returns value of comparison, 255 if not kosher

*/

int hardwareSerialSetBaudRate(char * input)
{
	int i = 0;
	while(i< SERIAL_NUM_BAUD_RATES)
	{
		if(!strcmp(serialValidBaudRates[i],input) )
		{
//		hello();

			return i;
		}
		i++;

	}
	return ERR_CMD;


}

int hardwareSerialSetEncoding(char *input)
{
	int i=0;
	int argIncrementer = 0;
	//arg 0 => number of bits
	//arg 1 parityyyyy
	//arg2 =>
	while(i < SERIAL_NUM_ENCODING)
	{
		if(!strcmp(serialValidEncoding[i],input))
		{
			return i;


		}
		i++;
	}
	return ERR_CMD;

}
tfunc_t hardwareSerialTransparentThread(void)
{
	while(1)
	{
		if(strstr("~~~~~~~~~",&breakSequence)!=NULL)
		{
			hello();
//			sh =shellCreate(&shCfg, 512, NORMALPRIO);
			return NULL;

		}


	}





}
