#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "constants.h"
#include "graphics.h"
#include  "world.h"
#include "bullet.h"
#include "events.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Premier Test");

    SetTargetFPS(60); //FPS du jeu
    
    World* world = init_data();

    while (!WindowShouldClose() && !(world->player->health <= 0)) 
    {
        player_movement(world->player);
        player_actions(world->player);
        
        manage_bullets(world->player);

        refresh_graphics(world);
    }
    

    CloseWindow(); //Ferme la fenêtre
    
    return 0;
}