#line 1 "D:/swift_act project/MyProject.c"
#line 1 "d:/swift act files/os.h"
#line 1 "d:/swift act files/std_types.h"
#line 20 "d:/swift act files/std_types.h"
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned int uint16;
typedef signed int sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
#line 15 "d:/swift act files/os.h"
void Os_start(void);


void Os_scheduler(void);


void Os_newTimerTick(void);
#line 1 "d:/swift act files/i2c.h"
#line 1 "d:/swift act files/std_types.h"
#line 15 "d:/swift act files/i2c.h"
void EEPROM_init(void);
void EEPROM_writeByte(unsigned short my_data,uint8 add);
uint8 EEPROM_readByte(uint8 add);
#line 1 "d:/swift act files/common_macros.h"
#line 5 "D:/swift_act project/MyProject.c"
uint8 elec_heater_flag = 0;
uint8 temp1;
uint8 temp2;

void main() {


 uint8 current_state;
 EEPROM_init();
#line 16 "D:/swift_act project/MyProject.c"
 delay_ms(10);


 TRISB.RB0 = 1;


 TRISD = 0;
 TRISA.RA4 = 0;
 TRISA.RA5 = 0;



 TRISB.RB1 = 1;
 TRISB.RB2 = 1;



 TRISB.RB7 = 0;
 PORTB.RB7 = 0;


 TRISC.RC2 = 0;
 PORTC.RC2 = 0;


 TRISC.RC5 = 0;
 PORTC.RC5 = 0;

 while(RB0_bit == 1);
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
 Os_start();


}
