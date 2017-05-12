#ifndef PADDLE_H
#define PADDLE_H

#include <stdbool.h>
#include "gba.h"
#include "colour.h"

typedef struct Ball Ball;

typedef struct Paddle Paddle;

struct Paddle{

    int x;
    int y;
    int height;
    int width;

    // for painting purposes
    int oldY;
    // speed at which the paddle moves up or down
    int velY;

};


void createPaddle(Paddle* paddle, int x, int y, int velY, int h, int w);
void renderPaddle(Paddle* paddle);
void paddleUp(Paddle* paddle);
void paddleDown(Paddle* paddle);
void paddleBotMove(Paddle* paddle, Ball* ball);

#endif