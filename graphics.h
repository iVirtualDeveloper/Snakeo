#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include "defs.h"
#include "player.h"

void draw_players(Player *players);
void draw_player(Player player);
void draw_quad(Quad q, Colour c);

#endif
