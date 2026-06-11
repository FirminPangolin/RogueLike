#include "player.h"
#include "bullet.h"

void create_bullet(Player* player){
    Bullet* bullet = malloc(sizeof(Bullet));

    //Taille
    bullet->width = BULLET_INIT_WIDTH;
    bullet->height = BULLET_INIT_HEIGHT;
    
    bullet->speedX = 0;
    bullet->speedY = 0;

    switch(player->facing){
        case 0: //Up
            //Position
            bullet->x = player->x + player->width / 2;
            bullet->y = player->y - bullet->height / 2;

            //Données
            bullet->speedY = (-1) * BULLET_INIT_SPEED;
            break;
//TODO : TEXTURES 
        case 1: //Right
            //Position
            bullet->x = player->x + player->width / 2;
            bullet->y = player->y + player->height  / 2;

            //Données
            bullet->speedX = BULLET_INIT_SPEED;
            break;
        
        case 2: //Down
            //Position
            bullet->x = player->x + player->width / 2 - bullet->height / 2;
            bullet->y = player->y + player->height;

            //Données
            bullet->speedY = BULLET_INIT_SPEED;
            break;
        
        case 3: //Left
            //Position
            bullet->x = player->x - bullet->width;
            bullet->y = player->y + player->height  / 2 - bullet->height / 2;

            //Données
            bullet->speedX = (-1) * BULLET_INIT_SPEED;
            break;

        default:
            printf("WTF\n");
            break;
    }

    player->bullets[player->bullets_shot] = bullet;
    player->bullets_shot += 1;
}