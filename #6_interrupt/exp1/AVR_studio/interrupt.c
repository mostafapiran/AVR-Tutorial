// interrupt.c

#include "prj.h"

volatile  unsigned char int0_count =0;



void interrupt0_init()
{ 
    // enable external interrupt 0
    DDRD  &= ~_BV(2); // input
    PORTD |=  _BV(2); // pull-high
    MCUCR |= _BV(ISC01) | _BV(ISC00); 
    GICR  |= _BV(INT0);
}    

ISR (INT0_vect) 
{ 
    // write your code 
    int0_count++;
} 

