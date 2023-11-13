// led.c

#include "prj.h"

void Led_blink()
{
   Led1_PORT ^= _BV(Led1_BIT) ;
}
