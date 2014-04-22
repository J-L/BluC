
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
	int commandSuccess = FALSE;
	int arg1 =FALSE;
	//parse input arguments make settings
	if(*argv[0] == '\0')
	{

		arg1 =FALSE;
		commandSuccess =FALSE;
	}
	else if (*(argv[0]+1) == 'o')
	{
		//oneshot 
		hardwareSetAdcCircular(FALSE);
		arg1 = TRUE;

	}
	else if (*(argv[0]+1) == 'c')
	{
		arg1 =TRUE;
		hardwareSetAdcCircular(TRUE);
		//cts mode
	}
	if (arg1 == TRUE && argv[1] !='\0')
	{

		int arrayOfPinLocations[10];
		hardwareGetPinLocations(argv[1], arrayOfPinLocations);
		if(hardwareSetupPins(arrayOfPinLocations,HW_ADC)) 
		{
			if(hardwareSetAdcChannels(arrayOfPinLocations))
			{
				chprintf(chp, "ran outta threadsfjhfkg\n");
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
(void)argc;
	int commandSuccess = FALSE;
//	int logic = FALSE;
	int mode = FALSE;
	int ioNumPins = 0;
	//itype, otype refer to the type of input or output high z or push pull output
	int i_type = HW_INPUT;
	int o_type =HW_PP;
	if(*argv[0] == '\0')
	{
		cmdError(chp);
		commandSuccess =FALSE;
	}
	else
	{

		if(argv[0][1] =='o')
		{
			mode = HW_OUTPUT;
			//command is to output


		}
		else if(argv[0][1] =='i')
		{
			mode = HW_INPUT;
			//command set to input
		}
		//mode is set
		if(argv[0][2] =='b')
		{
		}
		if (mode)
		{
			if(argv[1][0] == '\0')
			{
				argv[1] = "-01234567\0";
			}

			commandSuccess =TRUE;
			if( mode == HW_INPUT)
			{
//				hardwareSetupPins((argv[1]),i_type);
			}
			else if( mode == HW_OUTPUT)
			{
//				hardwareSetupPins((argv[1]),o_type);
			}
			else
			{
				cmdErrPinFunction(chp);
				ioNumPins--;
			}
		}
		hello();
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
			switch(outputResponseData.caller)
			{
				case HW_ADC:;
					int i = 0;
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
					chprintf(chp, "Something else \n");
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
