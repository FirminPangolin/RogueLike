#ifndef __ENNEMY__H__
#define __ENNEMY__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "constants.h"
#include "world.h"
#include "functions.h"

typedef struct World World;

typedef struct Ennemy{
    //Position
    int x;
    int y;

    //Taille
    int width;
    int height;

    //Données
    float speed;
    int health;
    int init_health;
    int facing;
    int invincible;
    Color color;
} Ennemy;

Ennemy* create_ennemy();
Ennemy** create_room_ennemies(World* world);
void ennemy_movement(World* world, Ennemy** ennemy);
void free_ennemy(World* world, Ennemy* ennemy, int i);

#endif