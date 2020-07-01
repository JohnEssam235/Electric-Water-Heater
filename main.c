#include "adc.h"
//////* Function yo get average of array *///////
uint32 average(int a[],int n){
int sum=0;
int i=0;
for(i=0;i<n;i++){
sum+=a[i];
}
return sum/n;
}
/////* main */////////
void main() {
	uint32 temp;  //// temprature from temp_sensor
        uint32 reading_1; ///// comparsion between set_temp and average of last 10 tempratures to compare with heat_elemnt
         uint32 reading_2; ///// comparsion between set_temp and average of last 10 tempratures to compare with cool_elemnt
        uint32 result; //// to get average of temperatures
        uint32 array[10]; ///// array to store last 10 temperatures
        int i=0; //// counter for "for loop"
        uint32 m=0; //// counter to be sure you read last 10 temperatures
        uint32 set_temp =60;
	ADC_Init(); /* initialize ADC driver */
	TRISC=0x00; //// configure portc as output
        PORTC=0x00;
	while(1){
	while(1){ //// to be sure that we take last 10 temp
	if(m==10){
	break; ///// we will break after taking 10 readings
	}
	 temp = ADC_readChannel(0); /* read channel two where the temp sensor is connect */
         temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
         array[i]=temp;
          delay_ms(100);
         m++;
         i++;
	}
	}
       result=average(array,10);
         reading_2=result-set_temp;
        if(result<set_temp){
        reading_1=set_temp-result;
         if(reading_1==5){
         RC0_bit=1; ////// heat element in pin 0 portc
         RC1_bit=0; /// close cooling elemnt
         }
         }
         if(result>set_temp){
          reading_2=result-set_temp;
          if(reading_2==5){
         RC1_bit=1; ////// cooling element in pin 1 portc
         RC0_bit=0;
         }
         }
}

	
	
	
	
	
	
	
	
	
	
	
/*
 TRISB=0x00;
 PORTB=0x00;
 for(;;){
 RB0_bit=1;
 delay_ms(100);
 RB0_bit=0;
 delay_ms(100);
}
*/
	
	