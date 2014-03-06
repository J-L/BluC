
#include "ch.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"
#include "cmdadc.h"
extern int adcDataReady;        




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
	chprintf((BaseSequentialStream*)&SD1, "DOOOOOONE");
}

void cmdGetVoltage(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdGetBattery(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

/*
cmdAdc
	handles the 'adc' command when entered, making sense of the command
	received,  setting up the adc, callback etc.

*/

void cmdAdc(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdPwm(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdUart(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdSpi(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}

void cmdBluetooth(BaseSequentialStream *chp, int argc, char *argv[]) 
{
    chprintf(chp, "Hello World");  

}
