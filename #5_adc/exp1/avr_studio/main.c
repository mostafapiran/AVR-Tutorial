// main.c

#include "prj.h"
#include <stdio.h>

/********************************************
  Project     : adc
  Description : 
  MCU         : MEGA16
  F_OSC       : 7.3728 MHz
  IDE         : AVR Studio 4.18
  Library     : WinAVR-20100110
  Date        : 2015-12-04
  Version     : 
  History     : 
********************************************/

void show_adc_value(unsigned char ch)
{
    char buf[16];

    unsigned int value = adc_get_value(ch);
    float f_value = (float ) (value * 5.0/ 1023.0);

    sprintf(buf, "ch%d = %d.%-3d", ch, (int)f_value, (int)(1000 * (f_value - (int)(f_value))));
    Lcm1_ShowString_xy(0,1, buf);

}


int main() 
{ 
   unsigned char ch = 0;
   
  // Key1 init 
    Key1_DIR  &= ~_BV(Key1_BIT); // input    
    Key1_PORT |=  _BV(Key1_BIT); // pull-high

    // Key2 init 
    Key2_DIR  &= ~_BV(Key2_BIT); // input    
    Key2_PORT |=  _BV(Key2_BIT); // pull-high

 
    adc_init();

    Lcm1_Init();
    Lcm1_Clearscreen();
    
    sei();

    Lcm1_ShowString_xy(0,0, "LCD adc demo");
    Lcm1_ShowString_xy(0,1, "Ver 002");

    _delay_ms(2000);

    while(1)
    {
       if (Key1_press())
       {
            do { ; } while (Key1_press());
            ch = 0;
        }
       if (Key2_press())
       {
            do {;} while (Key2_press());
            ch = 1;
        }    
         show_adc_value(ch);
            
        _delay_ms(100);
    }    
}

