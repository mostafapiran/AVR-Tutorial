#ifndef _KEY_H
#define _KEY_H

#include "prj.h"

#define Key1_press()     ( ( Key1_PIN & _BV(Key1_BIT)) == 0 )
#define Key1_release()   ( ( Key1_PIN & _BV(Key1_BIT)) == 1 )
#define Key2_press()     ( ( Key2_PIN & _BV(Key2_BIT)) == 0 )
#define Key2_release()   ( ( Key2_PIN & _BV(Key2_BIT)) == 1 )

#endif 
