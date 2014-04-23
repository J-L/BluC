
#include "ch.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"
#include "cmdadc.h"
#include "adc.h"
#include "cmd.h"
#include  <string.h>
#include "hardware.h"

extern int threadCount;
extern Thread *threadArray[];

extern ADCConversionGroup adcSettings;

extern MemoryPool mp;
extern adcsample_t samples;
extern BinarySemaphore adcSemDataReady;
char error[] = "Error Parsing String";
outputResponseStruct outputResponseData;



BSEMAPHORE_DECL(outputResponseDataReady, 0);

void cmdGetTemp(BaseSequentialStream *chp, int argc, char *argv[]) 
{
(void)chp;
(void)argc;
(void)argv;

}

void cmdGetVoltage(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	// create working area for new thread

	//set pheriperals

	//create thread

	//wait for callback thread

	//print returned value

(void)chp;
(void)argc;
(void)argv;
}

void cmdGetBattery(BaseSequentialStream *chp, int argc, char *argv[]) 
{
        // create working area for new thread

        //set pheriperals

        //create thread

        //wait for callback thread

        //print returned value


(void)chp;
(void)argc;
(void)argv;
}

/*
cmdAdc
	handles the 'adc' command when entered, making sense of the command
	received,  setting up the adc, callback etc.

*/

void cmdAdc(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	int argIncrementer =0;
	int commandSuccess = FALSE;
	//parse input arguments make settings
	if(*argv[0] == '\0')
	{
		//fail, no options given
		commandSuccess =FALSE;
	}
	else if (*(argv[0]+1) == 'o')
	{
		//oneshot 
		argIncrementer++;
		hardwareSetAdcCircular(FALSE);

	}
	else if (*(argv[0]+1) == 'c')
	{
		argIncrementer++;
		hardwareSetAdcCircular(TRUE);
		//cts mode
	}
	else
	{
		hardwareSetAdcCircular(FALSE);

	}
	if (argv[argIncrementer] !='\0')
	{

		int arrayOfPinLocations[NUM_OF_PIN];
		if(!hardwareGetPinLocations(argv[argIncrementer], arrayOfPinLocations))
		{
			if(hardwareSetupPins(arrayOfPinLocations,HW_ADC)) 
			{
				if(hardwareSetAdcChannels(arrayOfPinLocations))
				{
					commandSuccess = TRUE;
				}
			}
			if (commandSuccess == TRUE)
			{
				int i = threadManager();// returns which memory pool we can use
				if (i!=255)
				{
        				threadArray[i] = chThdCreateFromMemoryPool(&mp, NORMALPRIO, adcConversionThread, NULL);
				}
				else
				{
					chprintf(chp, "ran outta threads\n");
				}
			}
		}
	}

}
void cmdError(BaseSequentialStream *chp)
{
	chprintf(chp,"Command not understood.\n");
}

void cmdErrPinFunction(BaseSequentialStream *chp)
{
	chprintf(chp,"Pin Function Error\n");

}
#define BIN 1
#define HEX 2

void cmdInput(BaseSequentialStream *chp, int argc, char *argv[])
{
	// allows skipping of arguments
	int argIncrementer =0;
	int argSuccess=0;
	static int arrayOfPinLocations[NUM_OF_PIN];
	int commandSuccess =FALSE;
	if(argv[argIncrementer]=='\0')
	{
		//no argument given, look for free pins or used the ones used last time
		if(arrayOfPinLocations[0] ==END_PIN)
		{
			//no previosly selected pins, we have to get free pins
			hardwareGetFreePins(&arrayOfPinLocations[0]);
			commandSuccess =TRUE;
		}
		else
		{
			commandSuccess =TRUE;
			//previous pins ok. go team go
		}
	}
	else 
	{
		//look at listed pins
                if(!hardwareGetPinLocations(argv[argIncrementer], arrayOfPinLocations))
                {
			commandSuccess=TRUE;
		}
		else
		{
			cmdError(chp);
		}
	}
	if(commandSuccess)
	{
		if(hardwareSetupPins(&arrayOfPinLocations[0],HW_INPUT))
		{
			int arrayOfValues[NUM_OF_PIN];
                            //           arrayOfPinLocations
			hardwareReadPins(&arrayOfPinLocations[0],arrayOfValues);
			int i =0;
			while (!chBSemGetStateI(&outputResponseDataReady));
			while(i<=NUM_OF_PIN && arrayOfPinLocations[i] != END_PIN)
			{
//				hello();
				outputResponseData.inputPins[i] =arrayOfPinLocations[i]-1;
				outputResponseData.inputValues[i] =arrayOfValues[i];
				i++;
			}

			outputResponseData.caller=HW_INPUT;
			chBSemReset(&outputResponseDataReady, FALSE);
		}
	}

}

