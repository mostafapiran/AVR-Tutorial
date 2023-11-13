// main.c

#include "prj.h"

/******************************************************************
  Project     : uart
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
char *s = "ATMEGA16 uart test !\r\n";


void init()
{ 
    Key1_DIR  &= ~_BV(Key1_BIT) ;// input
    Key1_PORT |=  _BV(Key1_BIT) ;// pull-high
    
    uart_init();
} 

int main()
{
    // define variables

    init();  
    sei();  // enable interrupt
    while(1)
    {
        // add code here 
       if (Key1_press())
       {
           uart_sendString(s);
           _delay_ms(500);
       }
    }
}
