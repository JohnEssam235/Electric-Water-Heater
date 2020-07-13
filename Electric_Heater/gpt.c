#include "Gpt.h"
#include "Os.h"

// global variable used in handling the interrupt time of the compare module
static uint8 count = 0;

/* Global pointer to function used to point upper layer functions
 * to be used in Call Back ... if you want to use call back...
static volatile void (*g_Timer0_Call_Back_Ptr)(void) = NULL;  */

/*********************************************************************************************/ 
void Timer1_start(uint8 my_tick)  // ana m43'lo ka compare mode .... fa hb3tlo el tick_time.....
{
  //--[ Configure The Timer1 Module To Operate In Timer Mode ]--
  TMR1L = 0;
  TMR1H = 0;
  T1CKPS0_bit = 0;
  T1CKPS1_bit = 0;
  TMR1CS_bit = 0;
  TMR1ON_bit = 1;
  //--[ Configure The CCP1 Module To Operate in Compare Mode ]--
  // Preload The CCPR1 Register
  CCPR1 = my_tick;
  // CCP in Compare Mode, CCPx Pin Is Unchanged & Trigger Special Event
  CCP1CON = 0x0B;
  // Enable CCP1 Interrupt
  CCP1IE_bit = 1;
}
/*********************************************************************************************/
/* this is used if you wanna design the system with call back function
void Timer1_setCallBack(void(*Ptr2Func)(void))
{
        g_Timer0_Call_Back_Ptr = Ptr2Func;
}                                                                      */
/*********************************************************************************************/
/* Interrupt Service Routine for Timer1 compare mode */
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
          
          // This could be used if you wanna design the system using the call back function
        /* Check if the Timer1_setCallBack is already called */
       /*if(g_Timer0_Call_Back_Ptr != NULL)
        {
                (*g_Timer0_Call_Back_Ptr)(); //call the function in the scheduler using call-back concept
        } */

}
/*********************************************************************************************/