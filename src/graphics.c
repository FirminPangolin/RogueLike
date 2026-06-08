#include "graphics.h"
#include "bullet.h"

void refresh_graphics(World* world){
    Player* player = world->player;

    BeginDrawing();
        //Reset
        ClearBackground(WHITE);

        //Joueur
        DrawRectangle(
            player->x, 
            player->y, 
            player->width, 
            player->height, 
            ORANGE
        );

        //Vies
        for (int i = 0 ; i < player->health ; i++){
            DrawRectangle(
                10 + 40 * i, 
                10, 
                30, 
                30, 
                RED
            );
        }

        //Bullets
        for (int i = 0 ; i < player->bullets_shot ; i ++){
            DrawRectangle(
                player->bullets[i]->x, 
                player->bullets[i]->y, 
                player->bullets[i]->width, 
                player->bullets[i]->height, 
                BLUE
            );
        }

    EndDrawing();
}