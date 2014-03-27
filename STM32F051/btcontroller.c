extern MemoryPool mp;

int btSetupSpi(void)
{
	 palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(0) |
                           PAL_STM32_OSPEED_HIGHEST);       /* New SCK.     */
	palSetPadMode(GPIOB, 14, PAL_MODE_ALTERNATE(0) |
                           PAL_STM32_OSPEED_HIGHEST);       /* New MISO.    */
	palSetPadMode(GPIOB, 15, PAL_MODE_ALTERNATE(0) |
                           PAL_STM32_OSPEED_HIGHEST);       /* New MOSI.    */
	palSetPad(GPIOB, 12);
	palSetPadMode(GPIOB, 12, PAL_MODE_OUTPUT_PUSHPULL |
                           PAL_STM32_OSPEED_HIGHEST);       /* New CS.      */
	hread *adcThread = chThdCreateFromMemoryPool(&mp, NORMALPRIO, btStateMachine, NULL);


}

#define BT_INIT 0x01
#define BT_DISCOVERABLE 0x02
#define BT_CONNECTING 0x03
#define BT_CONNECTED 0x04
#define BT_DISCONNECTED 0x05

int btStateMachine(void)
{
	//start spi

	//initialize Bluetooth

	while (1)
	{
	


	}



}
int btDiscoverabilityMode(void)
{
	while(1)
	{
		//set up bluetooth chip into discoverable mode
		
		//wait for response
		


	}


}


int btCheckMode(void);
int btSetMode(int);
int btCheckPower(void);
int btSetPower(int);
int btCheckConnected(int);
int btSetup(int);
int btCheckRole(void);
int btSetRole(int);
int btSearchDevices(void);
int btFindDevName(int);
int btSetPassword(int);
int btCheckPassword(int);
int btCheckMyName(void);
int btMakeConnection(void);
int btBreakConnection(void);
int btSetBausRate(void);
int btCheckBaudRate(void);
int btSetInquiryMode(int);
int btReset(int);
int btSetClass(int);
int btCheckClass(void);
int btCheckStatus(void);

