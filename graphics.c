#include <GL/gl.h>
#include <stdio.h>

#include "graphics.h"


void
draw_players(Player *players) {
    int i;
    for (i = 0; i < 8; i++) {
        if (players[i].id == 0)
            continue;

        draw_player(players[i]);
    }
}

void
draw_player(Player player) {
    int i;
    for (i = 0; i < player.size; i++) {
        draw_quad(player.data[i], player.c);
    }
}

void
draw_quad(Quad q, Colour c) {
    int x, y, xsize, ysize;

    x = q.pos[0].x;
    y = q.pos[0].y;
    xsize = q.pos[1].x;
    ysize = q.pos[1].y;

    glLoadIdentity();
    glColor3f(c.r, c.g, c.b);

    glBegin(GL_QUADS);
        glVertex2d(x, y);
        glVertex2d(x, y+ysize);
        glVertex2d(x+xsize, y+ysize);
        glVertex2d(x+xsize, y);
    glEnd();
}
