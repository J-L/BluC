void cmdGetTemp(BaseSequentialStream *, int , char *[]);


 const ShellCommand shCmds[] = {
	{"temp",  (shellcmd_t)  cmdGetTemp},
	{NULL, NULL}
};

static const ShellConfig shCfg = {
    (BaseSequentialStream *)&SD1,
    shCmds
};
