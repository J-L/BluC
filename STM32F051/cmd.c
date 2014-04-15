
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
extern int adcSelectedChannels;
extern int adcNumberOfSelectedChannel;
outputResponseStruct outputResponseData;



BSEMAPHORE_DECL(outputResponseDataReady, 0);

void cmdGetTemp(BaseSequentialStream *chp, int argc, char *argv[]) 
{
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
	int commandSuccess = FALSE;
	int arg1 =FALSE;
	int adcMode = 0;
	int adcSampleDivider = 0;
	//parse input arguments make settings
	cmdParseArguments (chp,argc, argv,  CMD_ADC);
	if(*argv[0] == '\0')
	{
		chprintf(chp, "adc status selected");
		arg1 =FALSE;
		commandSuccess =FALSE;
	}
	else if (*(argv[0]+1) == 'o')
	{
		//oneshot 
		adcSettings.circular =FALSE;
		arg1 = TRUE;

	}
	else if (*(argv[0]+1) == 'c')
	{
		arg1 =TRUE;
		adcSettings.circular=TRUE;

		//cts mode
	}
	if (arg1 == TRUE)
	{

		adcSelectedChannels = 0;
		adcNumberOfSelectedChannel =0;
		int i  =1;
		while(argv[1][i] !='\0')
		{
			adcNumberOfSelectedChannel++;
			//if the pin in question has a adc function alowed
			if(hardwareCheckPins(&(argv[1][i]),HW_ADC))
			{
				commandSuccess =TRUE;
				//setting mode on selected pin
				hardwareSetPins(&(argv[1][i]),HW_ADC);
				//or-ing channels to be 

				int adcAddress = hardwareGetAdcAddress(&(argv[1][i]));
				if((adcSelectedChannels & adcAddress) == adcAddress)
				{

					//covers the case where in is already selected
					adcNumberOfSelectedChannel--;
				}
				adcSelectedChannels |= adcAddress;
			}
			else
			{
				//either pin does not exist or adc function does not exist
				adcNumberOfSelectedChannel--;
				cmdErrPinFunction(chp);
				commandSuccess = FALSE;
			}
		//incrementing char
		i++;
		adcSettings.num_channels =adcNumberOfSelectedChannel;
		adcSettings.chselr =adcSelectedChannels;
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
void cmdError(BaseSequentialStream *chp)
{
	chprintf(chp,"Command not understood.\n");
}
#define INPUT 1
#define OUTPUT 2

void cmdErrPinFunction(BaseSequentialStream *chp)
{
	chprintf(chp,"Pin Function Error");

}

void cmdIo(BaseSequentialStream *chp, int argc, char *argv[])
{
	int commandSuccess = FALSE;
	int mode = FALSE;
	int ioNumPins = 0;
	if(*argv[0] == '\0')
	{
		cmdError(chp);
		commandSuccess =FALSE;
	}
	else
	{
		if(argv[0][1] =='o')
		{
			mode = OUTPUT;
			//command is to output

		}
		else if(argv[0][1] =='i')
		{
			mode = INPUT;
			//command set to input
		}
		//mode is set
		if (mode)
		{
			int i = 1;
			commandSuccess =TRUE;
			while(argv[1][i] !='\0')
			{
				ioNumPins++;
				if(hardwareCheckPins(&(argv[1][i]),HW_IO)
				{


				}
				else
				{
					cmdPinErrFunction(chp);
					commandSuccess =FALSE;
					ioNumPins--;
				}


			i++;
			}
		}
	}

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

msg_t *cmdParseArguments (BaseSequentialStream *chp, int argc, char *argv[], int caller)
{
	//removes white space
	int i = 0;
	//checks option list for caller
	switch(caller)
	{
		case CMD_ADC:
			if (*argv[0] == '\0')
			{
				chprintf(chp, "adc status selected");
				break;
			}
			else
			{
			}
			break;
                case CMD_DAC:
			if(*argv[0] == '\0')
			{
				//check on dacs setup
			}
			else
			{	
				chprintf(chp,"dac setup chosen");
			}
                        break;
                case CMD_PWM:
                        break;
                case CMD_DATE:
                        break;
                case CMD_UART:
                        if(*argv[0] == '\0')
                        {
                                //check on uarts setup
                        }
                        else if (*argv[0] == '-')
                        {
                                chprintf(chp,"UART setup chosen");
                        }
			else
			{
				//if uart setup
					//create thread to send it
				//else  remind uart is not setup
			}
                        break;
                case CMD_SPI:
                        break;
                case CMD_I2C:
                        break;
                case CMD_BLUETOOTH:
			if (*argv[0] =='\0')
			{
				chprintf(chp,"name:");
				chprintf(chp,",password:");
				chprintf(chp,",status:");
				chprintf(chp,",address:");

			}
			else
			{
			}
                        break;
                case CMD_IO:
                        break;
	}
	//checks


}


static int parseCmdUart(BaseSequentialStream *chp, int argc, char *argv[])
{
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
			// check if escape argument has been given
}

static int parseCmdDac(BaseSequentialStream *chp, int argc, char *argv[])
{


}

static int parseCmdPwm(BaseSequentialStream *chp, int argc, char *argv[])
{


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
					chprintf(chp,"%d:",adcNumberOfSelectedChannel);
					while(i <adcNumberOfSelectedChannel)
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

}
