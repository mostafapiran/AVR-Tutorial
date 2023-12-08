/*
 * Quick and dirty PWM Demo
 */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include "pinDefines.h"

#define LED_DELAY 2

int main(void) {

  uint8_t brightness = 0;
  int8_t direction = 1;
  uint8_t i;

  // -------- Inits --------- //

  LED_DDR = 0xff;                                     /* Init all LEDs */

  // ------ Event loop ------ //
  while (1) {

    // PWM
    for (i = 0; i < 255; i++) {
      if (i < brightness) {
        LED_PORT = 0xff;                                    /* turn on */
      }
      else {
        LED_PORT = 0;                                      /* turn off */
      }
      _delay_us(LED_DELAY);
    }

    // Brighten and dim
    if (brightness == 0) {
      direction = 1;
    }
    if (brightness == 255) {
      direction = -1;
    }
    brightness += direction;

  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
