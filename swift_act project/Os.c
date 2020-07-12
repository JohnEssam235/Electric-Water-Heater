#include "Os.h"
#include "App.h"
#include "Gpt.h"
#include "i2c.h"
uint8 counto = 0;
/* Global variable to indicate the the timer has a new tick */
uint8 time_flag=0;

/* Global variable store the Os Time */
static uint8 timer_count = 0;

// extern of electric heater flag
extern uint8 elec_heater_flag;

// extern temp1 and temp2 to set them after turning off the heater and then turning it on
extern uint8 temp1;
extern uint8 temp2;

/*********************************************************************************************/
void Os_start(void)
{
        /* 
         * Set the Call Back function call to Scheduler_New_Timer_Tick
         * this function will be called every Timer0 Compare Interrupt(20ms)
         */
        //Timer1_setCallBack(Os_newTimerTick);  /* this is used if you wanna implpement the driver using the
                                                   /* call back function .. but its not applicable due to
                                                   /* RAM error(RAM shortage) in the PIC16F877A */

        /* Start compare mode (CCP module) with a base time 20ms */
        Timer1_start(400);

        Init_Task();

        /* Start the Os Scheduler */
        Os_scheduler();

}
/*********************************************************************************************/
void Os_newTimerTick(void)
{

        /* increment the Os time by OS_BASE_TIME */
        timer_count   += OS_BASE_TIME;

        /* Set the flag to 1 to indicate that there is a new timer tick */
        time_flag=1;
}
/*********************************************************************************************/
void Os_scheduler(void)
{

        while(1)
        {

                if(time_flag==1 && elec_heater_flag == 1)  // if heater is ON and timer flag = 1
                {

                        switch(timer_count)
                        {
                                case 20:
                                case 40:
                                case 60:
                                case 80:
                                case 120:
                                case 140:
                                case 160:
                                case 180:
                                        SSD_TASK();
                                        time_flag = 0;
                                        break;
                                case 100:
                                        SSD_TASK();
                                        ADC_Task();
                                        time_flag = 0;
                                        break;
                                  case 200:
                                        SSD_TASK();
                                        heater_task();
                                        up_ButtonTask();
                                        down_ButtonTask();
                                        SSD_blinking();
                                        ADC_Task();
                                        Heater_Led_Task();
                                        time_flag = 0;
                                        timer_count = 0;  // clear the counter at 200ms
                                        break;

                        }
                }
                else if(elec_heater_flag == 0)  // heater is off
                {
                    if(RB0_bit == 0) // when the heater button is ON again
                    {
                       temp1 = EEPROM_readByte(2);    // read the last setted temp.
                       temp2 = EEPROM_readByte(3);
                       elec_heater_flag = 1;           // raise the heater flag
                    }

                }
        }

}
