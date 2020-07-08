#include "Os.h"
#include "i2c.h"
void main() {

     /* OFF/ON heater button */
     TRISE.RE0 = 1;

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
     Os_start();


}