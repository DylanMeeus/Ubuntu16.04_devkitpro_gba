#include "drawing.h"

typedef unsigned short  uint16;

void drawRectangle(int left, int top, int width, int height, uint16 clr)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
    	   SCREEN_BUFFER[(top + y) * SCREEN_WIDTH + left + x] = clr;
        }
    }
}

