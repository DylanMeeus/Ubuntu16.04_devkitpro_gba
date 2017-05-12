#ifndef BALL_H
#define BALL_H


#include "colour.h"
#include "paddle.h"
#include "player.h"
#include "gba.h"

typedef struct Ball Ball;

struct Ball{

    int x;
    int y;
    int r; // radius for the future

    int height;
    int width;

    // velocities
    int velX;
    int velY;

    // variables to clean up screen
    int oldX;
    int oldY;


};

void setBallVelocity(Ball* ball, int velX, int velY);
void createBall(Ball* ball, int x, int y, int h, int w);
void renderBall(Ball* ball);
void moveBall(Ball* ball);
void checkBallCollision(Ball* ball, Paddle* bot, Player* player);

#endif