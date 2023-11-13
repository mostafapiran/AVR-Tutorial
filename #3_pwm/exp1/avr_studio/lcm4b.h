#ifndef _LCM4B_H
#define _LCM4B_H

#include "prj.h"

#define LCD_LINES           2     /* number of visible lines of the display */  
#define LCD_DISP_LENGTH    16     /* visibles characters per line of the display */ 


#define LCD_LINE_LENGTH  0x40     /* internal line length of the display    */ 
#define LCD_START_LINE1  0x00     /* DDRAM address of first char of line 1 */ 
#define LCD_START_LINE2  0x40     /* DDRAM address of first char of line 2 */ 
#define LCD_START_LINE3  0x14     /* DDRAM address of first char of line 3 */ 
#define LCD_START_LINE4  0x54     /* DDRAM address of first char of line 4 */ 
#define LCD_WRAP_LINES      0     /* 0: no wrap, 1: wrap at end of visibile line */


// delay time in micro second 
#define LCD_DELAY_BOOTUP   16000  /* delay in micro seconds after power-on  */
#define LCD_DELAY_INIT      5000  /* delay in micro seconds after initialization command sent  */
#define LCD_DELAY_INIT_REP    64  /* delay in micro seconds after initialization command repeated */
#define LCD_DELAY_INIT_4BIT   64  /* delay in micro seconds after setting 4-bit mode */ 
#define LCD_DELAY_BUSY_FLAG    4  /* time in micro seconds the address counter is updated after busy flag is cleared */
#define LCD_DELAY_ENABLE_PULSE 1  /* enable signal pulse width in micro seconds */

// instruction register bit positions, see HD44780U data sheet 
#define LCD_CLR               0      /* DB0: clear display                  */
#define LCD_HOME              1      /* DB1: return to home position        */
#define LCD_ENTRY_MODE        2      /* DB2: set entry mode                 */
#define LCD_ENTRY_INC         1      /*   DB1: 1=increment, 0=decrement     */
#define LCD_ENTRY_SHIFT       0      /*   DB2: 1=display shift on           */
#define LCD_ON                3      /* DB3: turn lcd/cursor on             */
#define LCD_ON_DISPLAY        2      /*   DB2: turn display on              */
#define LCD_ON_CURSOR         1      /*   DB1: turn cursor on               */
#define LCD_ON_BLINK          0      /*     DB0: blinking cursor ?          */
#define LCD_MOVE              4      /* DB4: move cursor/display            */
#define LCD_MOVE_DISP         3      /*   DB3: move display (0-> cursor) ?  */
#define LCD_MOVE_RIGHT        2      /*   DB2: move right (0-> left) ?      */
#define LCD_FUNCTION          5      /* DB5: function set                   */
#define LCD_FUNCTION_8BIT     4      /*   DB4: set 8BIT mode (0->4BIT mode) */
#define LCD_FUNCTION_2LINES   3      /*   DB3: two lines (0->one line)      */
#define LCD_FUNCTION_10DOTS   2      /*   DB2: 5x10 font (0->5x7 font)      */
#define LCD_CGRAM             6      /* DB6: set CG RAM address             */
#define LCD_DDRAM             7      /* DB7: set DD RAM address             */
#define LCD_BUSY              7      /* DB7: LCD is busy                    */

// set entry mode: display shift on/off, dec/inc cursor move direction 
#define LCD_ENTRY_DEC            0x04   /* display shift off, dec cursor move dir */
#define LCD_ENTRY_DEC_SHIFT      0x05   /* display shift on,  dec cursor move dir */
#define LCD_ENTRY_INC_           0x06   /* display shift off, inc cursor move dir */
#define LCD_ENTRY_INC_SHIFT      0x07   /* display shift on,  inc cursor move dir */

// display on/off, cursor on/off, blinking char at cursor position 
#define LCD_DISP_OFF             0x08   /* display off                            */
#define LCD_DISP_ON              0x0C   /* display on, cursor off                 */
#define LCD_DISP_ON_BLINK        0x0D   /* display on, cursor off, blink char     */
#define LCD_DISP_ON_CURSOR       0x0E   /* display on, cursor on                  */
#define LCD_DISP_ON_CURSOR_BLINK 0x0F   /* display on, cursor on, blink char      */

// move cursor/shift display 
#define LCD_MOVE_CURSOR_LEFT     0x10   /* move cursor left  (decrement)          */
#define LCD_MOVE_CURSOR_RIGHT    0x14   /* move cursor right (increment)          */
#define LCD_MOVE_DISP_LEFT       0x18   /* shift display left                     */
#define LCD_MOVE_DISP_RIGHT      0x1C   /* shift display right                    */

// function set: set interface data length and number of display lines 
#define LCD_FUNCTION_4BIT_1LINE  0x20   /* 4-bit interface, single line, 5x7 dots */
#define LCD_FUNCTION_4BIT_2LINES 0x28   /* 4-bit interface, dual line,   5x7 dots */
#define LCD_FUNCTION_8BIT_1LINE  0x30   /* 8-bit interface, single line, 5x7 dots */
#define LCD_FUNCTION_8BIT_2LINES 0x38   /* 8-bit interface, dual line,   5x7 dots */


#define LCD_MODE_DEFAULT     ((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) )

#define lcd_puts_P(__s)         lcd_puts_p(PSTR(__s))

extern void Lcm1_Init(); 
extern void Lcm1_Clearscreen(void);
extern void Lcm1_home(void);
extern void Lcm1_SetCursor(uint8_t x, uint8_t y);
extern void Lcm1_putc(char c);
extern void Lcm1_ShowString(const char *s);
extern void Lcm1_ShowString_xy(uint8_t x, uint8_t y, const char *s);
extern void Lcm1_puts_p(const char *progmem_s);
extern void Lcm1_command(uint8_t cmd);
extern void Lcm1_data(uint8_t data);
extern void Lcm1_ClearLine_xy(int x, int y);
#endif 
