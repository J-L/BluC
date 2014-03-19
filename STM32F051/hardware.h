/*
this file contains definitions  and mapping between the mcu and the board pertaining to which pin is where and which functions are possible on which pins et

*/
struct pinUse;


#define INPUT 0x01
#define OUTPUT 0x02
#define ADC 0x04
#define DAC 0x08
#define UART 0x10
#define SPI 0x20
#define I2C 0x40
#define PWM 0x80

#define PIN_0 0x01
#define PIN_1 0x02
#define PIN_2 0x04
#define PIN_3 0x08
#define PIN_4 0x10
#define PIN_5 0x20
#define PIN_6 0x40
#define PIN_7 0x80


struct pinSetting {
	int pinPort;
	int pinNumber;
	int pinOptions;
};
/*
pin[0].pinPort = GPIOA;
pin[0].pinNumber = 0;
pin[0].pinOptions = INPUT | OUTPUT |ADC |DAC |UART;
*/
struct pinSetting pinCapabilities[8];
   //      pinCapabilities

int hardwareSetPins(int,int);
int hardwareCheckPins(int,int);

//pwm acceptable pins
//adc pins
//dac accessible pins
//uart pins
//spi pins
//io pins


//register pin use


//check hardware use

