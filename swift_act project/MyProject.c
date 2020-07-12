#include "Os.h"
#include "i2c.h"
#include "common_macros.h"

uint8 elec_heater_flag = 0;  // global variable for flaging if the button heater is pressed or not
uint8 temp1;                 // two global variables for the temperature
uint8 temp2;

void main() {


     uint8 current_state;  // variable to determine if its the first time or not
     EEPROM_init();
     /*EEPROM_writeByte(0,2);      // these two lines are used to reset the electric heater
     EEPROM_writeByte(0,3); */
     delay_ms(10);

     /* OFF/ON heater button */
     TRISB.RB0 = 1;

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

     while(RB0_bit == 1);   // if heater button is pressed
     delay_ms(200);
     elec_heater_flag = 1;
     current_state = EEPROM_readByte(2);
     if(current_state == 0)
     {
        temp1 = 6;
        temp2 = 0;
     }
     else
     {
        temp1 = EEPROM_readByte(2);
        temp2 = EEPROM_readByte(3);
     }
     Os_start();   // after reading the last setted temperature ... start the OS


}