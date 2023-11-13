// main.c

#include "prj.h"

/******************************************************************
  Project     : Led brightness using pwm control
  Description : 
  MCU         : MEGA16
  F_OSC       : 7.3728 MHz
  IDE         : AVR Studio 4.18
  Library     : WinAVR-20100110
  Date        : 2018-02-09
  Version     : 
  History     : 

  Note
  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of  
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
******************************************************************/
  
 
 
//==============================================
void init()
{
    key_init();
    Lcm1_Init();
   
    Led1_DIR |= _BV(Led1_BIT) ;

     
}
 
//==============================================
void fast_pwm_setup()
{
   // TCCR0 : OC0 WGM00 COM01 COM00 | WGM01 CS02 CS01 CS00
   
  
   TCCR0|=   (1<<WGM00) | (1<<WGM01)  // fast pwm
           | (1<<COM01) | (1<<COM00)  // inverted pwm
           | (1<<CS02)   ;  // divier 256

}

// duty : 0 ~ 100
//==============================================
void SetPWMOutput(uint8_t duty)
{
    OCR0 = (int) (255.0 * duty / 100);
}
 
 
//==============================================
int main()
{ 

    init();  
    sei();  // enable interrupt

    Lcm1_ShowString_xy(0,0,"Fast PWM");
    Lcm1_ShowString_xy(0,1,"v001");    

    fast_pwm_setup();
    Lcm1_ShowString_xy(0,1,"duty cycle = 20%");  
    SetPWMOutput(20); // 20%

    while(1)
    {        
        if (Key1_press())
        {
			_delay_ms(25);
            while(Key1_press());

            Lcm1_ShowString_xy(0,1,"duty cycle = 20%");  
            SetPWMOutput(20); // 20%                   
        }
       
        if (Key2_press())
        {
            _delay_ms(25);
            while(Key2_press());
            
             Lcm1_ShowString_xy(0,1,"duty cycle = 80%");  
             SetPWMOutput(80); // 80%                  
        }         
    }
}


