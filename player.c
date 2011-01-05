#include <GL/glfw.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "player.h"

Player
init_player(int id) {
    Player player;

    player.id = id;
    player.size = 0;
    player.current_dir = DEF_RIGHT;

    player.name = malloc(sizeof(char) * 24);
    player.data = malloc(sizeof(Quad) * 2);
    add_body(&player);

    Colour c;
    c.r = 1.0f;
    c.g = 0.8f;
    c.b = 0.0f;
    player.c = c;

    return player;
}

void
add_body(Player *player) {
    int i = ++player->size;

    player->data = realloc(player->data, sizeof(Quad) * i + 1);
    Quad data = player->data[i-1];

    if (i == 1) {
        data.pos[0].x = 20;
        data.pos[0].y = 20;
    } else {
        data.pos[0].x = player->data[i-2].pos[0].x + player->data[i-2].pos[1].x;
        data.pos[0].y = player->data[i-2].pos[0].y + player->data[i-2].pos[1].y;
    }

    /*if (player->current_dir == DEF_RIGHT || player->current_dir == DEF_LEFT) {
        data.pos[1].x = 0;
        data.pos[1].y = 5;
    } else if (player->current_dir == DEF_UP|| player->current_dir == DEF_DOWN) {
        data.pos[1].x = 5;
        data.pos[1].y = 0;
    }*/

    switch (player->current_dir) {
        case DEF_UP:
            data.pos[1].x = 5;
            data.pos[1].y = 0;
        break;
        case DEF_DOWN:
            data.pos[1].x = -5;
            data.pos[1].y = 0;
        break;
        case DEF_LEFT:
            data.pos[1].x = 0;
            data.pos[1].y = -5;
        break;
        case DEF_RIGHT:
            data.pos[1].x = 0;
            data.pos[1].y = 5;
        break;
    }

    player->data[i-1] = data;
}

void
update_players(Player *players) {
    int i;
    for (i = 0; i < 8; i++) {
        if (players[i].id == 0)
            continue;

        update_player(&players[i]);
    }
}

void
control_player(Player *player) {
    if (glfwGetKey(GLFW_KEY_DOWN)) {
        if (player->current_dir == DEF_DOWN || player->current_dir == DEF_UP)
            return;

        player->current_dir = DEF_DOWN;
        add_body(player);
    } else if (glfwGetKey(GLFW_KEY_UP)) {
        if (player->current_dir == DEF_UP || player->current_dir == DEF_DOWN)
            return;

        player->current_dir = DEF_UP;
        add_body(player);
    } else if (glfwGetKey(GLFW_KEY_LEFT)) {
        if (player->current_dir == DEF_LEFT || player->current_dir == DEF_RIGHT)
            return;

        player->current_dir = DEF_LEFT;
        add_body(player);
    } else if (glfwGetKey(GLFW_KEY_RIGHT)) {
        if (player->current_dir == DEF_RIGHT || player->current_dir == DEF_LEFT)
            return;

        player->current_dir = DEF_RIGHT;
        add_body(player);
    }
}

void
update_player(Player *player) {
    int i = player->size;

    switch (player->current_dir) {
        case DEF_UP:
            player->data[i-1].pos[1].y -= 5;
        break;
        case DEF_DOWN:
            player->data[i-1].pos[1].y += 5;
        break;
        case DEF_LEFT:
            player->data[i-1].pos[1].x -= 5;
        break;
        case DEF_RIGHT:
            player->data[i-1].pos[1].x += 5;
        break;
    }
}

void
clean_players(Player *players) {
   int i;
    for (i = 0; i < 8; i++) {
        if (players[i].id == 0)
            continue;

        free(players[i].name);
        free(players[i].data);
    }

    memset(players, 0, sizeof(Player));
}
