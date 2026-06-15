#include "events.h"
#include "constants.h"

void manage_bullets(World* world, Player* player){
    for (int i = 0 ; i < player->bullets_shot ; i ++){
        Bullet* bullet = player->bullets[i];
        //Déplacement
        bullet->x += bullet->speedX;
        bullet->y += bullet->speedY;
        
        //Sorties d'écran
        if (bullet->x > SCREEN_WIDTH || bullet->x + bullet->width < 0 || bullet->y < 0 || bullet->y + bullet->height > SCREEN_HEIGHT){
            free_bullet(world, bullet, i);
            i--;
        }
    }
}

void check_room_exit(World* world, Player* player){
    //haut
    if(world->act_room->up != NULL){
        if (player->x >= SCREEN_WIDTH / 2 - GATE_WIDTH / 2 && player->x + player->width <= SCREEN_WIDTH / 2 + GATE_WIDTH / 2 && player->y <= GATE_HEIGHT){
            world->act_room = world->act_room->up;
            player->y = SCREEN_HEIGHT - GATE_HEIGHT - player->height - 1;
        }
    }
    //droite
    if(world->act_room->right != NULL){
        if (player->x + player->width  >= SCREEN_WIDTH - GATE_HEIGHT && player->y >= SCREEN_HEIGHT / 2 - GATE_WIDTH / 2 && player->y + player->height <= SCREEN_HEIGHT / 2 + GATE_WIDTH / 2){
            world->act_room = world->act_room->right;
            player->x = GATE_HEIGHT + 1;
        }
    }
    //bas
    if(world->act_room->down != NULL){
        if (player->x >= SCREEN_WIDTH / 2 - GATE_WIDTH / 2 && player->x + player->width <= SCREEN_WIDTH / 2 + GATE_WIDTH / 2 && player->y  + player->height >= SCREEN_HEIGHT - GATE_HEIGHT){
            world->act_room = world->act_room->down;
            player->y = GATE_HEIGHT + 1;
        }
    }
    //gauche
    if(world->act_room->left != NULL){
        if (player->x <= GATE_HEIGHT && player->y >= SCREEN_HEIGHT / 2 - GATE_WIDTH / 2 && player->y + player->height <= SCREEN_HEIGHT / 2 + GATE_WIDTH / 2){
            world->act_room = world->act_room->left;
            player->x = SCREEN_WIDTH - GATE_HEIGHT - player->width - 1;
        }
    }
}

void check_collision_ennemy_player(World* world){
    Player* player = world->player;
    for (int i = 0 ; i < world->nbEnnemies ; i++){
        Ennemy* ennemy = world->ennemies[i];
        bool cond_y_bas = player->y + player->height >= ennemy->y && player->y + player->height <= ennemy->y + ennemy->height;
        bool cond_y_haut = player->y >= ennemy->y && player->y <= ennemy->y + ennemy->height; 

        bool cond_x_gauche = player->x >= ennemy->x && player->x <= ennemy->x + ennemy->width;
        bool cond_x_droite = player->x + player->width >= ennemy->x && player->x + player->width <= ennemy->x + ennemy->width;

        if ((cond_y_bas || cond_y_haut) && (cond_x_gauche || cond_x_droite) && player->invincible == 0){
            player->invincible = PLAYER_COLLIDE_IDFRAME;
            if (world->player->health > 0){
                world->player->health -= 1;
            }
        }
        else{
            if (player->invincible > 0){
                player->invincible -= 1;
            }
        }
    } 
}

void check_collision_ennemy_bullet(World* world){
    Player* player = world->player;

    for (int j = 0 ; j < player->bullets_shot ; j++){
        Bullet* bullet = player->bullets[j];
        for (int i = 0 ; i < world->nbEnnemies ; i++){
            Ennemy* ennemy = world->ennemies[i];
            bool cond_y_bas = bullet->y + bullet->height >= ennemy->y && bullet->y + bullet->height <= ennemy->y + ennemy->height;
            bool cond_y_haut = bullet->y >= ennemy->y && bullet->y <= ennemy->y + ennemy->height; 

            bool cond_x_gauche = bullet->x >= ennemy->x && bullet->x <= ennemy->x + ennemy->width;
            bool cond_x_droite = bullet->x + bullet->width >= ennemy->x && bullet->x + bullet->width <= ennemy->x + ennemy->width;

            if ((cond_y_bas || cond_y_haut) && (cond_x_gauche || cond_x_droite)){
                if (ennemy->health > 0){
                    ennemy->health -= 1;
                }
                else{
                    free_bullet(world, bullet, j);
                    j--;
                    free_ennemy(world, ennemy, i);
                    i--;
                    break;
                }
            }
        }
    }
}