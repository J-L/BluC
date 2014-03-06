
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





 const ShellCommand shCmds[] = {
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
