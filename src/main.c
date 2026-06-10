#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "constants.h"
#include "graphics.h"
#include  "world.h"
#include "bullet.h"
#include "events.h"
#include "room.h"
#include "time.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Premier Test");

    SetTargetFPS(60); //FPS du jeu
    
    srand(time(NULL));

    World* world = init_data();
       
    while (!WindowShouldClose() && !(world->player->health <= 0)) 
    {
        player_movement(world->player);
        player_actions(world->player);
        
        manage_bullets(world->player);
        check_room_exit(world, world->player);

        printf("x : %d, y : %d\n", world->player->x, world->player->y);
        refresh_graphics(world);
    }
    

    CloseWindow(); //Ferme la fenêtre
    
    return 0;
}