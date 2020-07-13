#include "App.h"
#include "EEPROM.h"

/* global vars................... */


// the 2 variables of the temperature
extern uint8 temp1;
extern uint8 temp2;

// the flag of the SSD Task to display both displays.....
uint8 SSD_FLAG = 0;

// flag for Heating Element LED TASK
uint8 heat_elem_flag = 0;

// variable for set temp. in ADC task
uint8 set_temp;

/* ADC Variables..........*/
uint8 adc_flag = 0;   //flag for enabling ADC
uint16 read[10];     // array to store the readings
uint8 count = 0;     // number of ADC readings count
uint8 average;       // variable to calculate the average temp.
uint8 dodo;          // variable used in the ADC TASK :)
uint8 temp_var;      // temporary variable used in the ADC task


// the flag in the Os.c that indicates if the button heater is pressed or not
extern uint8 elec_heater_flag; // electric heater is closed

// counter for the heating element LED Task to handle its timing
uint8 led_count;


 /* variables for the SSD_blinking task...*/
 uint8 SSD_blinking_flag = 0;         // flag for operating the SSD blinking task..
 uint8 SSD_blinking_counter = 0;      // counter for the task to handle the timing
 uint8 SSD_Enable_flag = 0;           // flag for enabling/disabling the SSD task


 
void Init_Task()    // Init Task called by the OS
{
   PEIE_bit = 1;   // initializing the interrupt global variable and PEIE for the timer
   GIE_bit = 1;
   ADCON0 = 0x91;   // initializing the ADC
   ADCON1 = 0xC0;
}


void SSD_TASK() /* this task only displays the temp */
{
   if(SSD_Enable_flag != 1)   // This task should be disabled(flag=1) when SSD_blinking task is operating
                              //(specially when the SSD turns off in blinking) so SSD Task should not operate once
                              // as i wanna make the SSD off so it couldnt display the temp.
   {
    if(SSD_FLAG == 0)         // flag used to display both SSD and to switch between them
    {
      PORTA.RA5 = 0;
      switch(temp1)
      {
         case 2:
                PORTD = 0x5B;
                break;
         case 3:
               PORTD = 0x4F;
               break;
         case 4:
               PORTD = 0x66;
               break;
         case 5:
               PORTD = 0x6D;
               break;
         case 6:
               PORTD = 0x7D;
               break;
         case 7:
               PORTD = 0x07;
               break;
         case 8:
                PORTD = 0x7F;
                break;
      }
      PORTA.RA4 = 1;
      SSD_FLAG = 1;
   }
   else if(SSD_FLAG == 1)
   {
      PORTA.RA4 = 0;
      switch(temp2)
      {
         case 0:
                PORTD = 0x3F;
                break;
         case 1:
                PORTD = 0x06;
                break;
         case 2:
                PORTD = 0x5B;
                break;
         case 3:
                PORTD = 0x4F;
                break;
         case 4:
                PORTD = 0x66;
                break;
         case 5:
                PORTD = 0x6D;
                break;
         case 6:
                PORTD = 0x7D;
                break;
         case 7:
                PORTD = 0x07;
                break;
         case 8:
                PORTD = 0x7F;
                break;
         case 9:
                PORTD = 0x6F;
                break;
      }
      PORTA.RA5 = 1;
      SSD_FLAG = 0;
    }
   }
}

void up_ButtonTask()                  // task for raising the temperature
{

         if(RB1_bit == 0)             // raise the temp by 5
         {
             SSD_blinking_flag = 1;   // we have entered the set mode right now...
             SSD_blinking_counter=0;  // counter for SSD_blinking task to control the timing(clear the counter)
            if((temp1 == 7) && (temp2 == 5))
            {

            }
            else if(temp2 == 0)
            {
                temp2 = temp2 + 5;
                EEPROM_writeByte(temp1,2);
                EEPROM_writeByte(temp2,3);
            }
            else if(temp2 == 5)
            {
                temp2=0;
                temp1++;
                EEPROM_writeByte(temp1,2);
                EEPROM_writeByte(temp2,3);
            }
            set_temp = (temp1*10)+temp2;
         }

}
void down_ButtonTask()                 // task for decreasing the temperature
{

         if(RB2_bit == 0)              // decrease the temp by 5
         {
             SSD_blinking_flag=1;      // we have entered the set mode right now...
             SSD_blinking_counter=0;  // counter for SSD_blinking task to control the timing (clear the counter)
            if((temp1 == 3) && (temp2 == 5))
            {
            }
            else if(temp2 == 5)
            {
               temp2 = 0;
               EEPROM_writeByte(temp1,2);
               EEPROM_writeByte(temp2,3);
            }
            else if(temp2 == 0)
            {
               temp2 = 5;
               temp1 = temp1 - 1;
               EEPROM_writeByte(temp1,2);
               EEPROM_writeByte(temp2,3);
            }
            set_temp = (temp1*10)+temp2;
         }

}

