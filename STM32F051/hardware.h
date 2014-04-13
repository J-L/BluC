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

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7


typedef struct {
	GPIO_TypeDef * pinPort;
	int pinNumber;
	int pinOptions;
	int pinAdcAddress;
	int pinTimerAddress;
	int currentSetting;
}pinSetting;


void hardwareInitialise(void);
int hardwareSetPins(char *,int);
int hardwareCheckPins(char *,int);
int hardwarePinInterpret(char *);
int hardwarePinParse(char *);
int hardwareGetAdcAddress(char *);
//pwm acceptable pins
//adc pins
//dac accessible pins
//uart pins
//spi pins
//io pins


//register pin use


//check hardware use

