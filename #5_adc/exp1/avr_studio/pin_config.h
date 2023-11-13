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
#define ADC0_PORT    PORTA
#define ADC0_DIR     DDRA
#define ADC0_PIN     PINA
#define ADC0_BIT     0

#define ADC1_PORT    PORTA
#define ADC1_DIR     DDRA
#define ADC1_PIN     PINA
#define ADC1_BIT     1

#define Key1_PORT    PORTC
#define Key1_DIR     DDRC
#define Key1_PIN     PINC
#define Key1_BIT     6

#define Key2_PORT    PORTC
#define Key2_DIR     DDRC
#define Key2_PIN     PINC
#define Key2_BIT     7

#define Lcm1_D4_PORT    PORTB
#define Lcm1_D4_DIR     DDRB
#define Lcm1_D4_PIN     PINB
#define Lcm1_D4_BIT     4

#define Lcm1_D5_PORT    PORTB
#define Lcm1_D5_DIR     DDRB
#define Lcm1_D5_PIN     PINB
#define Lcm1_D5_BIT     5

#define Lcm1_D6_PORT    PORTB
#define Lcm1_D6_DIR     DDRB
#define Lcm1_D6_PIN     PINB
#define Lcm1_D6_BIT     6
   
#define Lcm1_D7_PORT    PORTB
#define Lcm1_D7_DIR     DDRB
#define Lcm1_D7_PIN     PINB
#define Lcm1_D7_BIT     7

#define Lcm1_RS_PORT    PORTB
#define Lcm1_RS_DIR     DDRB
#define Lcm1_RS_PIN     PINB
#define Lcm1_RS_BIT     0
#define Lcm1_RW_PORT    PORTB
#define Lcm1_RW_DIR     DDRB
#define Lcm1_RW_PIN     PINB
#define Lcm1_RW_BIT     1
#define Lcm1_EN_PORT    PORTB
#define Lcm1_EN_DIR     DDRB
#define Lcm1_EN_PIN     PINB
#define Lcm1_EN_BIT     2

#endif
