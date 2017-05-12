#include "gba.h"
#include "colour.h"
#include "drawing.h"
#include "game.h"
#include "menu.h"
#include "sound.h"

// type defintions
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;



uint8 gamestate = 0;
/*
* Do nothing when in VBlank / HBlank
*/
inline void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}

int main()
{
    REG_DISPLAYCONTROL = VIDEO_MODE | BG_MODE; //mode 3 graphics, we aren't actually using bg2 right now



    // game loop
    while(1)
	{

        uint8 oldState = gamestate;
        vsync();
        if(gamestate == 0){ // in menu
            menuTick(&gamestate);
        } else{  // in game
            gameTick(&gamestate);
        }

        // our game state changed during a tick, so we wipe the screen
        if(oldState != gamestate){
            drawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,BLACK);
        }
	}

    return 0;
}

