
    
#include "prj.h"


//---------------------------------------
//  HD44780U LCD 4bit library
//--------------------------------------- 


// delay
//========================== 
#define Lcm1_e_delay()   _delay_us(LCD_DELAY_ENABLE_PULSE)
#define delay(us)       _delay_us(us) 

#define Lcm1_e_high()    Lcm1_EN_PORT  |=  _BV(Lcm1_EN_BIT);
#define Lcm1_e_low()     Lcm1_EN_PORT  &= ~_BV(Lcm1_EN_BIT);
#define Lcm1_rw_high()   Lcm1_RW_PORT |=  _BV(Lcm1_RW_BIT)
#define Lcm1_rw_low()    Lcm1_RW_PORT &= ~_BV(Lcm1_RW_BIT)
#define Lcm1_rs_high()   Lcm1_RS_PORT |=  _BV(Lcm1_RS_BIT)
#define Lcm1_rs_low()    Lcm1_RS_PORT &= ~_BV(Lcm1_RS_BIT)
 
#define Lcm1_d4_high()    Lcm1_D4_PORT  |=  _BV(Lcm1_D4_BIT);
#define Lcm1_d4_low()     Lcm1_D4_PORT  &= ~_BV(Lcm1_D4_BIT);
#define Lcm1_d5_high()    Lcm1_D5_PORT  |=  _BV(Lcm1_D5_BIT);
#define Lcm1_d5_low()     Lcm1_D5_PORT  &= ~_BV(Lcm1_D5_BIT);
#define Lcm1_d6_high()    Lcm1_D6_PORT  |=  _BV(Lcm1_D6_BIT);
#define Lcm1_d6_low()     Lcm1_D6_PORT  &= ~_BV(Lcm1_D6_BIT);
#define Lcm1_d7_high()    Lcm1_D7_PORT  |=  _BV(Lcm1_D7_BIT);
#define Lcm1_d7_low()     Lcm1_D7_PORT  &= ~_BV(Lcm1_D7_BIT);
 

#if LCD_LINES==1
    #define LCD_FUNCTION_DEFAULT    LCD_FUNCTION_4BIT_1LINE 
#else
    #define LCD_FUNCTION_DEFAULT    LCD_FUNCTION_4BIT_2LINES 
#endif
 

//=====================
// Enable pin toggle
//=====================
void Lcm1_e_toggle()  
{
    Lcm1_e_high();
    Lcm1_e_delay();
    Lcm1_e_low();
}

void Lcm1_set_data_as_output()
{
    // configure data pins as output 
    Lcm1_D4_DIR |= _BV(Lcm1_D4_BIT);
    Lcm1_D5_DIR |= _BV(Lcm1_D5_BIT);
    Lcm1_D6_DIR |= _BV(Lcm1_D6_BIT);
    Lcm1_D7_DIR |= _BV(Lcm1_D7_BIT);
}

void Lcm1_set_data_as_input()
{
    //    configure data pins as input 
    Lcm1_D4_DIR &= ~_BV(Lcm1_D4_BIT);
    Lcm1_D5_DIR &= ~_BV(Lcm1_D5_BIT);
    Lcm1_D6_DIR &= ~_BV(Lcm1_D6_BIT);
    Lcm1_D7_DIR &= ~_BV(Lcm1_D7_BIT);
}

void Lcm1_set_data_all_low()
{
    //    configure data pins as input 
    Lcm1_d4_low();
    Lcm1_d5_low();;
    Lcm1_d6_low();
    Lcm1_d7_low();
}

void Lcm1_set_data_all_high()
{
    //    configure data pins as input 
    Lcm1_d4_high();
    Lcm1_d5_high();
    Lcm1_d6_high();
    Lcm1_d7_high();
}

 
//=========================================================================
// Input:  
//  data  : byte to write to LCD
//  rs =1 : write data    
//     =0 : write instruction
//=========================================================================
void Lcm1_write(uint8_t data,uint8_t rs) 
{
   

    if (rs) {        // write data        (RS=1, RW=0) 
       Lcm1_rs_high();
    } else {         // write instruction (RS=0, RW=0) 
       Lcm1_rs_low();
    }
    Lcm1_rw_low();    // RW=0  write mode      

      
    Lcm1_set_data_as_output();
        
    // output high nibble first 
	Lcm1_set_data_all_low();
 
    if(data & 0x80) Lcm1_d7_high();
    if(data & 0x40) Lcm1_d6_high();
    if(data & 0x20) Lcm1_d5_high();
    if(data & 0x10) Lcm1_d4_high();  
    Lcm1_e_toggle();
    
    // output low nibble 
	Lcm1_set_data_all_low();
    if(data & 0x08) Lcm1_d7_high();
    if(data & 0x04) Lcm1_d6_high();
    if(data & 0x02) Lcm1_d5_high();
    if(data & 0x01) Lcm1_d4_high();
    Lcm1_e_toggle();        
    
    // all data pins high (inactive)
	Lcm1_set_data_all_high();	     
}
 
