#ifndef _BUZZER_H
#define _BUZZER_H

// 0 - active low, 1 - active high
#define BZ1_ACTIVE_LOW    0

#if (BZ1_ACTIVE_LOW ==0) 
    #define Bz1_on()     Bz1_PORT &= ~_BV(Bz1_BIT) 
    #define Bz1_off()    Bz1_PORT |=  _BV(Bz1_BIT) 
#else 
    #define Bz1_on()     Bz1_PORT |=  _BV(Bz1_BIT) 
    #define Bz1_off()    Bz1_PORT &= ~_BV(Bz1_BIT) 
#endif


void beep();


#endif
