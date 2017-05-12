#include "menu.h"

#include "drawing.h"
#include "text.h"
#include "colour.h"
#include "input.h"
#include "sound.h"

typedef unsigned char uint8;

ChoiceBox cBox;
bool menuCreated = false;

// which menu to display.
uint8 menuLevel = 1;

void menuTick(uint8* gamestate){
    if(!menuCreated){
        createMenu();
    }
    key_poll();
    handleMenuInput(gamestate);
    menuDraw();
}

inline createMenu(){
    cBox.x = 40;
    cBox.y = 40;
    cBox.size = 10;
    menuCreated = true;
}

void menuDraw(){
    switch(menuLevel){
        case 1: drawString("GBA Pong", WHITE, 30,0);
                drawString("Single Player", WHITE, 30,20);
                drawString("Multi Player", WHITE, 30,50);
                drawRectangle(cBox.x, cBox.y, cBox.size,cBox.size, WHITE);
                break;
    }
}

void handleMenuInput(uint8* gamestate){

    if (key_is_down(KEY_UP))
        {
              const char pSample[] = {100,200,300,400,500,600};
              playSound(&pSample);
            // put a black square over our white one
            drawRectangle(cBox.x, cBox.y, cBox.size,cBox.size, BLACK);
            cBox.y = 40; // cBox position = text position / 2
        }
        else if (key_is_down(KEY_DOWN))
        {
            drawRectangle(cBox.x, cBox.y, cBox.size,cBox.size, BLACK);
            cBox.y = 100;
        }

        if(key_is_down(KEY_A)){
            if(cBox.y == 40){
                *(gamestate) = 1;
            } else if(cBox.y == 100){
                *(gamestate) = 2;
            }
        }

        if(key_is_down(KEY_START)){
            // todo: pause the game
        }
}