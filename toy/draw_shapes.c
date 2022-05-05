#include "draw_shapes.h"    
#include "switches.h"
#include "buzzer.h"
#include "music.h"


int period = 500;
char songT = 0;



// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_GREEN;


// Color of the shape.
unsigned int SHAPE_COLOR = COLOR_DARK_VIOLE;
unsigned int SHAPE_COLOR2 = COLOR_ROYAL_BLUE;
unsigned int SHAPE_COLOR3 = COLOR_DARK_OLIVE_GREEN;
void update_shape()
{
  static unsigned char row = screenHeight / 2, col = screenWidth / 2;
  static int colStep = 5;
  static int rowStep = 5;
  static unsigned char step = 0;
  
  if (step <= 10) {
    int startCol = col - step*2;
    int endCol = col*2 + step*2;
    int width = 4 + endCol - startCol;

    // Shape drawing.
    // Shape_color means that it would be violet if not button is pressed
    // if pressed any of the button it would change to the respective colors
    // of the buttons.
    fillRectangle(endCol, row+1-step, width, 1, SHAPE_COLOR);
    fillRectangle(endCol, row+1+step, width, 1, SHAPE_COLOR);
    drawPixel(endCol+3, row, SHAPE_COLOR); 
    drawPixel(endCol+3, row-1, SHAPE_COLOR);
    drawPixel(endCol+3, row+1, SHAPE_COLOR);
    drawPixel(endCol+3, row-2, SHAPE_COLOR);
    drawPixel(endCol+3, row+2, SHAPE_COLOR);
    drawPixel(endCol+3, row-3, SHAPE_COLOR);
    drawPixel(endCol+3, row+3, SHAPE_COLOR);
    

    // Second shape 
   fillRectangle(endCol, row+11-step, width, 1, SHAPE_COLOR2);
   fillRectangle(endCol, row+11+step, width, 1, SHAPE_COLOR2);
   drawPixel(endCol+10, row-7, SHAPE_COLOR2); 
   drawPixel(endCol+10, row+7, SHAPE_COLOR2);
   drawPixel(endCol+11, row+8, SHAPE_COLOR2);
   drawPixel(endCol+11, row-8, SHAPE_COLOR2);
   drawPixel(endCol+12, row+9, SHAPE_COLOR2);
   drawPixel(endCol+12, row-9, SHAPE_COLOR2);
   drawPixel(endCol+13, row+10, SHAPE_COLOR2);


   // Third shape
   fillRectangle(endCol, row+12-step, width, 1, SHAPE_COLOR3);
   fillRectangle(endCol, row+12+step, width, 1, SHAPE_COLOR3);
   drawPixel(endCol+14, row-12, SHAPE_COLOR3); 
   drawPixel(endCol+14, row+12, SHAPE_COLOR3);
   drawPixel(endCol+15, row+13, SHAPE_COLOR3);
   drawPixel(endCol+15, row-14, SHAPE_COLOR3);
   drawPixel(endCol+16, row+14, SHAPE_COLOR3);
   drawPixel(endCol+16, row-15, SHAPE_COLOR3);
   drawPixel(endCol+17, row+15, SHAPE_COLOR3);
   
   
   
   // draw rectrangles on horizontal way 
   // fillRectangle(endCol+30, row*step, width, 1, COLOR_BLACK);
    /* Make shadow of hot pink color to the violet shape   (violet is the original color of the shape) */
    
    if (switches & SW1)
    { // first button
      SHAPE_COLOR = COLOR_HOT_PINK;
      SHAPE_COLOR2 = COLOR_GOLD;
      SHAPE_COLOR3 = COLOR_VIOLET;
      
       buzzer_set_period(0);
    }
        /* Make shadow of gold color to the violet shape   (violet is the original color of the shape) */
    // second button.
    if (switches & SW2)
    {
      SHAPE_COLOR = COLOR_BLUE;
      SHAPE_COLOR2 = COLOR_GREEN;
      SHAPE_COLOR3 = COLOR_RED;
      buzzer_set_period(0);
    }
        /* Make shadow of aquamarine color to the violet shape   (violet is the original color of the shape) */
    // third button.
    if (switches & SW3)
    {
      SHAPE_COLOR = COLOR_AQUAMARINE;
      SHAPE_COLOR2 = COLOR_MAGENTA;
      SHAPE_COLOR3 = COLOR_VIOLET;
      buzzer_set_period(0);
    }
        /* Make shadow of black color to the violet shape   (violet is the original color of the shape) */
    // four button.
    if (switches & SW4)
    {
      musicS();

    }
    step ++;
    
  }
  else
  {

    // move the shape to the left
    col -= colStep;

    
    
    clearScreen(COLOR_BLACK); // clear the screen with color black.
    // clearScreen(COLOR_TAN);     // clear the screen with color tan
     step = 0;
  }
}



