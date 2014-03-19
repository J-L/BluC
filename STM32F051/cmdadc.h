/*

*/


#define ADCTEMPCHANNELS   1
#define ADCTEMPBUFFER      8




extern int adcDataReady;
extern ADCConversionGroup adcsettings;

void hello(void);
void adcCallBack(ADCDriver *, adcsample_t *, size_t);
void adcErrorCallBack(ADCDriver *, adcerror_t);
msg_t adcConversionThread( void );




