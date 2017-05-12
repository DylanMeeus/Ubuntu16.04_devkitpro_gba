#ifndef MENU_H
#define MENU_H

#include <stdbool.h>
#include "gba.h"

typedef struct ChoiceBox ChoiceBox;

struct ChoiceBox{
    int x;
    int y;
    int size;
};

void menuTick();
void handleMenuInput();

#endif