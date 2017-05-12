#include "ball.h"


void createBall(Ball* ball, int x, int y, int h, int w){
    ball->x = x;
    ball->y = y;
    ball->height = h;
    ball->width = w;

    // initial velocity
    ball->velX = 0;
    ball->velY = 0;
}


void setBallVelocity(Ball* ball, int velX, int velY){
    ball->velX = velX;
    ball->velY = velY;
}


void renderBall(Ball* ball){

    if(ball->oldX != ball->x || ball->y != ball->oldY){
        // clear previous rectangle space
        drawRectangle(ball->oldX,ball->oldY,ball->width,ball->height,BLACK);
    }
    drawRectangle(ball->x,ball->y,ball->width,ball->height,CYAN);
    ball->oldX = ball->x;
    ball->oldY = ball->y;
}

void moveBall(Ball* ball){
    ball->x += ball->velX;
    ball->y += ball->velY;
}


void checkBallCollision(Ball* ball, Paddle* bot, Player* player){
    // bot paddle check
    if (((ball->x + ball->width) >= bot->x
            && (ball->x + ball->width) <= (bot->x + bot->width))
            && (ball->y + ball->height) >= bot->y
            && (ball->y) <= (bot->y + bot->height)
            ){
        reverseVelocityX(ball);
    }
     // player check
    if(
        (ball->x) <= (player->paddle->x + player->paddle->width)
          && (ball->x) >= (player->paddle->x)
          && ball->y + ball->height >= player->paddle->y
          && (ball->y) < (player->paddle->y + player->paddle->height)
    ){
        reverseVelocityX(ball);
    }

    // check roof and floor collision
    if((ball->y) <= 0){
        reverseVelocityY(ball);
    } else if ((ball->y + ball->height)>= SCREEN_HEIGHT){
        reverseVelocityY(ball);
    }

}


inline reverseVelocityX(Ball* ball){
    ball->velX *= -1;
}

inline reverseVelocityY(Ball* ball){
    ball->velY *= -1;
}