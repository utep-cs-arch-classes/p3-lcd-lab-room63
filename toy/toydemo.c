#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h" // color fonts definition.
#include "lcddraw.h" 
#include "draw_shapes.h"
#include "switches.h"
// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 
void buzzer_init();
void update_shape();

void main()
{
  
  P1DIR |= LED;		/**< Led on when CPU on */
  P1OUT |= LED;
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {

      drawString5x7(14,5, "D: I need to pass5x7", COLOR_GREEN, COLOR_BLACK);
      
      // drawString5x7(8, 120, "Where is the main?", COLOR_GREEN, COLOR_BLACK);
      //drawString5x7(12, 140," I don't know 5x7", COLOR_GREEN, COLOR_BLACK);
      redrawScreen = 0;
      update_shape();  //  update the new shape(arrow).
    }
    P1OUT &= ~LED;	/* led off */
    or_sr(0x10);	/**< CPU OFF */
    P1OUT |= LED;	/* led on */
  }
}
