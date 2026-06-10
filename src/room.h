#ifndef __ROOM__H__
#define __ROOM__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "constants.h"
#include "world.h"

typedef struct World World;
typedef struct Room{
    bool exists;

    struct Room* up;
    struct Room* right;
    struct Room* down;
    struct Room* left;

    int row;
    int column;

    int type; //A voir plus tard
} Room;

void gen_matrice(int room[MAP_SIZE][MAP_SIZE]);

void init_all_rooms(World* world);

Room* init_room(World* world, int i, int j);


#endif