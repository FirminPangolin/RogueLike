#include "world.h"

World* init_data(){
    World* world = malloc(sizeof(World));
    world->player = init_player();

    return world;
}