//=========================================================================
// read byte from LCD controller
// Input:    rs     1: read data    
//                  0: read busy flag / address counter
//=========================================================================
uint8_t Lcm1_read(uint8_t rs) 
{
    uint8_t data;
     
    if (rs)
        Lcm1_rs_high();  // RS=1 : read data
    else
        Lcm1_rs_low();   // RS=0 : read busy flag 
    Lcm1_rw_high();      // RW=1  read mode      
    
    Lcm1_set_data_as_input();
    
    //  read high nibble first 
    Lcm1_e_high();
    Lcm1_e_delay();        
    data = 0;
    if ( Lcm1_D4_PIN & _BV(Lcm1_D4_BIT) ) data |= 0x10;
    if ( Lcm1_D5_PIN & _BV(Lcm1_D5_BIT) ) data |= 0x20;
    if ( Lcm1_D6_PIN & _BV(Lcm1_D6_BIT) ) data |= 0x40;
    if ( Lcm1_D7_PIN & _BV(Lcm1_D7_BIT) ) data |= 0x80;
    Lcm1_e_low();

    Lcm1_e_delay();  // Enable 500ns low  
    
    // read low nibble 
    Lcm1_e_high();
    Lcm1_e_delay();
    if ( Lcm1_D4_PIN & _BV(Lcm1_D4_BIT) ) data |= 0x01;
    if ( Lcm1_D5_PIN & _BV(Lcm1_D5_BIT) ) data |= 0x02;
    if ( Lcm1_D6_PIN & _BV(Lcm1_D6_BIT) ) data |= 0x04;
    if ( Lcm1_D7_PIN & _BV(Lcm1_D7_BIT) ) data |= 0x08;        
    Lcm1_e_low();
    
    return data;
}
 
 
//=========================================================================
// loops while lcd is busy, returns address counter
//=========================================================================
uint8_t Lcm1_waitbusy(void)
{
    register uint8_t c;
    
    // wait until busy flag is cleared 
    while ( (c=Lcm1_read(0)) & (1<<LCD_BUSY)) {}
    
    // the address counter is updated 4us after the busy flag is cleared 
    delay(LCD_DELAY_BUSY_FLAG);

    // now read the address counter 
    return (Lcm1_read(0));  
    
} 
 
//=========================================================================
// Move cursor to the start of next line or to the first line if the cursor 
// is already on the last line.
//=========================================================================
inline void Lcm1_newline(uint8_t pos)
{
    register uint8_t addressCounter;

#if LCD_LINES==1
    addressCounter = 0;
#endif
#if LCD_LINES==2
    if ( pos < (LCD_START_LINE2) )
        addressCounter = LCD_START_LINE2;
    else
        addressCounter = LCD_START_LINE1;
#endif
#if LCD_LINES==4
 
    if ( pos < LCD_START_LINE3 )
        addressCounter = LCD_START_LINE2;
    else if ( (pos >= LCD_START_LINE2) && (pos < LCD_START_LINE4) )
        addressCounter = LCD_START_LINE3;
    else if ( (pos >= LCD_START_LINE3) && (pos < LCD_START_LINE2) )
        addressCounter = LCD_START_LINE4;
    else 
        addressCounter = LCD_START_LINE1;
 
#endif
    Lcm1_command((1<<LCD_DDRAM)+addressCounter);

} 
 
//=========================================================================
// Send LCD controller instruction command
//=========================================================================
void Lcm1_command(uint8_t cmd)
{
    Lcm1_waitbusy();
    Lcm1_write(cmd,0); // rs = 0
}
 
//=========================================================================
// Send data byte to LCD controller 
//=========================================================================
void Lcm1_data(uint8_t data)
{
    Lcm1_waitbusy();
    Lcm1_write(data,1); // rs = 1
}

 
//=========================================================================
//Set cursor to specified position
//Input:    x  horizontal position  (0 ~ 20)
//          y  vertical position    (0 ~ 3)
//=========================================================================
void Lcm1_SetCursor(uint8_t x, uint8_t y)
{
#if LCD_LINES==1
    Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE1+x);
#endif

#if LCD_LINES==2
    if ( y==0 ) 
        Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE1+x);
    else
        Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE2+x);
#endif

#if LCD_LINES==4
    if ( y==0 )
        Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE1+x);
    else if ( y==1)
        Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE2+x);
    else if ( y==2)
        Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE3+x);
    else /* y==3 */
        Lcm1_command((1<<LCD_DDRAM)+LCD_START_LINE4+x);
#endif

}  

int Lcm1_getxy(void)
{
    return Lcm1_waitbusy();
}

