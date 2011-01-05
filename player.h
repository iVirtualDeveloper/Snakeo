#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "defs.h"

typedef struct {
    Quad *data;
    int freq;
} Body;

typedef struct {
    int id;
    char *name;
    Vertex2d pos;
    Colour c;
    Body body;
    int current_dir;
} Player;

Player init_player(int id);
void add_body(Player *player);
void update_players(Player *players);
void control_player(Player *player);
void update_player(Player *player);
void clean_players(Player *players);

#endif
