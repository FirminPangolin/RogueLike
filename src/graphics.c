#include "graphics.h"
#include "bullet.h"

void refresh_graphics(World* world){
    Player* player = world->player;
    Room* act_room = world->act_room;

    BeginDrawing();
        //Reset
        ClearBackground(WHITE);

        //Joueur
        DrawRectangle(player->x, player->y, player->width, player->height, ORANGE);

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
        if(act_room->up != NULL){
            DrawRectangle(SCREEN_WIDTH / 2 - GATE_WIDTH / 2, 0, GATE_WIDTH, GATE_HEIGHT, (act_room->type == 0)?BLUE:GREEN);
        }
        if(act_room->right != NULL){
            DrawRectangle(SCREEN_WIDTH - GATE_HEIGHT, SCREEN_HEIGHT / 2 - GATE_WIDTH / 2, GATE_HEIGHT, GATE_WIDTH, (act_room->type == 0)?BLUE:GREEN);
        }
        if(act_room->down != NULL){
            DrawRectangle(SCREEN_WIDTH / 2 - GATE_WIDTH / 2, SCREEN_HEIGHT - GATE_HEIGHT, GATE_WIDTH, GATE_HEIGHT, (act_room->type == 0)?BLUE:GREEN);
        }
        if(act_room->left != NULL){
            DrawRectangle(0, SCREEN_HEIGHT / 2 - GATE_WIDTH / 2, GATE_HEIGHT, GATE_WIDTH, (act_room->type == 0)?BLUE:GREEN);
        }

    EndDrawing();
}