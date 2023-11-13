// segment.c

#include "prj.h"

#if (SEGMENT_COMMON_CATHODE==1)
     unsigned char segment1[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71 }; // 0~F
#else // common anode
     unsigned char segment1[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e }; // 0~F
#endif     
    

// show hexadecimal 0 ~ F 
void Segment1_ShowDigit(unsigned char hexadecimal) 
{
      Segment1_PORT = segment1[ hexadecimal & 0x0f];
}

// show hexadecimal 0 ~ F with decimal point 
void Segment1_ShowDigit_withDP(unsigned char hexadecimal) // 0-F
{
      #if (SEGMENT_COMMON_CATHODE==1)
          Segment1_PORT = segment1[ hexadecimal & 0x0f] | 0x80;
      #else
          Segment1_PORT = segment1[ hexadecimal & 0x0f] &  ~0x80 ;
      #endif
}

// show pattern : 00 ~ FF 
//  
// b7 b6 b5 b4 b3 b2 b1 b0 
// dp  g  f  e  d  c  b  a 
void Segment1_ShowPattern(unsigned char pattern) // 00-FF
{
      Segment1_PORT = pattern;
}

void Segment1_off() 
{ 
  #if (SEGMENT_COMMON_CATHODE==1)
         Segment1_PORT = 0x00;
  #else
         Segment1_PORT = 0xFF;
  #endif
}

