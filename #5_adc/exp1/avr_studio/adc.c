// adc.c

#include "prj.h"

void adc_init() 
{ 
    // Aref = AVCC 
    ADMUX = (1<<REFS0);

    // ENABLE ADC, PRESCLER 128
    ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    
} 
 
unsigned int adc_get_value(unsigned char ch) 
{ 
    ch = ch & 0b00000111;
    ADMUX = (ADMUX & 0xf8) | ch; 

    // start single conversion
    ADCSRA |= (1 << ADSC);

    // wait for  conversion to complete
    while ( (ADCSRA & (1<<ADSC)));

    return ( ADC ); 
} 

