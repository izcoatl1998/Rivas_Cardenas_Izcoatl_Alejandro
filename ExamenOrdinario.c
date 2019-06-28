#include <interrupcionSerial.h>
#include <stdio.h>
char caracter[22];
int i=0,flag=0,datollego=0,flag2=0;
#INT_RDA
void isr_serial(void){
   if(kbhit()){
    caracter[i]=getch();
    datollego=1;
    i++;
   }
}
void main()
{
   int j=i-1;
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   while(TRUE)
   { 
      if(datollego==1){
        datollego=0;
       if(flag2==1){
           if(caracter[i-1]==13){
             printf("hola");
           }
       }
      if(caracter[i-1]==60){
         flag=1;
         caracter[i-1]=NULL;
       }
      if(flag==1){
         if(caracter[i-1]==62){
           flag=0;
           flag2=1;
           i++;
           caracter[i-1]=NULL;}
          printf("%c",caracter[i-1]);
        }
        else {
           i--;}
        }
      }

   }


