// main.c

#include "prj.h"

/******************************************************************
  Project     : timer0
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

// global variable


void init()
{ 

    // Led1 init 
    Led1_DIR |= _BV(Led1_BIT) ;
    Led1_off(); 
    Timer0_Init();
} 

int main()
{
    // define variables

    init();  
    sei();  // enable interrupt
    while(1)
    {
        // add code here 
 
    }
}
