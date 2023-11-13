#include<mega16.h>
#define xtal 1000000

/* the I2C bus is connected to PORTB */
/* the SDA signal is bit 3 */
/* the SCL signal is bit 4 */

#asm

    .equ __i2c_port=0x18
    .equ __sda_bit=3
    .equ __scl_bit=4

#endasm

/* now you can include the I2C Functions */

#include <i2c.h>

/* function declaration for delay_ms */
#include <delay.h>

#define EEPROM_BUS_ADDRESS 0xa0

/* read a byte from the EEPROM */
unsigned char eeprom_read(unsigned char address) {
unsigned char data;
i2c_start();
i2c_write(EEPROM_BUS_ADDRESS);
i2c_write(address);
i2c_start();
i2c_write(EEPROM_BUS_ADDRESS | 1);
data=i2c_read(0);
i2c_stop();
return data;
}

/* write a byte to the EEPROM */
void eeprom_write(unsigned char address, unsigned char data) {

i2c_start();
i2c_write(EEPROM_BUS_ADDRESS);
i2c_write(address);
i2c_write(data);
i2c_stop();

/* 10ms delay to complete the write operation */
delay_ms(10);
}

void main(void) {
unsigned char i; 
DDRD=0xFF;

/* initialize the I2C bus */
i2c_init();

/* write the byte 55h at address 10h */
eeprom_write(0x10,0x55);

/* read the byte from address AAh */
i=eeprom_read(0x10);
PORTD=i;

while (1); /* loop forever */
} 
