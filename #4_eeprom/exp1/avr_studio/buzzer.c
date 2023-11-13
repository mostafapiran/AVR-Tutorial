// buzzer.c

#include "prj.h"

void beep()
{
   unsigned int  i;
   for (i=0; i<300; i++)
   {
       Bz1_PORT ^= _BV(Bz1_BIT);
       _delay_ms(1.1);
    }
}
