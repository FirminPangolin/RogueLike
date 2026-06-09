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

        //Map
        for (int i = 0 ; i < MAP_SIZE ; i++){
            for (int j = 0 ; j < MAP_SIZE ; j++){
                if (world->map[i][j] == 1){
                    DrawRectangle(
                        j * (SCREEN_WIDTH / MAP_SIZE),
                        i * (SCREEN_WIDTH / MAP_SIZE),
                        SCREEN_WIDTH / MAP_SIZE, 
                        SCREEN_WIDTH / MAP_SIZE, 
                        YELLOW
                    );
                }
            }
        }

    EndDrawing();
}