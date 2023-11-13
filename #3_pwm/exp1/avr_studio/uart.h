#ifndef _UART_H
#define _UART_H

#include "prj.h"

void uart_init(); 
void uart_send_char(unsigned char ch); 
void uart_sendString(char *s); 
void uart_send_hex(unsigned char ch); 

#endif 
