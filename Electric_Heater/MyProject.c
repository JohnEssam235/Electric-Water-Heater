#include "Os.h"
#include "EEPROM.h"
#include "common_macros.h"

uint8 elec_heater_flag = 0;  // global variable for flaging if the button heater is pressed or not
uint8 temp1;                 // two global variables for the temperature
uint8 temp2;

void main() {


     uint8 current_state;  // variable to determine if its the first time or not
     EEPROM_init();
     /*EEPROM_writeByte(0xFF,2);      // these two lines are used to reset the electric heater temperature
     EEPROM_writeByte(0XFF,3); */     // if you uncomment these two lines so the temp. will be set again
     delay_ms(10);                    // to 60(as you bought the heater for the first time)
                                      // so every time you load the the hex file to the picgenios or turning off/on
                                      // the heater ,the displayed temp will be the last set temp.
                                      // so if you want to reset the whole system as it operates for the first time
                                      // you have to uncomment these two lines and build and load it to the picgenios
                                      // and after that uncomment them and build and the heater will be operated
                                      // as it is the first time :)

                                      // when you turn off and then on the heater it will display the last
                                      // set temp. .... you dont have to uncomment these two lines of course
                                      // but if you want to reset the system at all uncomment them and make
                                      // what i have said :)
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
     if(current_state == 0xFF)
     {
        temp1 = 6;
        temp2 = 0;
        EEPROM_writeByte(6,2);
        EEPROM_writeByte(0,3);
     }
     else
     {
        temp1 = EEPROM_readByte(2);
        temp2 = EEPROM_readByte(3);
     }
     Os_start();   // after reading the last setted temperature ... start the OS


}