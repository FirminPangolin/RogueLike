#include "room.h"
#include "constants.h"

void gen_matrice(int room[MAP_SIZE][MAP_SIZE]) {
    //Tout la map à 0
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            room[i][j] = 0;
        }
        
    }

    int target = (MAP_SIZE * MAP_SIZE) / 4; // ajuste densité

    int x = MAP_SIZE / 2;
    int y = MAP_SIZE / 2;

    room[x][y] = 1;
    int count = 1;

    int frontier[MAP_SIZE * MAP_SIZE][2];
    int fsize = 0;

    frontier[fsize][0] = x;
    frontier[fsize][1] = y;
    fsize++;

    while (count < target && fsize > 0) {

        int id = rand() % fsize;
        int cx = frontier[id][0];
        int cy = frontier[id][1];

        int dirs[4][2] = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int tries = 0;
        int placed = 0;

        while (tries < 4 && !placed) {
            int d = rand() % 4;

            int nx = cx + dirs[d][0];
            int ny = cy + dirs[d][1];

            if (nx < 0 || ny < 0 || nx >= MAP_SIZE || ny >= MAP_SIZE) {
                tries++;
                continue;
            }

            if (room[nx][ny] == 0) {
                room[nx][ny] = 1;

                frontier[fsize][0] = nx;
                frontier[fsize][1] = ny;
                fsize++;

                count++;
                placed = 1;
            }

            tries++;
        }

        // si bloqué, on swap out ce frontier
        frontier[id][0] = frontier[fsize - 1][0];
        frontier[id][1] = frontier[fsize - 1][1];
        fsize--;
    }
}

void init_all_rooms(World* world){
    //Inits
    for (int i = 0 ; i < MAP_SIZE ; i++){
        for (int j = 0 ; j < MAP_SIZE ; j++){
            if (world->map[i][j] == 1){
                world->rooms[i][j] = init_room(world, i, j);
                if (world->act_room == NULL){
                    world->act_room = world->rooms[i][j];
                }
            }
            else{
                world->rooms[i][j] = NULL;
            }
        }
    }

    //Links
    for (int i = 0 ; i < MAP_SIZE ; i++){
        for (int j = 0 ; j < MAP_SIZE ; j++){
            Room* r = world->rooms[i][j];
            if (r == NULL) continue;
            r->up = (i > 0) ? world->rooms[i - 1][j] : NULL;
            r->down = (i < MAP_SIZE - 1) ? world->rooms[i + 1][j] : NULL;
            r->left = (j > 0) ? world->rooms[i][j - 1] : NULL;
            r->right = (j < MAP_SIZE - 1) ? world->rooms[i][j + 1] : NULL;
        }
    }
}

Room* init_room(World* world, int i, int j){
    Room* room = malloc(sizeof(Room));
    room->exists = 1;
    room->up = room->right = room->down = room->left = NULL;
    room->row = i;
    room->column = j;
    room->type = rand()%2;
    room->cleared = 0;

    return room;
}