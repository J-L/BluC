
static SerialConfig uartCfg =
{
38400, // bit rate
};



int btSetupSerial(int)
{
	uartStart(&UARTD1, &uart_cfg_1);
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(1));       /* USART1 TX.       */
  	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(1));      /* USART1 RX.       */
	sdStart(&SD3, &uartCfg); 

}

int btCheckMode(void)
{
	
	return hc05Mode;

}
int btSetMode(int mode)
{
	//check pin value

	// set pin value
	//set mode
	hc05Mode = mode;
	return 0;
}
int btCheckPower(void)
{
	return hc05Power;
}


int btSetPower(int power)
{
	//check power setting 
	//set power setting

	hc05Power = power;
	return 0;
}
int btCheckConnected(int)
{
	

}
int btSetup(BaseSequentialStream *chp);
int btCheckRole(BaseSequentialStream *chp);
int btSetRole(BaseSequentialStream *chp)
{
	const char btString[] ="AT+ROLE=0\r\n"

}
int btFindDevName(BaseSequentialStream *chp);
int btSetPassword(int)
{
	const char btString[] ="AT+PSWD\r\n"

}


int btCheckPassword(BaseSequentialStream *chp)
{
	const char btString[] ="AT+PSWD?\r\n"

}
int btCheckMyName(BaseSequentialStream *chp)
{
	const char btString[] ="AT+NAME?\r\n"
	

}
int btMakeConnection(BaseSequentialStream *chp);
int btBreakConnection(BaseSequentialStream *chp);
int btSetBaudRate(BaseSequentialStream *chp);
int btReset(int)
{
	//set reset pin
}

int btSetClass(int);
int btCheckClass(void);
int btCheckStatus(BaseSequentialStream *chp)
{

	if
}
int btResponseCallBack(void)
{
	btParseParameters(void);

}


int btInitialSetup(aseSequentialStream *chp)
{
	btSetMode(HC05_CONFIGURATION);
	btSetPower(ON);
	btCheckAt();
	btSetBaudRate(115200);
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
		}
		while(hc05.state == CONNECTED)
		{
			//start shell and listen real close

		}
	
	}

}


int btParseParameters(chp, int function)
{
	case (function)
	{
		switch HC05_CHECK_MODE:
		switch HC05_SET_MODE:
		switch HC05_CHECK_POWER:
		switch HC05_SET_POWER:
		switch HC05_CHECK_STATE::
		switch HC05_SET_STATE:
		switch HC05_SET_BAUD_RATE:
		switch HC05_SET_NAME:
		switch HC05_CHECK_NAME:
		switch HC05_CHECK_PSWD:
		switch HC05_SET_PSWD:
		switch HC05_CHECK_MAC::






	}

}

