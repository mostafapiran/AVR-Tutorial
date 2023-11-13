#include <mega32.h>
#include <delay.h>

#define led PORTA.1

void main(void)
{
    DDRA = 0x02;
    
    while (1)
    {
        led=1;
        delay_ms(1000);
        led=0;
        delay_ms(1000);  
    }
}
