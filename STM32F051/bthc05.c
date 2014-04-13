#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "bthc05.h"


int btSetupSerial(int)
{
	uartStart(&UARTD1, &uart_cfg_1);
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(1));       /* USART1 TX.       */
  	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(1));      /* USART1 RX.       */
	sdStart(&SD3, &uartCfg); 

}

int btPing(BaseSequentialStream chp)
{
	const char btString[] ="AT\r\n;"
	//send char
	//wait for response


}
int btCheckMode(void)
{
	
	return hc05.mode;

}
int btSetMode(int mode)
{
	//check pin value
	if(mode == HC05_TRANSPARENT)
	{
        	palClearPad(GPIOC, GPIOC_LED4);
	}
	else
	{
	        palSetPad(GPIOC, GPIOC_LED4);
	}
	hc05.mode = mode;
	return 0;
}
int btCheckPower(void)
{
	return hc05.power;
}


int btSetPower(int power)
{
	if(power == OFF)
	{
        	palClearPad(GPIOC, GPIOC_LED4);

	}
	else
	{
	        palSetPad(GPIOC, GPIOC_LED4);
	}

	hc05.power = power;
	return 0;
}
int btCheckConnected(int)
{
	

}

int btSetup(BaseSequentialStream *chp);
int btCheckRole(BaseSequentialStream *chp)
{
	const char btString[] ="AT+ROLE=0\r\n;"

}
int btSetRole(BaseSequentialStream *chp)
{
	const char btString[] ="AT+ROLE=0\r\n;"

}
int btFindDevName(BaseSequentialStream *chp);
int btSetPassword(int)
{
	const char btString[] ="AT+PSWD\r\n";

}


int btCheckPassword(BaseSequentialStream *chp)
{
	const char btString[] ="AT+PSWD?\r\n";

}
int btCheckMyName(BaseSequentialStream *chp)
{
	const char btString[] ="AT+NAME?\r\n";
	

}
int btMakeConnection(BaseSequentialStream *chp);
int btBreakConnection(BaseSequentialStream *chp);
int btSetBaudRate(BaseSequentialStream *chp);
int btReset(void)
{
	palClearPad(GPIOC, GPIOC_LED4);
	chThdSleepMilliseconds(50);
	palSetPad(GPIOC, GPIOC_LED4);
	return 0;
	//set reset pin
}

int btSetClass(int);
int btCheckClass(void);
int btCheckStatus(BaseSequentialStream *chp)
{

	return 0;
}
int btResponseCallBack(void)
{
	btParseParameters(void);

}


int btInitialSetup(BaseSequentialStream *chp)
{
	btSetMode(HC05_CONFIGURATION);
	btSetPower(ON);
	btCheckAt();
	btSetBaudRate(chp,115200);
	btSetName(chp);
	btSetPassword(chp);
	btCheckMac(chp);
	btSetRole(chp,SLAVE);
	btSetPower(OFF);
	btSetMode(HC05_TRANSPARENT);

}


int btThread(chp)
{
	while(1)
	{
		btInitialSetup(chp);
		while(hc05.state ==READY)
		{
			//sleep like a mofo
			return 0;
		}
		while(hc05.state == CONNECTED)
		{
			//start shell and listen real close
			return 0;
		}

	}

}


int btParseParameters(BaseSequentialStream *chp, int function)
{
	switch (function)
	{
		case BT_CHECK_MODE:
			break;
		case BT_SET_MODE:
			break;
		case BT_CHECK_POWER:
			break;
		case BT_SET_POWER:
			break;
		case BT_CHECK_STATE:
			break;
		case BT_SET_STATE:
			break;
		case BT_SET_BAUD_RATE:
			break;
		case BT_SET_NAME:
			break;
		case BT_CHECK_NAME:
			break;
		case BT_CHECK_PSWD:
			break;
		case BT_SET_PSWD:
			break;
		case BT_CHECK_MAC:
			break;


	}
	return 0;

}

