
#include "ch.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"
#include "cmdadc.h"
extern int adcDataReady;        
extern float value;
float valu = 12.0;

static int cmdParseArguments (BaseSequentialStream *, int, char *[], int);

void cmdGetTemp(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	static WORKING_AREA(adcTempArea, 128);
        adcSTM32SetCCR(ADC_CCR_VBATEN | ADC_CCR_TSEN | ADC_CCR_VREFEN);
        chprintf((BaseSequentialStream*)&SD1, "Temperature Conversion Started");
	(void)chThdCreateStatic(adcTempArea,sizeof(adcTempArea), NORMALPRIO,adcConversionThread,NULL); 
	while (adcDataReady ==FALSE)
	{	
		chprintf((BaseSequentialStream*)&SD1, "waiting");
	}
	float value1 = 3.3*(value/40)*100;
	float valu2 = 12.54;
	chprintf(chp, "TEMP DCV: %2.6f \n\r", valu2); 
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

	//checks option list for caller

	//checks


}

