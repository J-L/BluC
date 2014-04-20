/*

*/


#define ADCTEMPCHANNELS   1
#define ADCTEMPBUFFER      8




void adcCallBack(ADCDriver *, adcsample_t *, size_t);
void adcErrorCallBack(ADCDriver *, adcerror_t);
tfunc_t adcConversionThread( void );




