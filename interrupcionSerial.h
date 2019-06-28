#include <18F4620.h>
#device ADC=10
#include <stdio.h>
#include <stdlib.h> 

#FUSES NOWDT                    //No Watch Dog Timer

#use delay(oscillator=4MHz)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

