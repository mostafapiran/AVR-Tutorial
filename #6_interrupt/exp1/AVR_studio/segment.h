#ifndef _SEGMENT_H
#define _SEGMENT_H

#include "prj.h"

// 0 - common anode, 1 - common cathode
#define SEGMENT_COMMON_CATHODE    1


void Segment1_ShowDigit(unsigned char digit);
void Segment1_ShowDigit_withDP(unsigned char hexadecimal);
void Segment1_ShowPattern(unsigned char pattern);
void Segment1_off(); 

#endif 
