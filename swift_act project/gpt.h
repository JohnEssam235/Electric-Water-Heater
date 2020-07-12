

#ifndef GPT_H
#define GPT_H
#include "std_types.h"

void Timer1_start(uint8 my_tick);

/* Points to the required function in the OS upper layer Scheduler */
/* this could be used if you wanna design the system with a call back function
void Timer1_setCallBack(void (*Ptr2Func)(void));                              */

#endif /* GPT_H */
