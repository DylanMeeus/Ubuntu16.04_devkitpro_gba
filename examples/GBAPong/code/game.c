#include "game.h"

#include "text.h"

typedef unsigned char      uint8;

Paddle bot; // the bot-player
Player player;
Ball ball;

ballSize = 7;
paddleHeight = 20;
paddleWidth = 5;

uint8 botScore = 0;
uint8 playerScore = 0;

bool initialised = false;
bool roundStarted = false;

uint8 mode = 0; // in mode two, a second player takes control over our bot

/*
* One tick in the game.
* Progress game state, and draw
* Here, gamestate represents gamemode
*/
void gameTick(uint8* gamemode){
    mode = *(gamemode);
    updateState();
    draw();
}


void updateState(){

    if(initialised){
        key_poll();
        handleGameInput();

        if(roundStarted){
            if(mode == 1){
                paddleBotMove(&bot,&ball);
            }
            moveBall(&ball);
            checkBallCollision(&ball,&bot,&player);
            checkRoundOver();
        }
    } else {
        initGame();
        initialised = true;
    }

}


/*
* Check the state of the round.
*/
void checkRoundOver(){
    // the game is over if there is a collision with the left / right wall.

    if(ball.x <= 0){
        botScore++;
        roundStarted = false;
        resetRound();
    }

    if(ball.x+ball.width >= SCREEN_WIDTH){
        playerScore++;
        roundStarted = false;
        resetRound();
    }
}

/*
* Set round state to the beginning.
*/
void resetRound(){
    // reset the area!
    drawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,BLACK);
    createBall(&ball,SCREEN_WIDTH >> 1,SCREEN_HEIGHT >> 1,ballSize,ballSize);
}

/*
* Setup of the game
*/
void initGame(){
    createPaddle(&bot,SCREEN_WIDTH - paddleWidth - 10,((SCREEN_HEIGHT >> 1) - (paddleHeight>>1)),2,paddleHeight,paddleWidth);
    createPlayer(&player, 10,((SCREEN_HEIGHT >> 1) - (paddleHeight>>1)),paddleHeight,paddleWidth);
    // setup ball in the middle of the screen.
    createBall(&ball,SCREEN_WIDTH >> 1,SCREEN_HEIGHT >> 1,ballSize,ballSize);
}


/*
* Draw elements on the screen, the order of the renderer decides what will be 'on top'
*/
void draw(){
    renderLine();
    renderPaddle(&bot);
    renderPlayer(&player);
    renderBall(&ball);
    renderScore();
}

void renderLine(){

    for(int i = 0; i < SCREEN_HEIGHT; i+=10){
        drawRectangle(SCREEN_WIDTH>>1,i,2,9,WHITE);
    }

}

void renderScore(){
    char playerScoreString[16];
    char botScoreString[16];
    sprintf(playerScoreString, "%d", playerScore);
    sprintf(botScoreString, "%d", botScore);
    drawString(playerScoreString,WHITE,(SCREEN_WIDTH / 2)-7,5);
    drawString(botScoreString,WHITE,(SCREEN_WIDTH / 2)+5,5);
}

void handleGameInput()
{
    if (key_is_down(KEY_UP))
    {
        paddleUp(player.paddle);
    }
    else if (key_is_down(KEY_DOWN))
    {
        paddleDown(player.paddle);
    }

    if(key_is_down(KEY_A)){
        if(!roundStarted){
            setBallVelocity(&ball, 2,2);
            roundStarted = true;
        }
    }

    if(key_is_down(KEY_START)){
        // todo: pause the game
    }


    // check for input for our user-controller bot
    if(mode == 2){
        if (key_is_down(KEY_LEFT))
        {
            paddleUp(&bot);
        }
        else if (key_is_down(KEY_RIGHT))
        {
            paddleDown(&bot);
        }
    }

}
