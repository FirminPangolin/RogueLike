#include "room.h"
#include "constants.h"

Room*** init_map(){
    Room*** map[MAP_SIZE][MAP_SIZE] = malloc(MAP_SIZE * MAP_SIZE * sizeof(Room));
    
    return map;
}

void init_all_rooms(Room*** map){
    for (int i = 0 ; i < MAP_SIZE ; i++){
        for (int j = 0 ; j < MAP_SIZE ; j++){
            init_room(map[i][j]);
        } 
    }
}

void init_room(Room* room){
    room->exists = 1;
    
    room->up = 1;
    room->right = 1;
    room->down = 1;
    room->left = 1;

    room->type = 1;
} 