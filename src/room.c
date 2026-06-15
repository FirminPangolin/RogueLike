#include "room.h"
#include "constants.h"

void gen_matrice(int room[MAP_SIZE][MAP_SIZE]){
    for (int i = 0 ; i < MAP_SIZE ; i ++){
        for (int j = 0 ; j < MAP_SIZE ; j ++){
            room[i][j] = rand()%2; //Entre  0 et 1
        }
    }
}

void init_all_rooms(World* world){
    //Inits
    for (int i = 0 ; i < MAP_SIZE ; i++){
        for (int j = 0 ; j < MAP_SIZE ; j++){
            if (world->map[i][j] == 1){
                world->rooms[i][j] = init_room(world, i, j);
                if (world->act_room == NULL){
                    world->act_room = world->rooms[i][j];
                }
            }
            else{
                world->rooms[i][j] = NULL;
            }
        }
    }

    //Links
    for (int i = 0 ; i < MAP_SIZE ; i++){
        for (int j = 0 ; j < MAP_SIZE ; j++){
            Room* r = world->rooms[i][j];
            if (r == NULL) continue;
            r->up = (i > 0) ? world->rooms[i - 1][j] : NULL;
            r->down = (i < MAP_SIZE - 1) ? world->rooms[i + 1][j] : NULL;
            r->left = (j > 0) ? world->rooms[i][j - 1] : NULL;
            r->right = (j < MAP_SIZE - 1) ? world->rooms[i][j + 1] : NULL;
        }
    }
}

Room* init_room(World* world, int i, int j){
    Room* room = malloc(sizeof(Room));
    room->exists = 1;
    room->up = room->right = room->down = room->left = NULL;
    room->row = i;
    room->column = j;
    room->type = rand()%2;

    return room;
}