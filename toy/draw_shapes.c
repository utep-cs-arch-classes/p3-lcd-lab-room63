#include "draw_shapes.h"    
#include "switches.h"

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
u_int controlFontColor = COLOR_GREEN;


// Color of the shape.
unsigned int SHAPE_COLOR = COLOR_DARK_VIOLE;

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

    // draw triangles on horizontal way 
    fillRectangle(endCol+30, row*step, width, 1, COLOR_BLACK);
   
    /* Make shadow of hot pink color to the violet shape   (violet is the original color of the shape) */
    
    if (switches & SW1)
    { // first button
      SHAPE_COLOR = COLOR_HOT_PINK;
  
    }
        /* Make shadow of gold color to the violet shape   (violet is the original color of the shape) */
    // second button.
    if (switches & SW2)
    {
      SHAPE_COLOR = COLOR_GOLD;
     
    }
        /* Make shadow of aquamarine color to the violet shape   (violet is the original color of the shape) */
    // third button.
    if (switches & SW3)
    {
      SHAPE_COLOR = COLOR_AQUAMARINE;
     
    }
        /* Make shadow of black color to the violet shape   (violet is the original color of the shape) */
    // four button.
    if (switches & SW4)
    {
      
       clearScreen(COLOR_RED);
    }
    step ++;
    
  }
  else
  {

    // move the shape to the left
    col -= colStep;
    
    clearScreen(COLOR_GOLDENROD); // clear the screen with color goldenrod
    clearScreen(COLOR_TAN);     // clear the screen with color tan
     step = 0;
  }
}


