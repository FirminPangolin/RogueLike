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