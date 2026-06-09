#include "world.h"

World* init_data(){
    World* world = malloc(sizeof(World));
    world->player = init_player();
    gen_matrice(world->map);
    
    for (int i = 0 ; i < MAP_SIZE ; i++){
        for (int j = 0 ; j < MAP_SIZE ; j++){
            printf("%d  ", world->map[i][j]);
        }
        printf("\n");
    }
    return world;
}