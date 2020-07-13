#line 1 "D:/swift act files/gpt.c"
#line 1 "d:/swift act files/gpt.h"
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
#line 7 "d:/swift act files/gpt.h"
void Timer1_start(uint8 my_tick);
#line 1 "d:/swift act files/os.h"
#line 1 "d:/swift act files/std_types.h"
#line 15 "d:/swift act files/os.h"
void Os_start(void);


void Os_scheduler(void);


void Os_newTimerTick(void);
#line 5 "D:/swift act files/gpt.c"
static uint8 count = 0;
#line 12 "D:/swift act files/gpt.c"
void Timer1_start(uint8 my_tick)
{

 TMR1L = 0;
 TMR1H = 0;
 T1CKPS0_bit = 0;
 T1CKPS1_bit = 0;
 TMR1CS_bit = 0;
 TMR1ON_bit = 1;


 CCPR1 = my_tick;

 CCP1CON = 0x0B;

 CCP1IE_bit = 1;
}
#line 37 "D:/swift act files/gpt.c"
void interrupt()
{

 if(CCP1IF_bit)
 {
 count++;
 if(count==100)
 {
 Os_newTimerTick();
 count = 0;
 }
 CCP1IF_bit = 0;
 }
#line 58 "D:/swift act files/gpt.c"
}
