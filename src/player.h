#ifndef __PLAYER__H__
#define __PLAYER__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "constants.h"

typedef struct Bullet Bullet;

typedef struct Player{
    //Position
    int x;
    int y;

    //Taille
    int width;
    int height;

    //Données
    float speed;
    int health;
    int facing;
    int invincible;

    Bullet** bullets;
    int bullets_shot;

} Player;



Player* init_player();
void player_movement(Player* player);
void player_actions(Player* player);

#endif