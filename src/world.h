#ifndef __WORLD__H__
#define __WORLD__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"

typedef struct World{
    Player* player;
} World;

World* init_data();

#endif