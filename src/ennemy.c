#include "ennemy.h"
#include <math.h>

Ennemy* create_ennemy(){
    Ennemy* ennemy = malloc(sizeof(Ennemy));

    ennemy->x = rand()%SCREEN_WIDTH;
    ennemy->y = rand()%SCREEN_HEIGHT;

    ennemy->width = ENNEMY_INIT_WIDTH;
    ennemy->height = ENNEMY_INIT_HEIGHT;

    ennemy->speed = PLAYER_INIT_SPEED;
    ennemy->health = 1;

    return ennemy;
}

Ennemy** create_room_ennemies(World* world){
    int nbEnnenmyInRoom = maxi(rand()%NB_ENNEMIES, 4);
    Ennemy** ennemies = malloc(nbEnnenmyInRoom * sizeof(Ennemy*));
    for (int i = 0 ; i < nbEnnenmyInRoom ; i++){
        ennemies[i] = create_ennemy();
        world->nbEnnemies += 1;
    }
    
    return ennemies;
}

void ennemy_movement(World* world, Ennemy** ennemies){
    for (int i = 0 ; i < world->nbEnnemies ; i++){
        Ennemy* ennemy = ennemies[i];

        float dist_x = (float)world->player->x - (float)ennemy->x;
        float dist_y = (float)world->player->y - (float)ennemy->y;
        float dist_tot = sqrtf(squared(dist_x) + squared(dist_y));

        if (dist_tot > 0.0f){
            float new_x = dist_x / dist_tot;
            float new_y = dist_y / dist_tot;
            ennemy->x += (int)(new_x * ennemy->speed);
            ennemy->y += (int)(new_y * ennemy->speed); 
        }
    }
}

void free_ennemy(World* world, Ennemy* ennemy, int i){
    free(ennemy);
    //Décalement
    for (int j = i; j < world->nbEnnemies - 1; j++){
        world->ennemies[j] = world->ennemies[j + 1];
    }
    world->nbEnnemies --;
}