//=========================================================================
// Clear display and set cursor to home position 
//=========================================================================
void Lcm1_Clearscreen(void)
{
    Lcm1_command(1<<LCD_CLR);
}
 
//=========================================================================
// Set cursor to home position
//=========================================================================
void Lcm1_home(void)
{
    Lcm1_command(1<<LCD_HOME);
}
 
//=========================================================================
// Display character at current cursor position 
//=========================================================================
void Lcm1_putc(char c)
{
    uint8_t pos;

    pos = Lcm1_waitbusy();   // read busy-flag and address counter
    if (c=='\n')
    {
        Lcm1_newline(pos);
    }
    else
    {
#if LCD_WRAP_LINES==1
#if LCD_LINES==1
        if ( pos == LCD_START_LINE1+LCD_DISP_LENGTH ) {
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE1,0);
        }
#elif LCD_LINES==2
        if ( pos == LCD_START_LINE1+LCD_DISP_LENGTH ) {
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE2,0);    
        }else if ( pos == LCD_START_LINE2+LCD_DISP_LENGTH ){
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE1,0);
        }
#elif LCD_LINES==4
        if ( pos == LCD_START_LINE1+LCD_DISP_LENGTH ) {
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE2,0);    
        }else if ( pos == LCD_START_LINE2+LCD_DISP_LENGTH ) {
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE3,0);
        }else if ( pos == LCD_START_LINE3+LCD_DISP_LENGTH ) {
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE4,0);
        }else if ( pos == LCD_START_LINE4+LCD_DISP_LENGTH ) {
            Lcm1_write((1<<LCD_DDRAM)+LCD_START_LINE1,0);
        }
#endif
        Lcm1_waitbusy();
#endif
        Lcm1_write(c, 1);
    }
}

 
//=========================================================================
// Display string without auto linefeed 
//=========================================================================
void Lcm1_ShowString(const char *s)
{
    register char c;

    while ( (c = *s++) ) 
    {
        Lcm1_putc(c);
    }
} 

//=========================================================================
// Display string without auto linefeed 
//=========================================================================
void Lcm1_ShowString_xy(uint8_t x, uint8_t y, const char *s)
{
    register char c;

    Lcm1_SetCursor(x,y);
    while ( (c = *s++) ) 
    {
        Lcm1_putc(c);
    }
} 
 
//=========================================================================
// Display string from program memory without auto linefeed 
//=========================================================================
void Lcm1_puts_p(const char *progmem_s)
{
    register char c;

    while ( (c = pgm_read_byte(progmem_s++)) )
     {
        Lcm1_putc(c);
    }

}
 

//=========================================================================
// Init
//Input:    dispAttr LCD_DISP_OFF               display off
//                   LCD_DISP_ON                display on, cursor off
//                   LCD_DISP_ON_CURSOR         display on, cursor on
//                   LCD_DISP_ON_CURSOR_BLINK   display on, cursor on flashing
//=========================================================================
void Lcm1_Init()
{
    // Set as output 
    Lcm1_RS_DIR  |= _BV(Lcm1_RS_BIT);
    Lcm1_RW_DIR  |= _BV(Lcm1_RW_BIT);
    Lcm1_EN_DIR  |= _BV(Lcm1_EN_BIT);

    Lcm1_set_data_as_output();

    delay(LCD_DELAY_BOOTUP);    // wait 16ms or more after power-on       
    
    // 0011
	Lcm1_d4_high();
	Lcm1_d5_high();     
    Lcm1_e_toggle();
    delay(LCD_DELAY_INIT);      // delay, busy flag can't be checked here 
   
    // repeat last command 
    Lcm1_e_toggle();      
    delay(LCD_DELAY_INIT_REP);  // delay, busy flag can't be checked here 
    
    // repeat last command a third time 
    Lcm1_e_toggle();      
    delay(LCD_DELAY_INIT_REP);  // delay, busy flag can't be checked here 

    // 0010
	Lcm1_d4_low();    
    Lcm1_e_toggle();
    delay(LCD_DELAY_INIT_4BIT); // some displays need this additional delay 
    
    Lcm1_command(LCD_FUNCTION_DEFAULT);      // function set: display lines  
    Lcm1_command(LCD_DISP_OFF);              // display off                  
    Lcm1_Clearscreen();                           // display clear                 
    Lcm1_command(LCD_MODE_DEFAULT);          // set entry mode               
    Lcm1_command(LCD_DISP_ON);                  // display/cursor control       

}


void Lcm1_ClearLine_xy(int x, int y)
{
    int i;
    Lcm1_SetCursor(x,y);
    for (i=x;  i<LCD_DISP_LENGTH; i++)
    {
        Lcm1_putc(' ');
    }
    Lcm1_SetCursor(x,y);

}
