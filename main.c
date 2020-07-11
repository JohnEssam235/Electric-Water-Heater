#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "adc.h"
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


void main(void) {
uint32 temp;
uint32 teemp[20];
/*
  ANSELL  = 0;                        // Configure AN pins as digital I/O
  ANSELH = 0;
  C1ON_bit = 0;                      // Disable comparators
  C2ON_bit = 0;
  */
  LCD_Init();
  ADC_Init1();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1, 1, "Temp = ");
  while(1)
  {
  temp = ADC_readChannel(2); /* read channel two where the temp sensor is connect */
  temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
  FloatToStr(temp,teemp);
  Lcd_Out(1, 7, teemp);
  
  }

}