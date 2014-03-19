
#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "shell.h"
#include "adc.h"
#include "cmdadc.h"
int value;
adcsample_t samples[8];
size_t nx = 0, ny = 0;
BSEMAPHORE_DECL(adcSemDataReady, 0);

#define ADC_GRP1_NUM_CHANNELS   1
#define ADC_GRP1_BUF_DEPTH      1

#define ADC_GRP2_NUM_CHANNELS   4
#define ADC_GRP2_BUF_DEPTH      16


ADCConversionGroup adcSettings = {
    TRUE,
    ADCTEMPCHANNELS,
    adcCallBack,
    adcErrorCallBack,
    ADC_CFGR1_RES_12BIT,                              /* CFGRR1 */
    ADC_TR(0, 0),                                     /* TR */
    ADC_SMPR_SMP_28P5,
    ADC_CHSELR_CHSEL1                                /* CHSELR */
};



void hello(void)
{
	chprintf((BaseSequentialStream*)&SD1, "HelloWorld");
}

void adcCallBack(ADCDriver *adcp, adcsample_t *buffer, size_t n)
{
	(void)adcp;
	if (samples == buffer) 
	{
		nx += n;
  	}
	else 
	{
		ny += n;
	}

		chSysLockFromIsr();
		if (chBSemGetStateI(&adcSemDataReady))
		{
			chBSemResetI(&adcSemDataReady, FALSE);
		}
		chSysUnlockFromIsr();
	
}


void adcErrorCallBack(ADCDriver *adcp, adcerror_t err) 
{
	(void)adcp;
	(void)err;
}



msg_t adcConversionThread(void) 
{
	adcStart(&ADCD1, NULL);
  	adcStartConversion(&ADCD1, &adcSettings, &samples, 8);

  
}
