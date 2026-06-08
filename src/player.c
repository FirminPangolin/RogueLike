#include "player.h"
#include "bullet.h"
#include "functions.h"

Player* init_player(){
    Player* player = malloc(sizeof(Player));
    
    //Position
    player->x = 10;
    player->y = SCREEN_HEIGHT / 2;

    //Taille
    player->width = PLAYER_INIT_WIDTH;
    player->height = PLAYER_INIT_HEIGHT;

    //Données
    player->speed = PLAYER_INIT_SPEED;
    player->health = PLAYER_INIT_HEALTH;
    player->facing = 1; //0 up, 1 right, 2 down, 3 left

    player->bullets = malloc(PLAYER_MAX_BULLETS * sizeof(Bullet));
    player->bullets_shot = 0;

    return player;
}

void player_movement(Player* player){
    if (IsKeyDown(KEY_W)){
        player->y -= mini(player->speed, player->y);
        player->facing = 0;
    }
    if (IsKeyDown(KEY_D)){
        player->x += mini(player->speed, SCREEN_WIDTH - (player->x + player->width));
        player->facing = 1;
    }
    if (IsKeyDown(KEY_A)){
        player->x -= mini(player->speed, player->x);
        player->facing = 2;
    }
    if (IsKeyDown(KEY_S)){
        player->y += mini(player->speed, SCREEN_HEIGHT - (player->y + player->height));
        player->facing = 2;
    }
}

void player_actions(Player* player){
    if (IsKeyReleased(KEY_LEFT_SHIFT) && player->speed < PLAYER_MAX_SPEED){
        player->speed += 5;
    }
    if (IsKeyReleased(KEY_R)){
        player->health -= 1;
    }
    if (IsKeyReleased(KEY_I) && player->bullets_shot < PLAYER_MAX_BULLETS){
        player->facing = 0;
        create_bullet(player);
    }
    if (IsKeyReleased(KEY_L) && player->bullets_shot < PLAYER_MAX_BULLETS){
        player->facing = 1;
        create_bullet(player);
    }
    if (IsKeyReleased(KEY_K) && player->bullets_shot < PLAYER_MAX_BULLETS){
        player->facing = 2;
        create_bullet(player);
    }
    if (IsKeyReleased(KEY_J) && player->bullets_shot < PLAYER_MAX_BULLETS){
        player->facing = 3;
        create_bullet(player);
    }
}