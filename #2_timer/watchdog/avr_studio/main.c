// main.c

#include "prj.h"

/******************************************************************
  Project     : watchdog
  Description : 
  MCU         : MEGA16
  F_OSC       : 7.3728 MHz
  IDE         : AVR Studio 4.18
  Library     : WinAVR-20100110
  Date        : 2015-12-05
  Version     : 
  History     : 

  Note
  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of  
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
******************************************************************/

/*
Led D1 flash 3 times when the program starts. Then led D2 is flashing. 
When user press key K1, the timer is off. Then the watchdog timer is not reset, watchdog reset occurs.
*/

// global variable


void init()
{ 

    // Led1 init 
    Led1_DIR |= _BV(Led1_BIT) ;
    Led1_off(); 

    // Led2 init 
    Led2_DIR |= _BV(Led2_BIT) ;
    Led2_off(); 

    // Key1 init 
    Key1_DIR  &= ~_BV(Key1_BIT); // input    
    Key1_PORT |=  _BV(Key1_BIT); // pull-high
    
} 

void flash_led1()
{
    unsigned char i;

	for (i=0; i<6; i++)
	{
         Led1_PORT ^= 0x02;
		_delay_ms(200);
	}
    Led1_off();
}

void flash_led2()
{
    Led2_PORT ^= 0x04;
}

int main()
{
    // define variables

    init();  
    flash_led1();

    Timer0_Init();

    // watchdog enable 
    wdt_enable(WDTO_2S); 
    sei();  // enable interrupt

    while(1)
    {
        // add code here 
        if (Key1_press())
	   {
	        // stop timer0 -> watchdog timer not reset
			// It will cause watchdog reset
			TIMSK = 0x00; 
     	    while(Key1_press());  	
		}	
    }
}
