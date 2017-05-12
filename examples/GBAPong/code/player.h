#ifndef PLAYER_H
#define PLAYER_H

#include "paddle.h"

typedef struct Player Player;

struct Player{

    Paddle* paddle;

};


void createPlayer(Player* player, int x, int y, int h, int w);
void renderPlayer(Player* player);
void playerUp(Player* p);


#endif