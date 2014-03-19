
#include "ch.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"
#include "cmdadc.h"
#include "cmd.h"
#include  <string.h>

extern int value;
extern ADCConversionGroup adcSettings;
extern MemoryPool mp;
extern adcsample_t samples;
extern BinarySemaphore adcSemDataReady;
char error[] = "Error Parsing String";



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
	//parse input arguments make settings
	cmdParseArguments (chp,argc, argv,  CMD_ADC);

        Thread *adcThread = chThdCreateFromMemoryPool(&mp, NORMALPRIO, adcConversionThread, NULL);

        //this should be replaced with a thread wait for message
	//setup adc conversion arguments

	//create thread




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
 				return parseCmdAdc (chp,argc, argv);
			}
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

ADCConversionGroup *parseCmdAdc (BaseSequentialStream *chp, int argc, char *argv[])
{
	// find first argument
	int adcMode = 0;
	int adcSelectedChannels = 0;
	int adcNumberOfSelectedChannel = 0;
	int adcSampleDivider = 0;
	// check if continuous os one shot
	if (*(argv[0]+1) =='c')
	{
		chprintf(chp, "Continuous Mode\n");
		adcMode = TRUE;
		//continuous
	}
	else if ( *(argv[0]+1)  == 'o')
	{
		chprintf(chp, "One Shot\n");

	}
	else
	{
		return FALSE;
	}
	// while characters in channel selection argument
	int i =1;
	int adcChannelAdded =0;
	while (*(argv[1]+i) != '\0')
	{
		//switch for charcter	
		switch (*(argv[1]+i))
		{
					chprintf(chp, "Channels Selected:");
				case '1':
			    		adcChannelAdded =ADC_CHSELR_CHSEL1;                                /* CHSELR */
					adcNumberOfSelectedChannel++;
					chprintf(chp, "1,");
					break;
				case '2':
					adcChannelAdded =ADC_CHSELR_CHSEL2;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "2,");
					break;
				case '3':
					adcChannelAdded =ADC_CHSELR_CHSEL3;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "3,");
					break;
				case '4':
					adcChannelAdded =ADC_CHSELR_CHSEL4;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "4,");
					break;
				case '5':
                                        adcChannelAdded=ADC_CHSELR_CHSEL5;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "5,");
					break;
				case '6':
                                        adcChannelAdded =ADC_CHSELR_CHSEL6;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "6,");
					break;
                                case '7':
                                        adcChannelAdded =ADC_CHSELR_CHSEL7;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "7,");
                                        break;
                                case '8':
                                        adcChannelAdded =ADC_CHSELR_CHSEL8;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "8,");
                                        break;
                                case '9':
                                        adcChannelAdded =ADC_CHSELR_CHSEL9;                                /* CHSELR */
                                        adcNumberOfSelectedChannel++;
					chprintf(chp, "9,");
                                        break;
				default:
					return FALSE;
				//not a valid  charc
		}
		if ((adcSelectedChannels && adcChannelAdded)!= adcChannelAdded)
		{
			adcSelectedChannels |= adcChannelAdded;
		}
		i++;
	}
/*
define ADC_SMPR_SMP_1P5        0   < @brief 14 cycles conversion time   
#define ADC_SMPR_SMP_7P5        1   < @brief 21 cycles conversion time.  
#define ADC_SMPR_SMP_13P5       2   < @brief 28 cycles conversion time.  
#define ADC_SMPR_SMP_28P5       3   < @brief 41 cycles conversion time.  
#define ADC_SMPR_SMP_41P5       4   < @brief 54 cycles conversion time.  
#define ADC_SMPR_SMP_55P5       5   < @brief 68 cycles conversion time.  
#define ADC_SMPR_SMP_71P5       6   < @brief 84 cycles conversion time.  
#define ADC_SMPR_SMP_239P5      7   < @brief 252 cycles conversion time. 	
*/	
	if (*(argv[2])=='\0')
	{
		chprintf(chp, "default frequency");
	}
	else if (strcmp(argv[2], "-1MHz") ==0)
	{
		chprintf(chp, "true");

	}
        else if (strcmp(argv[2], "-666kHz") ==0)
        {
                chprintf(chp, "true");

        }
        else if (strcmp(argv[2], "-500kHz") ==0)
        {
                chprintf(chp, "true");

        }
        else if (strcmp(argv[2], "-341kHz") ==0)
        {
                chprintf(chp, "true");

        }
        else if (strcmp(argv[2], "-259kHz") ==0)
        {
                chprintf(chp, "true");

        }
        else if (strcmp(argv[2], "-206kHz") ==0)
        {
                chprintf(chp, "true");

        }
        else if (strcmp(argv[2], "-167kHz") ==0)
        {
                chprintf(chp, "true");

        }
        adcSettings.circular=adcMode;
        adcSettings.num_channels=adcNumberOfSelectedChannel;
	return &adcSettings;
	//looks at frequency argument (if exists)
	// looks at output pointer (if exists)
	//sets output pins, warn is not ok.
	

}

static int parseCmdUart(BaseSequentialStream *chp, int argc, char *argv[])
{
	//check if first command is letter or number

	// if letter

	// if number
		//check if valid baud rate
			//set hardware pins on
			//warns if must turn off other programs
			// check if escape argument has been given
}

/*
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
*/

void outputResponse(void)
{
	while(1)
	{
        chBSemWait(&adcSemDataReady);	

	        if (chBSemGetStateI(&adcSemDataReady))
                {
                        chBSemResetI(&adcSemDataReady, FALSE);
                }	

	}

}
