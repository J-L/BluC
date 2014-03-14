
#include "ch.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"
#include "cmdadc.h"
extern int adcDataReady;        
extern float value;
extern ADCConversionGroup adcSettings;

static int cmdParseArguments (BaseSequentialStream *, int, char *[], int);

void cmdGetTemp(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	// adc settings are settingspassed to new thread
	ADCConversionGroup adcSettings = {
    		FALSE,
    		ADCTEMPCHANNELS,
    		adcTempCallBack,
    		adcErrorCallBack,
    		ADC_CFGR1_RES_12BIT,                              /* CFGRR1 */
    		ADC_TR(0, 0),                                     /* TR */
    		ADC_SMPR_SMP_1P5,                                 /* SMPR */
    		ADC_CHSELR_CHSEL16                                /* CHSELR */
	};
	//creating space in memory for the adc thread
	static WORKING_AREA(adcTempArea, 128);
	//turning on pheripherals
        adcSTM32SetCCR(ADC_CCR_VBATEN | ADC_CCR_TSEN | ADC_CCR_VREFEN);
        chprintf((BaseSequentialStream*)&SD1, "Temperature Conversion Started");
	//thread created, need to change to dynamic pool allocation
	(void)chThdCreateStatic(adcTempArea,sizeof(adcTempArea), NORMALPRIO,adcConversionThread,&adcSettings); 
	//this should be replaced with a thread wait for message
	while (adcDataReady ==FALSE)
	{	
		chprintf((BaseSequentialStream*)&SD1, "waiting");
	}
	//data made
	int value1 = (int)(330*value/4095);
	chprintf(chp, "TEMP DCV: %d \n\r", value1); 
	//should kill adc thread at this point
}

void cmdGetVoltage(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	// create working area for new thread

	//set pheriperals

	//create thread

	//wait for callback thread

	//print returned value

    chprintf(chp, "Hello World");  

}

void cmdGetBattery(BaseSequentialStream *chp, int argc, char *argv[]) 
{
        // create working area for new thread

        //set pheriperals

        //create thread

        //wait for callback thread

        //print returned value


    chprintf(chp, "Hello World");  

}

/*
cmdAdc
	handles the 'adc' command when entered, making sense of the command
	received,  setting up the adc, callback etc.

*/

void cmdAdc(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parse input arguments
	cmdParseArguments (chp,argc, *argv,  14);
	//set up peripherals

	//setup adc conversion arguments

	//create thread



	chprintf(chp, "Hello World");  

}

void cmdDac(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parse arguments
	//initialise dac 

	//initialise dac  pheripheral

	//create thread

	//threadsleep

	//threadwakup

	//thread kill

    chprintf(chp, "Hello World");  

}

void cmdUart(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parse arguments

	//if no arguments supplied, shows current configuration

	//if arguments supplied,  change configuration

	//if  start found, gogogo
    chprintf(chp, "Hello World");  

}

void cmdSpi(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdBluetooth(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parses  Bluetooth arguments

	//if no arguments,  returns status

	//if arguments , changes configuration in memory (restart required)

    chprintf(chp, "Hello World");  

}



void cmdI2c(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}


void cmdPwm(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdDate(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parses arguments

	//if  no argument, print system time

	//in argument,  set system time


    chprintf(chp, "Hello World");  

}


//parses commands for sense. if no sense, prints error to console

static int cmdParseArguments (BaseSequentialStream *chp, int argc, char *argv[], int caller)
{
	//removes white space
	int i = 0;
	while (i< argc)
	{
		chprintf(chp, argv);
		i++;
	}
	//checks option list for caller
	switch(caller)
	{
		case CMD_ADC:
			break;
                case CMD_DAC:
                        break;
                case CMD_PWM:
                        break;
                case CMD_DATE:
                        break;
                case CMD_UART:
                        break;
                case CMD_SPI:
                        break;
                case CMD_I2C:
                        break;
                case CMD_BLUETOOTH:
                        break;
                case CMD_IO:
                        break;
	}
	//checks


}

static int parseCmdAdc (BaseSequentialStream *chp, int argc, char *argv[])
{
	// find first argument
	int adcSelectedChannels = 0;
	int adcNumberOfSelectedChannel = 0;
	// check if continuous os one shot
	if (char =='c')
	{
		//continuous
	}
	else if ( char == 'o')
	{
		//one shot
	}
	else
	{
		return False;
	}
	// while characters in channel selection argument
	while (number of characters in second  arg)
	{
		//switch for charcter	
		switch (pointer_to_char)
		{
				case '1':
					break;
				case '2':
					break;
				case '3':
					break;
				case '4':
					break;
				case '5':
					break;
				case '6':
					break;
                                case '7':
                                        break;
                                case '8':
                                        break;
                                case '9':
                                        break;
				default:
					return False;
				//not a valid  charc
		}
		
	}
	//looks at frequency argument (if exists)
	while (characters in next arg)
	{
		
	}
	// looks at output pointer (if exists)
	//sets output pins, warn is not ok.
	

}

statitc int parseCmdUart(BaseSequentialStream *chp, int argc, char *argv[])
{
	//check if first command is letter or number

	// if letter

	// if number
		//check if valid baud rate
			//set hardware pins on
			//warns if must turn off other programs
			// check if escape argument has been given
}


static int parseCmdIo(BaseSequentialStream *chp, int argc, char *argv[])
{
	// check if input or output
		//parse pins
		// set pins up
}

static int parseCmdDac(BaseSequentialStream *chp, int argc, char *argv[])
{


}

static int parseCmdPwm(BaseSequentialStream *chp, int argc, char *argv[])
{


}

static int parseCmdBluetooth(BaseSequentialStream *chp, int argc, char *argv[])
{


}

static int parseCmdDate(BaseSequentialStream *chp, int argc, char *argv[])
{


}


