// uart.c

#include "prj.h"

void uart_init() 
{
    // fosc = 7372800 Hz 
    // baud=57600, actual_baud=57600.0, err=0.0 %
    UBRRL = 0x07; 
    UBRRH = 0x00; 
   
    // enable uart N81  
    UCSRB =  _BV(RXEN) | _BV(TXEN) ;
    UCSRC = _BV(URSEL) | _BV(UCSZ1) | _BV(UCSZ0);
   
}

void uart_send_char(unsigned char ch)
{
   UDR = ch;

   /* Wait for empty transmit buffer */
   while (! (UCSRA & _BV(UDRE)) );

}

void uart_sendString(char *s)
{
   unsigned int i=0;
   while (s[i] != '\x0') 
   {
       uart_send_char(s[i++]);
    };
}

void  uart_send_hex(unsigned char ch)
{
    unsigned char i,temp;
     
    for (i=0; i<2; i++)
    {
        temp = (ch & 0xF0)>>4;
        if ( temp <= 9)
            uart_send_char ( '0' + temp);
        else
            uart_send_char(  'A' + temp - 10);
        ch = ch << 4;    
     }   
}

