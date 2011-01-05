#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "defs.h"

typedef struct {
    int id;
    char *name;
    Colour c;
    Quad *data;
    int size;
    int current_dir;
} Player;

Player init_player(int id);
void add_body(Player *player);
void update_players(Player *players);
void control_player(Player *player);
void update_player(Player *player);
void clean_players(Player *players);

#endif
