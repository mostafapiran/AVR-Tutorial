// timer.c

#include "prj.h"

volatile unsigned int repeat_cnt0 = 0;

// Timer 0  timeout= 500.000 ms, fosc = 7.3728 MHz 
//=========================================
void Timer0_Init()
{
    TCCR0 = 0x05; // divider 1024
    TCNT0 = 256 - 225;  
    TIMSK |= _BV(TOIE0);  
}

// Timer 0 interrupt service routine 
// timeout 500.000 ms , fosc = 7.3728 MHz 
//====================================
ISR (TIMER0_OVF_vect)
{
    TCNT0 = 256 - 225; 
    if (++repeat_cnt0 == 16) 
    {
        repeat_cnt0 = 0; 
        // write your code 
        Led_blink();
    }
}


