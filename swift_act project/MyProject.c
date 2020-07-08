#include "Os.h"
#include "i2c.h"

uint8 elec_heater_flag = 0; // electric heater is closed

void main() {

     /* OFF/ON heater button */
     TRISE.RB5 = 1;

     /* SSD PORTD (PORT OF THE DATA) */
     TRISD = 0;

     /* up and down buttons */
     TRISB.RB0 = 1;
     TRISB.RB1 = 1;

     /* heating element led */
     TRISB.RB2 = 0;
     PORTB.RB2 = 0;

     /* Fan pin */
     TRISC.RC2 = 0;
     PORTC.RC2 = 0;

     /* Heater pin */
     TRISC.RC5 = 0;
     PORTC.RC5 = 0;

     /* start the OS */
     while(RB5_bit == 0)
     {

     }
     elec_heater_flag = 1; // electric heater is opened
     Os_start();


}