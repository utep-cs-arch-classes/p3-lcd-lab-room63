#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h" // color fonts definition.
#include "lcddraw.h" 
#include "draw_shapes.h"
#include "switches.h"
// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void update_shape();

void main()
{
  
  P1DIR |= LED;		/**< Led on when CPU on */
  P1OUT |= LED;
  configureClocks();
  lcd_init();
  switch_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {

      drawString5x7(14,5, "D: I need to pass 5x7", COLOR_GREEN, COLOR_BLACK);
      
      drawString5x7(8, 120, "This is the best I can do", COLOR_GREEN, COLOR_BLACK);
      drawString5x7(12, 140,"with a little time 5x7", COLOR_GREEN, COLOR_BLACK);
      redrawScreen = 0;
      update_shape();  //  update the new shape.
    }
    P1OUT &= ~LED;	/* led off */
    or_sr(0x10);	/**< CPU OFF */
    P1OUT |= LED;	/* led on */
  }
}
