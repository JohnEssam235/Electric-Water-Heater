#include "Os.h"
#include "i2c.h"
#include "common_macros.h"

uint8 elec_heater_flag = 0;
uint8 temp1;
uint8 temp2;
void main() {
     uint8 current_one;
     EEPROM_init();
     //EEPROM_writeByte(0,2);
     //EEPROM_writeByte(0,3);
     delay_ms(10);

     //ANSELA = 0x04;              // Configure AN2 pin as analog

     /* OFF/ON heater button */
     TRISB.RB0 = 1;
     SET_BIT(INTCON,7);   // bit7 is the global interrupt (GIE)
     SET_BIT(INTCON,6);    // peripheral

     /* SSD PORTD (PORT OF THE DATA) */
     TRISD = 0;
     TRISA.RA4 = 0; // select of second display
     TRISA.RA5 = 0; // select of first display


     /* up and down buttons */
     TRISB.RB1 = 1;  // up
     TRISB.RB2 = 1;  // down


     /* heating element led */
     TRISB.RB7 = 0;
     PORTB.RB7 = 0;

     /* Fan pin */
     TRISC.RC2 = 0;
     PORTC.RC2 = 0;

     /* Heater pin */
     TRISC.RC5 = 0;
     PORTC.RC5 = 0;
     
     //sensor pin and ADC
     //ADCON0 = 0x51;    // Turn ADC ON, Select AN2 Channel, ADC Clock = Fosc/8
    //ADCON1 = 0x80;  // All 8 Channels Are Analog, Result is "Right-Justified"
                    // ADC Clock = Fosc/8
     ADCON0 = 0x91;
     ADCON1 = 0xC0;
     
      TRISB.RB6 = 0;
      PORTB.RB6 = 1;
     while(RB0_bit == 1);
     elec_heater_flag = 1;
     delay_ms(300);
     current_one = EEPROM_readByte(2);
     if(current_one == 0)
     {
        temp1 = 6;
        temp2 = 0;
     }
     else
     {
        temp1 = EEPROM_readByte(2);
        temp2 = EEPROM_readByte(3);
     }
     Os_start();


}