void Heater_Led_Task()               // The Led task that operates when the cooler or heater operate
{

     if(RC5_bit == 1)                // heating element is ON
      {
         led_count = led_count + 2;  // count variable to control the timing
         if(led_count == 10)
         {
            PORTB.RB7 = !PORTB.RB7;
            led_count = 0;
         }
      }
     else if(RC2_bit == 1)
     {
        PORTB.RB7 = 1;
     }
}

void ADC_Task()
{
    if(adc_flag != 0)                  // flag to enable the ADC task when the temperature is setted
    {
     
     if(count == 9)                    // last reading
     {
       read[count] = (ADC_Read(2)*0.0048828)/0.01;
       average = (read[0]+read[1]+read[2]+read[3]+read[4]+read[5]+read[6]+read[7]+read[8]+read[9])/10;
       temp_var = average;             // temp_var is used to not corrupting the average temp variable
       
       // for loop to seperate the two digits of the average temperature...
       for(dodo=0;dodo<2;dodo++)
       {
         if(dodo==0)
         {
            temp2 = temp_var%10;
            temp_var = temp_var/10;
         }
         else
         {
            temp1 = temp_var;
         }
       }
       
       // make a decision depending on the average temperature
       if((average - set_temp) >=  5)
       {
           // operate the fan
           PORTC.RC2 = 1;
           // close the heater
           PORTC.RC5 = 0;
       }
       else if((average - set_temp) <= -5)
       {
          // operate the heater
          PORTC.RC5 = 1;
          //close the fan
          PORTC.RC2=0;
       }
       count = 0;  // clearing the count of the readings
    }
    else
    {
     read[count] = (ADC_Read(2)*0.0048828)/0.01;
     count++;
    }
   }
}

void heater_task()                            // task indicates if the heater is OFF or ON
{
   if(RB0_bit == 0)
   {
       elec_heater_flag = !elec_heater_flag;  // toggle the flag of the elec. heater
       if(elec_heater_flag == 0)              // if heater became off
       {

          PORTD = 0;                          //close the SSD
          PORTA.RA5 = 0;                      // close the two control lines
          delay_ms(100);
          PORTA.RA4 = 0;
          delay_ms(100);
          PORTC.RC2 = 0;         // close the fan
          PORTC.RC5 =0;          // close the heating element
          adc_flag = 0;          // turn ADC off....
          PORTB.RB7 = 0;         //turn heater led off
       }
   }
}

void SSD_blinking()                      // blinking Task
{
   if(SSD_blinking_flag==1)              // if we are in the setting mode right now
   {
      if(SSD_blinking_counter == 0 || SSD_blinking_counter==10 || SSD_blinking_counter==20 || SSD_blinking_counter==30 || SSD_blinking_counter==40)
      {
         PORTD = 0;                      // close the SSD PORTD(data port)
         SSD_Enable_flag = 1;
      }
      SSD_blinking_counter = SSD_blinking_counter+1;  // counter to control the timing of the Task
      if(SSD_blinking_counter==5 || SSD_blinking_counter==15 || SSD_blinking_counter==25 || SSD_blinking_counter==35)
      {
         SSD_Enable_flag = 0;
      }
      else if(SSD_blinking_counter == 45)
      {
          PORTA.RA4 = 0;
          PORTA.RA5 = 0;
          SSD_blinking_counter = 0;
          SSD_blinking_flag = 0;
          SSD_Enable_flag = 0;          // enable the SSD once again to display the temp.
          adc_flag = 1;                 // enable the adc to control the temp.
      }
      
   }
}