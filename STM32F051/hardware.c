#include "hal.h"
#include "hardware.h"
pinSetting hwPin[8];
extern ADCConversionGroup adcSettings;




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

int hardwareSetupPin(char * pinToBeUsed, int mode)
{
	int pinLocation = hardwarePinParse(pinToBeUsed);
	if (pinLocation !=255)
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
int hardwareSetupPins(char * pinsToBeUsed, int mode)
{
	if(!hardwareCheckPins(pinsToBeUsed,mode))
	{
		return FALSE;

	}
	int i = 1;
	int pinSetSuccess;
	while(pinsToBeUsed[i] !='\0')
	{
		pinSetSuccess =hardwareSetupPin(&pinsToBeUsed[i],mode);
		if (pinSetSuccess ==FALSE)
		{
			return FALSE;
			//setting pin failed, either due to pin location  fail or function or otherwise


		}
	
	}
	//all pins to be set were set
	return TRUE;
}


int hardwareCheckPins(char * pinsToBeUsed, int mode)
{
	int i =1;
	while(pinsToBeUsed[i] !='\0')
	{
	
		int pinValue =FALSE;
		pinValue = hardwarePinParse(pinsToBeUsed);
		if(pinValue == 255)
		{

			return FALSE;
		// pin does not exist in mapping
		}
		if((hwPin[pinValue].pinOptions & mode) != mode)
		{
			return FALSE;

		}
		i++;
		//trying to set a function which does not exist on that pin.
	}
	return TRUE;

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
	return hardwareParseDecimal(pinToBeUsed);
}
//rerurns adc loation
int hardwareSetAdcCircular(int circular)
{

}


int hardwareGetAdcLocation(char * pinToBeUsed)
{
	int pinLocation =hardwarePinParse(pinToBeUsed);
	return hwPin[pinLocation].pinAdcAddress;

}


int hardwareSetAdcChannels(char * pinsToBeUsed)
{
	int chselr =0; //channel select
	int num_channels =0; //number of selected channels
	adcSettings.chselr =0;
	adcSettings.num_channels =0;
	int i = 1;
	while (pinsToBeUsed != '\0')
	{
		num_channels++;
		int tempCh = hardwareGetAdcLocation( pinsToBeUsed[i]);
		if(!tempCh)
		{
			return FALSE ;
			//no location found 
		}
		if ((tempCh & chselr) ==tempCh)
		{
			//channel has already beed selected
			num_channels--;
		}
		chselr |=tempCh;
	}
	adcSettings.chselr = chselr;
	adcSettings.num_channels =num_channels;
	return TRUE;
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

int hardwareParseDecimal(char * pinToBeUsed)
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
int hardwareReadPins(char * pinsToBeUsed)
{
	int pinLoc=hardwarePinParse(pinsToBeUsed);
	
}
