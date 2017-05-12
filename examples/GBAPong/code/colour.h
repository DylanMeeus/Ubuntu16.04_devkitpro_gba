#ifndef COLOUR_H
#define COLOUR_H

// colours

#define CYAN 0x339c8
#define BLACK 0x00000
#define WHITE 0xffffff

typedef unsigned char   uint8;
typedef unsigned short  uint16;



/*
 * Create a colour: http://www.coranac.com/tonc/text/
 */
inline uint16 MakeColour(uint8 red, uint8 green, uint8 blue)
{
    return red | green << 5 | blue << 10;
}

#endif