// timer.c

#include "prj.h"

volatile unsigned int repeat_cnt0 = 0;

// Timer 0  timeout= 1.500 s, fosc = 7.3728 MHz 
//=========================================
void Timer0_Init()
{
    TCCR0 = 0x05; // divider 1024
    TCNT0 = 256 - 168;  
    TIMSK |= _BV(TOIE0);  
}

// Timer 0 interrupt service routine 
// timeout 1.500 s , fosc = 7.3728 MHz 
//====================================
ISR (TIMER0_OVF_vect)
{
    TCNT0 = 256 - 168; 

    flash_led2();

    if (++repeat_cnt0 == 64) 
    {
        repeat_cnt0 = 0; 
        // write your code 
        wdt_reset(); 
    }
}


