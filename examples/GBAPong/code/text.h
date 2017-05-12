#ifndef TEXT_H
#define TEXT_H
#include "gba.h"

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;

void drawString(char* msg, uint16 textCol, int x, int y);

#endif
