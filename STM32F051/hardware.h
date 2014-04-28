/*
this file contains definitions  and mapping between the mcu and the board pertaining to which pin is where and which functions are possible on which pins et

*/
struct pinUse;



#define HW_NONE 0x00
#define HW_INPUT 0x01
#define HW_OUTPUT 0x02
#define HW_ADC 0x04
#define HW_DAC 0x08
#define HW_UART 0x10
#define HW_SPI 0x20
#define HW_I2C 0x40
#define HW_PWM 0x80
#define HW_PU 0x200
#define HW_PD 0x400
#define HW_OD 0x800
#define HW_PP 0x1000


#define END_PIN 0
#define PIN_0 1
#define PIN_1 2
#define PIN_2 3
#define PIN_3 4
#define PIN_4 5
#define PIN_5 6
#define PIN_6 7
#define PIN_7 8
#define ERR_PIN 255
#define ERR_CMD 254
#define NUM_OF_PIN 8

//const char* uartBaudRates[7]={"9600\0","14400","19200","38400","57600","115200","234000"};
#define SERIAL_NUM_BAUD_RATES 7
#define SERIAL_BAUD_9600 0
#define SERIAL_BAUD_14400 1
#define SERIAL_BAUD_19200 2
#define SERIAL_BAUD_38400 3
#define SERIAL_BAUD_57600 4
#define SERIAL_BAUD_115200 5
#define SERIAL_BAUD_23400 6

#define SERIAL_NUM_ENCODING 7
#define SERIAL_ENCODING_8N1 0

typedef struct {
	GPIO_TypeDef * pinPort;
	int pinNumber;
	int pinOptions;
	int pinAdcAddress;
	int pinTimerAddress;
	int currentSetting;
}pinSetting;

void hello(void);
void hardwareInitialise(void);
int hardwareSetupPins(int *,int);
int hardwareSetupPin(int,int);
int hardwareCheckPins(int *,int );
int hardwareCheckPin(int,int);
int hardwareGetPinLocations(char *,int *);
int hardwareParseDecimalPins(char *,int *);
int hardwareReadPins(int *);
int hardwareGetFreePins(int *);
int hardwareGetCurrentMode(int);
hardwareSetPins(int *, int * );

int hardwareAdcSetCircular(int );
int hardwaretAdcSetAddress(int);
int hardwareAdcSetChannels(int *);
int * hardwareIoGetPort(int);
int hardwareIoGetPin(int);

tfunc_t hardwareSerialTransparentThread(void);
/*
static  const ShellCommand shCmds[] = {
        {"temp",  (shellcmd_t)  cmdGetTemp},
        {"voltage",  (shellcmd_t)  cmdGetVoltage},
        {"battery",  (shellcmd_t)  cmdGetBattery},
        {"bluetooth",  (shellcmd_t)  cmdBluetooth},
        {"pwm",  (shellcmd_t)  cmdPwm},
        {"input",  (shellcmd_t)  cmdInput},
        {"output",  (shellcmd_t)  cmdOutput},
        {"spi",  (shellcmd_t)  cmdSpi},
        {"uart",  (shellcmd_t)  cmdUart},
        {"i2c",  (shellcmd_t)  cmdI2c},
        {"date",  (shellcmd_t)  cmdDate},
        {"adc",  (shellcmd_t)  cmdAdc},
        {"dac",  (shellcmd_t)  cmdDac},
        {"config",  (shellcmd_t)  cmdConfig},
        {NULL, NULL}
};

static const ShellConfig shCfg = {
    (BaseSequentialStream *)&SD1,
    shCmds
};

*/


/*
int hardwareSerialSetBaudRate(char *);
int hardwareSerialSetEncoding(char *);
int hardwareSerialRxCallback(UARTDriver *, uint16_t );
int hardwareSerialRxBufferFull(UARTDriver *);
int hardwareSerialTxBufferRead(UARTDriver *);
int hardwareSerialTxBufferRead2(UARTDriver *);
*/


//pwm acceptable pins
//adc pins
//dac accessible pins
//uart pins
//spi pins
//io pins


//register pin use


//check hardware use

