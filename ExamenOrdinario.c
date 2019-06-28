#include <interrupcionSerial.h>
#include <stdio.h>
char caracter[22];
int i=0,flag=0,datollego=0,flag2=0,flagcomenzar=1;
int16 op1=0,op2=0,op3=0;
#INT_RDA
void isr_serial(void){
   if(kbhit()){
    caracter[i]=getch();
    datollego=1;
    i++;
   }
}
#INT_TIMER0 
void TIMER0(){
set_timer0(57);
}
void main()
{
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_32 );
   set_timer0(57);
   while(TRUE)
   { 
      if(datollego==1){
          datollego=0;
       if(caracter[i-1]>64 && caracter[i-1]<91  || caracter[i-1]>96 && caracter[i-1]<123  || caracter[i-1]=='<' || caracter[i-1]=='>' || caracter[i-1]==13 || caracter[i-1] ==';'){ 
       if(flag2==1){
           if(caracter[i-1]==13){
             printf("hola");
             flagcomenzar=1;
           }
       }
      if(caracter[i-1]=='>'){
         flag=1;
         caracter[i-1]=NULL;
       }
      if(flag==1){
         if(caracter[i-1]=='<'){
           flag=0;
           flag2=1;
           i++;
           caracter[i-1]=NULL;}
          printf("%c",caracter[i-1]);
        }
        else {
           i--;}
        }else{
           caracter[i-1]=NULL;
           i--;}
       }
      }
   }


