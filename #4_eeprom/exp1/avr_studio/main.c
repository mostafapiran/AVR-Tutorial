// main.c

#include "prj.h"

/******************************************************************
  Project     : internal eeprom
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

// ATMEG16 eeprom size 512 bytes (0~1FF)

#define eerpom_address         0x1f8


void Write_pattern1()
{
    unsigned char buf [] = { 0x11, 0x22, 0x33,0x44};
    eeprom_write_block ( (const void * )&buf, (void *) eerpom_address, 4);
    beep();
}

void Write_pattern2()
{
    unsigned char buf [] = { 0x55, 0x66, 0x77,0x88};
    eeprom_write_block ( (const void * )&buf, (void *) eerpom_address, 4);
    beep();
}


void Dump_eeprom()
{
   unsigned int i,j;
   unsigned char buf[16];
   char temp_buf[12];

   for (i=0; i<512 ; i=i+16)
   {
        eeprom_read_block( (void *) &buf, (const void* )i, 16);

        for (j=0; j<16 ; j++)
        {
            if (j==0)
            {
                sprintf(temp_buf,"[%03X] ", i);
                uart_sendString(temp_buf);
             }
             uart_send_hex(buf[j]);
             uart_send_char(' '); // space
        }
        uart_sendString("\r\n");
    }
    beep();
}

void init()
{ 

    // Bz1 init 
    Bz1_DIR |= _BV(Bz1_BIT) ;
    Bz1_off(); 

    // Key1 init 
    Key1_DIR  &= ~_BV(Key1_BIT); // input    
    Key1_PORT |=  _BV(Key1_BIT); // pull-high

    // Key2 init 
    Key2_DIR  &= ~_BV(Key2_BIT); // input    
    Key2_PORT |=  _BV(Key2_BIT); // pull-high

    // Key3 init 
    Key3_DIR  &= ~_BV(Key3_BIT); // input    
    Key3_PORT |=  _BV(Key3_BIT); // pull-high

    uart_init();
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
           while(Key1_press());
           Write_pattern1();
       }
       if (Key2_press())
       {
           while(Key2_press());
           Write_pattern2();
       }
       if (Key3_press())
       {
           while(Key3_press());
           Dump_eeprom();
       }
    }
}
