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
#line 4 "D:/swift_act project/MyProject.c"
uint8 elec_heater_flag = 0;

void main() {


 TRISE.RB5 = 1;


 TRISD = 0;


 TRISB.RB0 = 1;
 TRISB.RB1 = 1;


 TRISB.RB2 = 0;
 PORTB.RB2 = 0;


 TRISC.RC2 = 0;
 PORTC.RC2 = 0;


 TRISC.RC5 = 0;
 PORTC.RC5 = 0;


 while(RB5_bit == 0)
 {

 }
 elec_heater_flag = 1;
 Os_start();


}
