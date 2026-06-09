#include "room.h"
#include "constants.h"

void gen_matrice(int room[MAP_SIZE][MAP_SIZE]){
    for (int i = 0 ; i < MAP_SIZE ; i ++){
        for (int j = 0 ; j < MAP_SIZE ; j ++){
            room[i][j] = rand()%2; //Entre  0 et 1
        }
    }
}