
#define CMD_TEMP	0x0
#define CMD_VOLT	0x1
#define CMD_BATT	0x2
#define CMD_BLUE	0x3
#define CMD_ADC		0x4
#define CMD_DAC		0x5
#define CMD_PWM		0x6
#define CMD_I2C		0x7
#define CMD_SPI		0x8
#define CMD_DATE	0x9
#define CMD_WRITE	0xA
#define CMD_IF		0XB
#define CMD_SLEEP	0xC
#define CMD_WHILE	0xD
#define CMD_FOR		0xF
#define CMD_DEFINE	0x11
#define CMD_BREAK	0x12
#define CMD_KILL	0x13
#define CMD_IO		0x14
#define CMD_MAN		0x15
#define CMD_UART	0x16
#define CMD_BLUETOOTH	0x17

	






//base functionality
void cmdGetTemp(BaseSequentialStream *, int , char *[]);
void cmdGetVoltage(BaseSequentialStream *, int , char *[]);
void cmdGetBattery(BaseSequentialStream *, int , char *[]);
void cmdBluetooth(BaseSequentialStream *, int , char *[]);
void cmdAdc(BaseSequentialStream *, int , char *[]);
void cmdDac(BaseSequentialStream *, int , char *[]);
void cmdPwm(BaseSequentialStream *, int , char *[]);
void cmdUart(BaseSequentialStream *, int , char *[]);
void cmdI2c(BaseSequentialStream *, int , char *[]);
void cmdSpi(BaseSequentialStream *, int , char *[]);
void cmdDate(BaseSequentialStream *, int , char *[]);
void cmdWrite(BaseSequentialStream *, int , char *[]);
void cmdRead(BaseSequentialStream *, int , char *[]);

//Extended functionality
void cmdSleep(BaseSequentialStream *, int , char *[]);
void cmdIf(BaseSequentialStream *, int , char *[]);
void cmdWhile(BaseSequentialStream *, int , char *[]);
void cmdFor(BaseSequentialStream *, int , char *[]);
void cmdDefine(BaseSequentialStream *, int , char *[]);
void cmdBreak(BaseSequentialStream *, int , char *[]);

//helper functions (static), not used  elsewhere
ADCConversionGroup *parseCmdAdc (BaseSequentialStream *, int, char *[]);
msg_t *cmdParseArguments (BaseSequentialStream *chp, int argc, char *argv[], int caller);

static  const ShellCommand shCmds[] = {
	{"temp",  (shellcmd_t)  cmdGetTemp},
	{"voltage",  (shellcmd_t)  cmdGetVoltage},
	{"battery",  (shellcmd_t)  cmdGetBattery},
	{"bluetooth",  (shellcmd_t)  cmdBluetooth},
	{"pwm",  (shellcmd_t)  cmdPwm},
	{"spi",  (shellcmd_t)  cmdSpi},
	{"i2c",  (shellcmd_t)  cmdI2c},
	{"date",  (shellcmd_t)  cmdDate},
	{"adc",  (shellcmd_t)  cmdAdc},
	{"dac",  (shellcmd_t)  cmdDac},
	{NULL, NULL}
};

static const ShellConfig shCfg = {
    (BaseSequentialStream *)&SD1,
    shCmds
};
