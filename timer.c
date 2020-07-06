 void interrupt(){
  if(INTCON.TMR0IF ==1){     //// wait until flag of timer come which indicate the timer has finished counting
  /////// doing the action here
  INTCON.TMR0IF=0;         //// clear flag
  TMR0=0;                  //// clear the data register of timer0
  }
 }
 
 
 
 
 void Timer0_init_Normal_Mode(void){
 TMR0IE_bit=1;   // enable interrupt for timer 0
 T0CS_bit=0;   //// to select clock of microcontroller
 PSA_bit=0;  ///  Prescaler is assigned to the Timer0 module
 TMR0=0;          //// initial value for timer0
 PS0_bit=1;  /// prescaler=256 we should put ps2:ps0=111
 PS1_bit=1; /// prescaler=256
 PS2_bit=1; /// prescaler=256
 }

 
 void main(){
  GIE_bit=1; /// enable global interrupt
  Timer0_init_Normal_Mode();
  while(1){
  
  }
 
 }