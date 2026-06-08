#ifndef __ROOM__H__
#define __ROOM__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "constants.h"


typedef struct Room{
    bool exists;

    bool up;
    bool right;
    bool down;
    bool left;

    int type; //A voir plus tard
} Room;

Room* init_map();


#endif