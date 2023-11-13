// key.c

#include "prj.h"

void key_init()
{
    // Key1 init 
    Key1_DIR  &= ~_BV(Key1_BIT); // input    
    Key1_PORT |=  _BV(Key1_BIT); // pull-high

    // Key2 init 
    Key2_DIR  &= ~_BV(Key2_BIT); // input    
    Key2_PORT |=  _BV(Key2_BIT); // pull-high

    


}
