#ifndef _PIN_CONFIG_H
#define _PIN_CONFIG_H

#include "prj.h"

//                 ATMEGA16             
//      +---------------------------+   
//     1|PB0 (XCK/T0)     (ADC0) PA0|40 
//     2|PB1 (T1)         (ADC1) PA1|39 
//     3|PB2 (INT2/AIN0)  (ADC2) PA2|38 
//     4|PB3 (OC0/AIN1)   (ADC3) PA3|37 
//     5|PB4 (nSS)        (ADC4) PA4|36 
//     6|PB5 (MOSI)       (ADC5) PA5|35 
//     7|PB6 (MISO)       (ADC6) PA6|34 
//     8|PB7 (SCK)        (ADC7) PA7|33 
//     9|nRST                   AREF|32 
//    10|VCC                     GND|31 
//    11|GND                    AVCC|30 
//    12|XTAL2           (TOSC2) PC7|29 
//    13|XTAL1           (TOSC1) PC6|28 
//    14|PD0 (RXD)         (TDI) PC5|27 
//    15|PD1 (TXD)         (TDO) PC4|26 
//    16|PD2 (INT0)        (TMS) PC3|25 
//    17|PD3 (INT1)        (TCK) PC2|24 
//    18|PD4 (OC1B)        (SDA) PC1|23 
//    19|PD5 (OC1A)        (SCL) PC0|22 
//    20|PD6 (ICP1)        (OC2) PD7|21 
//      +---------------------------+   
#define Key1_PORT    PORTD
#define Key1_DIR     DDRD
#define Key1_PIN     PIND
#define Key1_BIT     7

#define Segment1_PORT    PORTA
#define Segment1_DIR     DDRA
#define Segment1_PIN     PINA

#endif
