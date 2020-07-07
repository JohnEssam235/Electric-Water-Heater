


 void interrupt(){
  if(CCP1IF==1){     //// wait until flag of timer come which indicate the timer has finished counting
  /////// doing the action here
  CCP1IF = 0;         //// clear flag
  TMR1 = 0;                 //// clear the data register of timer1
  }
 }



 void Timer1_init_compare_Mode(void){
  TMR1=0;   //// initial value for timer1
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  TMR1CS = 0;
  TMR1ON = 1;
  // Preload The CCPR1 Register
  CCPR1 = 50000;
   ///// Compare mode, generate software interrupt on match
  CCP1M0 = 1;
  CCP1M1 = 1;
  CCP1M2 = 0;
  CCP1M3 = 1;
  // Enable CCP1 Interrupt
  CCP1IE = 1;
  PEIE = 1;
 }

 void main(){
  GIE_bit=1; /// enable global interrupt
  Timer1_init_compare_Mode();
  while(1){

  }

 }