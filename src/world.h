#ifndef __WORLD__H__
#define __WORLD__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "room.h"
#include "ennemy.h"

typedef struct Room Room;
typedef struct Ennemy Ennemy;

typedef struct World{
    Player* player;
    int map[MAP_SIZE][MAP_SIZE];

    Room* rooms[MAP_SIZE][MAP_SIZE];
    Room* act_room;

    Ennemy** ennemies;
    int nbEnnemies;
} World;

World* init_data();

#endif