// main.c

#include "prj.h"

/******************************************************************
  Project     : external interrupt
  Description : 
  MCU         : MEGA16
  F_OSC       : 4.0000 MHz
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

    // Key1 init 
    Key1_DIR  &= ~_BV(Key1_BIT); // input    
    Key1_PORT |=  _BV(Key1_BIT); // pull-high

    // Segment1 init 
    Segment1_DIR  = 0xFF; // output 
    Segment1_off(); 
    interrupt0_init(); 
} 

int main()
{
    // define variables

    init();  
    sei();  // enable interrupt
    while(1)
    {
        if (Key1_press())
        {
             int0_count = 0;
        }              
        Segment1_ShowDigit(int0_count % 16 );
    }
}
