#include <interrupcionSerial.h>
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
char caracter[50];
char palabra[50];
int i=0,flag=0,datollego=0,flag2=0,flagcomenzar=1;
int flagop1=0,flagop2=0,flagop3=0,flagpalabra=0;
int16 op1=0,op2=0,op3=0;
int punteroOP;
int16 flagcontador1=0,flagcontador2=0,flagcontador3=0;
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
       if(caracter[i-1]>64 && caracter[i-1]<91  || caracter[i-1]>96 && caracter[i-1]<123  || caracter[i-1]=='<' 
       || caracter[i-1]=='>' || caracter[i-1]==13 || caracter[i-1] ==';'|| caracter[i-1]>47 && caracter[i-1]<58){
       if(flag2==1){
           if(caracter[i-1]==13){
             printf("hola");
             flagcomenzar=1;
           }
       }
      if(caracter[i-1]=='>'){
         flag=1;
         caracter[i-1]=NULL;
         flagop1=1;
       }
      if(flag==1){
         if(flagop1==1){
           if(caracter[i-1] == ';'){
              punteroOP=i;
              op1=calcular1(caracter);
              flagop1=0;
              flagop2=1;
              printf("%c",caracter[i-1]);
              caracter[i-1]=NULL;}
            }
          if(flagop2==1){
            if(caracter[i-1] == ';'){
              op2=calcular2(caracter,punteroOp);
              punteroOP=i;
              flagop1=0;
              flagop2=0;
              flagop3=1;
              printf("%c",caracter[i-1]);
              caracter[i-1]=NULL;}
            }
           if(flagop3==1){
             if(caracter[i-1] == ';'){
               op3=calcular2(caracter,punteroOp);
               punteroOP=i;
               flagop1=0;
               flagop2=0;
               flagop3=0;
               flagpalabra=1;
               printf("%c",caracter[i-1]);
               caracter[i-1]=NULL;
               }
            }
            if(flagpalabra=0){
               if(caracter[i-1] == 13){
                
               }
            }
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


