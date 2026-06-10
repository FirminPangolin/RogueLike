#ifndef __EVENTS__H__
#define __EVENTS__H__

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "bullet.h"
#include "world.h"

void manage_bullets(Player* player);
void check_room_exit(World* world, Player* player);

#endif