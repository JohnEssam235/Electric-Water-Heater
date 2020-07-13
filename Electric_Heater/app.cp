#line 1 "D:/swift act files/app.c"
#line 1 "d:/swift act files/app.h"
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
#line 8 "d:/swift act files/app.h"
void Init_Task();
void SSD_TASK();
void up_ButtonTask();
void down_ButtonTask();
void Heater_Led_Task();
void ADC_Task();
void heater_task();
void SSD_blinking();
#line 1 "d:/swift act files/eeprom.h"
#line 1 "d:/swift act files/std_types.h"
#line 15 "d:/swift act files/eeprom.h"
void EEPROM_init(void);
void EEPROM_writeByte(unsigned short my_data,uint8 add);
uint8 EEPROM_readByte(uint8 add);
#line 8 "D:/swift act files/app.c"
extern uint8 temp1;
extern uint8 temp2;


uint8 SSD_FLAG = 0;


uint8 heat_elem_flag = 0;


uint8 set_temp;


uint8 adc_flag = 0;
uint16 read[10];
uint8 count = 0;
uint8 average;
uint8 dodo;
uint8 temp_var;



extern uint8 elec_heater_flag;


uint8 led_count;



 uint8 SSD_blinking_flag = 0;
 uint8 SSD_blinking_counter = 0;
 uint8 SSD_Enable_flag = 0;



void Init_Task()
{
 PEIE_bit = 1;
 GIE_bit = 1;
 ADCON0 = 0x91;
 ADCON1 = 0xC0;
}


void SSD_TASK()
{
 if(SSD_Enable_flag != 1)


 {
 if(SSD_FLAG == 0)
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

void up_ButtonTask()
{

 if(RB1_bit == 0)
 {
 SSD_blinking_flag = 1;
 SSD_blinking_counter=0;
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
void down_ButtonTask()
{

 if(RB2_bit == 0)
 {
 SSD_blinking_flag=1;
 SSD_blinking_counter=0;
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

void Heater_Led_Task()
{

 if(RC5_bit == 1)
 {
 led_count = led_count + 2;
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
 if(adc_flag != 0)
 {

 if(count == 9)
 {
 read[count] = (ADC_Read(2)*0.0048828)/0.01;
 average = (read[0]+read[1]+read[2]+read[3]+read[4]+read[5]+read[6]+read[7]+read[8]+read[9])/10;
 temp_var = average;


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


 if((average - set_temp) >= 5)
 {

 PORTC.RC2 = 1;

 PORTC.RC5 = 0;
 }
 else if((average - set_temp) <= -5)
 {

 PORTC.RC5 = 1;

 PORTC.RC2=0;
 }
 count = 0;
 }
 else
 {
 read[count] = (ADC_Read(2)*0.0048828)/0.01;
 count++;
 }
 }
}

void heater_task()
{
 if(RB0_bit == 0)
 {
 elec_heater_flag = !elec_heater_flag;
 if(elec_heater_flag == 0)
 {

 PORTD = 0;
 PORTA.RA5 = 0;
 delay_ms(100);
 PORTA.RA4 = 0;
 delay_ms(100);
 PORTC.RC2 = 0;
 PORTC.RC5 =0;
 adc_flag = 0;
 PORTB.RB7 = 0;
 }
 }
}

void SSD_blinking()
{
 if(SSD_blinking_flag==1)
 {
 if(SSD_blinking_counter == 0 || SSD_blinking_counter==10 || SSD_blinking_counter==20 || SSD_blinking_counter==30 || SSD_blinking_counter==40)
 {
 PORTD = 0;
 SSD_Enable_flag = 1;
 }
 SSD_blinking_counter = SSD_blinking_counter+1;
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
 SSD_Enable_flag = 0;
 adc_flag = 1;
 }

 }
}
