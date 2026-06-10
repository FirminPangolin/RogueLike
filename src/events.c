#include "events.h"
#include "constants.h"

void manage_bullets(Player* player){
    for (int i = 0 ; i < player->bullets_shot ; i ++){
        Bullet* bullet = player->bullets[i];
        //Déplacement
        bullet->x += bullet->speedX;
        bullet->y += bullet->speedY;
        
        //Sorties d'écran
        if (bullet->x > SCREEN_WIDTH || bullet->x + bullet->width < 0 || bullet->y < 0 || bullet->y + bullet->height > SCREEN_HEIGHT){
            free(bullet);
            //Décalement
            for (int j = i; j < player->bullets_shot - 1; j++){
                player->bullets[j] = player->bullets[j + 1];
            }
            player->bullets_shot--;
            i--;
        }
    }
}

void check_room_exit(World* world, Player* player){
    //haut
    if(world->act_room->up != NULL){
        if (player->x >= SCREEN_WIDTH / 2 - GATE_WIDTH / 2 && player->x <= SCREEN_WIDTH / 2 + GATE_WIDTH / 2 && player->y <= GATE_HEIGHT){
            world->act_room = world->act_room->up;
        }
    }
    //droite
    if(world->act_room->right != NULL){
        if (player->x + PLAYER_INIT_WIDTH  >= SCREEN_WIDTH - GATE_HEIGHT && player->y >= SCREEN_HEIGHT / 2 - GATE_WIDTH / 2 && player->y <= SCREEN_HEIGHT / 2 + GATE_WIDTH / 2){
            world->act_room = world->act_room->right;
        }
    }
    //bas
    if(world->act_room->down != NULL){
        if (player->x >= SCREEN_WIDTH / 2 - GATE_WIDTH / 2 && player->x <= SCREEN_WIDTH / 2 + GATE_WIDTH / 2 && player->y  + PLAYER_INIT_HEIGHT >= SCREEN_HEIGHT - GATE_HEIGHT){
            world->act_room = world->act_room->down;
        }
    }
    //gauche
    if(world->act_room->left != NULL){
        if (player->x <= GATE_HEIGHT && player->y >= SCREEN_HEIGHT / 2 - GATE_WIDTH / 2 && player->y <= SCREEN_HEIGHT / 2 + GATE_WIDTH / 2){
            world->act_room = world->act_room->left;
        }
    }
}