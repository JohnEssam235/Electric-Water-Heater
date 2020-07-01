#include "adc.h"
 //// to read data
uint16 ADC_readChannel(uint8 channel_num){
return ADC_Read(channel_num);
}
