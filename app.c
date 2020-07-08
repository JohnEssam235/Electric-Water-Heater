

#include "App.h"
#include "i2c.h"

/* global vars................... */
// the 2 variables of the 2 SSD ..ha5odhom mn el up/down buttons task...
uint8 temp1;    // el h3rdo 3ala display1
uint8 temp2;   // el h3rdo 3ala display2
// the flag of the 2 SSD .....
uint8 SSD_FLAG = 0;

// the flag of the first_time of the setting mode
uint8 setmode_flag = 0;

// the extern of the heating element and the cooling element .....
extern uint8 heat_element;
extern uint8 cooling_element;
// flag for heating element LED TASK
uint8 heat_elem_flag = 0;


/* ADC Variables..........*/
uint16 read[10];
uint8 count = 0;
uint8 average;


void Init_Task()
{
   PEIE_bit = 1;
  GIE_bit = 1;
  ADC_Init();
   EEPROM_init();
}


void SSD_TASK() /* this task only displays the temp */
{
   if(SSD_FLAG == 0)
   {
      SSD_FLAG = 1;
      TRISA.RA3 = 1; /* a2fel el display el tanya*/
      TRISA.RA2 = 0;
      PORTD = temp1;
   }
   else
   {
      SSD_FLAG = 0;
      TRISA.RA2 = 1;
      TRISA.RA3 = 0;
      PORTD = temp2;
   }
}

void up_down_ButtonTask()
{

         if(RB0_bit == 1) // raise the temp by 5
         {
            if(setmode_flag == 0)
            {
               setmode_flag = 1;
               temp1 = 6;
               temp2 = 0;
            }
            if((temp1 == 7) && (temp2 == 5))
            {

            }
            else if(temp2 == 0)
            {
                temp2 += 5;
                EEPROM_writeByte(temp1,2);
                EEPROM_writeByte(temp2,3);
            }
            else if(temp2 == 5)
            {
                temp1++;
                temp2=0;
                EEPROM_writeByte(temp1,2);
                EEPROM_writeByte(temp2,3);
            }
         }
         if(RB1_bit == 1) // decrease the temp by 5
         {
            if(setmode_flag == 0)
            {
               setmode_flag = 1;
               temp1 = 6;
               temp2 = 0;
            }
            if((temp1 == 3) && (temp1 == 5))
            {
            }
            else if(temp1 == 5)
            {
               temp1 == 0;
            }
            else if(temp1 == 0)
            {
               temp1--;
               temp2 = 5;
            }
         }

}

void Heater_Led_Task()
{
    if(heat_element == 1) // heating element is ON
      {
         if(heat_elem_flag == 0)
         {
            heat_elem_flag = 1;
            PORTB.RB2 = 1;
         }
         else
         {
            heat_elem_flag =0;
            PORTB.RB2 = 0;
         }
      }
     if(cooling_element == 1)
     {
        PORTB.RB2 = 1;
     }
}

void ADC_Task()
{
    if(count == 9)
    {
       uint8 set_temp;
       read[count] = ADC_Read(5);
       count = 0;
       average = (read[0]+read[1]+read[2]+read[3]+read[4]+read[5]+read[6]+read[7]+read[8]+read[9])/10;
       set_temp = (temp1*10)+temp2;
       if(average-set_temp > 5)
       {
           // operate the fan
           PORTC.RC2 = 1;
           // close the heater
           PORTC.RC5 = 0;
       }
       else if(average-set_temp < -5)
       {
          // operate the heater
          PORTC.RC5 = 1;
          //close the fan
          PORTC.RC2=0;
       }
    }
    else
    {
     read[count] = ADC_Read(5); /* read channel two where the temp sensor is connect */
     read[count] = (read[count]*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
     count++;
    }

}