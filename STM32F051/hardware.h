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
#define NUM_OF_PIN 8

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

int hardwareSetAdcCircular(int );
int hardwareGetAdcAddress(int);
int hardwareSetAdcChannels(int *);
int * hardwareGetIoPort(int);
int hardwareGetIoPin(int);


//pwm acceptable pins
//adc pins
//dac accessible pins
//uart pins
//spi pins
//io pins


//register pin use


//check hardware use