void cmdDac(BaseSequentialStream *chp, int argc, char *argv[]) 
{
(void)chp;
(void)argc;
(void)argv;

	//parse arguments
	//initialise dac 

	//initialise dac  pheripheral

	//create thread

	//threadsleep

	//threadwakup

	//thread kill


}

void cmdUart(BaseSequentialStream *chp, int argc, char *argv[]) 
{

(void)chp;
(void)argc;
(void)argv;
	//parse arguments

	//if no arguments supplied, shows current configuration

	//if arguments supplied,  change configuration

	//if  start found, gogogo

}

void cmdSpi(BaseSequentialStream *chp, int argc, char *argv[]) 
{
(void)chp;
(void)argc;
(void)argv;
}

void cmdBluetooth(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parses  Bluetooth arguments

	//if no arguments,  returns status

	//if arguments , changes configuration in memory (restart required)

(void)chp;
(void)argc;
(void)argv;
}



void cmdI2c(BaseSequentialStream *chp, int argc, char *argv[]) 
{
(void)chp;
(void)argc;
(void)argv;
}


void cmdPwm(BaseSequentialStream *chp, int argc, char *argv[]) 
{
(void)chp;
(void)argc;
(void)argv;
}

void cmdDate(BaseSequentialStream *chp, int argc, char *argv[]) 
{
	//parses arguments

	//if  no argument, print system time

	//in argument,  set system time


(void)chp;
(void)argc;
(void)argv;
}


//parses commands for sense. if no sense, prints error to console



 int parseCmdUart(BaseSequentialStream *chp, int argc, char *argv[])
{
(void)chp;
(void)argc;
(void)argv;
	//check if first command is letter or number

	// if letter

	// if number
		//check if valid baud rate
			if(strcmp(argv[0], "-9600")==0)
			{

			}
			else if(strcmp(argv[0], "38400")==0)
			{

			}
			else if(strcmp(argv[0], "56800")==0)
			{

			}
			else if(strcmp(argv[0], "115200")==0)
			{
			}
			else if(strcmp(argv[0], "19200")==0)
			{

			}
			else
			{
				chprintf(chp, "Command not valid");
			}
			
			//set hardware pins on
			//warns if must turn off other programs
	return 0;
			// check if escape argument has been given
}

void cmdConfig(BaseSequentialStream *chp, int argc, char *argv[])
{
(void)chp;
(void)argc;
(void)argv;

}
//cleans up threads, returns pointer to wherenew thread can be made, null iff not

int threadManager(void)
{

	int i=0;// thread iterator
	while(i <2)
	{
//		chprintf((BaseSequentialStream*)&SD1, "it\n");

		if(threadArray[i]==NULL)
		{

//			chprintf((BaseSequentialStream*)&SD1, "op1");
			return i;

		}
		if(checkForMessages(threadArray[i]))
		{
//			hello();
//			chprintf((BaseSequentialStream*)&SD1, "op2");

			//removes thread
			threadArray[i] =NULL;
			return i;

		}
		i++;
	}
//	chprintf((BaseSequentialStream*)&SD1, "op3");


	return 255;
}
//returns true if message was found, false if not indicating a thread can be cleaned up
int checkForMessages(Thread *thdArray)
{
	if(chThdTerminated(thdArray))
	{
		chThdWait(thdArray);
		return TRUE;
	}
	else
	{
		return FALSE;
	}


}


tfunc_t outputResponse(BaseSequentialStream *chp)
{
	outputResponseData.serialString = NULL;
	outputResponseData.adcOutputValues = NULL;
	outputResponseData.numberOfValues = 0;
	outputResponseData.caller = 0;
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
	while(1)
	{
	        chBSemWait(&outputResponseDataReady);
	        if (!chBSemGetStateI(&outputResponseDataReady))
                {
//			chprintf(chp, "semaphore ok");

			int i =0;
			switch(outputResponseData.caller)
			{
				case HW_ADC:;
					while(i <adcSettings.num_channels)
					{
						int valToPrint = (int) (outputResponseData.adcOutputValues[i]);
						chprintf(chp,"%d," ,valToPrint);
						i++;
					}
						chprintf(chp,"\n");
						 chThdSleepMilliseconds(10);
					break;
				case HW_INPUT:
				//	hello();
					while(i<=NUM_OF_PIN)
					{
						//hello();
						if (outputResponseData.inputValues[i])
						{
							chprintf(chp, "%d,",(int)(outputResponseData.inputPins[i]));
						}
						i++;
					}
					chprintf(chp,"\n");
					break;
				case HW_UART:
					chprintf(chp, "Something else \n");
					break;
				case HW_SPI:
					chprintf(chp, "Something else \n");
					break;
				case HW_I2C:
					chprintf(chp, "Something else \n");
					break;
				default:
					chprintf(chp, "default output response \n");
					break;

			}
                        chBSemReset(&outputResponseDataReady, TRUE);
                }

	}
	return FALSE;

}
