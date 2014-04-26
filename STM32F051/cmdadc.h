/*

*/

#define ADCTEMPCHANNELS   1
#define ADCTEMPBUFFER      8
void hardwareAdcCallBack(ADCDriver *, adcsample_t *, size_t);
void hardwareAdcErrorCallBack(ADCDriver *, adcerror_t);
tfunc_t hardwareAdcConversionThread( void );



