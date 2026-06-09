#ifndef __WORLD__H__
#define __WORLD__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "room.h"

typedef struct World{
    Player* player;
    int map[MAP_SIZE][MAP_SIZE];
} World;

World* init_data();

#endif