/*
Header file includes declarations responsible for managing the bluetooth chip



*/



/*
btcheckmode:
	returns current status of bluetooth chip, at least as far as the mcu is
	aware.
	returns 0 if pin is set to configuration mode
	returns 1 if set to pass through mode
*/



/*
btsetmode:
in	sets pin on mcu responsible for config/passthrough mode
	returns 0 if successful
*/



/*
btcheckpower:
	returns status of bluetooths power
*/

/*
btsetpower:
	sets power pin on bluetooth chip according to passed variable
*/

/*
btsetup:
	uses struct to intialise bluetooth chip
*/

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




