#ifndef __BULLET_H__
#define __BULLET_H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "constants.h"
#include "world.h"

typedef struct Bullet{
    //Position
    int x;
    int y;

    //Taille
    int width;
    int height;

    //Données
    float speedX;
    float speedY;
} Bullet;

typedef struct Player Player;

void create_bullet(Player* player);
void free_bullet(World* world, Bullet* bullet, int i);

#endif