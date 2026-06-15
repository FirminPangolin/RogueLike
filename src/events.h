#ifndef __EVENTS__H__
#define __EVENTS__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "bullet.h"
#include "world.h"

void manage_bullets(World* world, Player* player);
void check_room_exit(World* world, Player* player);
void check_collision_ennemy_player(World* world);
void check_collision_ennemy_bullet(World* world);


#endif