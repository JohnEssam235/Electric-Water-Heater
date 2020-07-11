#include"adc.h"

//------------[ AD Converter Routines ]--------------
void ADC_Init1()
{
   // ADCON0 = 0x41;  // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8
      ADCON0 = 0x51;    // Turn ADC ON, Select AN2 Channel, ADC Clock = Fosc/8
    ADCON1 = 0x80;  // All 8 Channels Are Analog, Result is "Right-Justified"
                    // ADC Clock = Fosc/8
}
uint16 ADC_readChannel(uint8 channel_num)
{
    if(channel_num<0 || channel_num>7)    // Check Channel Number Validity
    { return 0;}
    ADCON0 &= 0x11000101; // Clear The Channel Selection Bits
    ADCON0 |= channel_num<<3;     // Select The Required Channel (ANC)
                          // Wait The Aquisition Time

     delay_us(30);      // The Minimum Tacq = 20us, So That should be enough
    GO_DONE_bit= 1;          // Start A/D Conversion
    while(GO_DONE_bit); // Polling GO_DONE Bit
                               // Provides Delay Until Conversion Is Complete
    return ((ADRESH << 8) + ADRESL); // Return The Right-Justified 10-Bit Result
    
}