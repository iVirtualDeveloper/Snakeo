#include <GL/glfw.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "player.h"

Player
init_player(int id) {
    Player player;

    player.id = id;
    player.pos.x = 100;
    player.pos.y = 100;
    player.body.freq = 0;
    player.current_dir = DEF_RIGHT;

    player.name = malloc(sizeof(char) * 24);
    player.body.data = malloc(sizeof(Quad) * 2);
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
    int i = ++player->body.freq;

    player->body.data = realloc(player->body.data, sizeof(Quad) * i + 1);
    Quad body = player->body.data[i-1];

    body.pos[0].x = player->pos.x;
    body.pos[0].y = player->pos.y;

    if (player->current_dir == DEF_RIGHT || player->current_dir == DEF_LEFT) {
        body.pos[1].x = 0;
        body.pos[1].y = 5;
    } else if (player->current_dir == DEF_UP|| player->current_dir == DEF_DOWN) {
        body.pos[1].x = 5;
        body.pos[1].y = 0;
    }

    player->body.data[i-1] = body;
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
        if (player->current_dir == DEF_DOWN)
            return;

        player->current_dir = DEF_DOWN;
        add_body(player);
    } else if (glfwGetKey(GLFW_KEY_UP)) {
        if (player->current_dir == DEF_UP)
            return;

        player->current_dir = DEF_UP;
        add_body(player);
    } else if (glfwGetKey(GLFW_KEY_LEFT)) {
        if (player->current_dir == DEF_LEFT)
            return;

        player->current_dir = DEF_LEFT;
        add_body(player);
    } else if (glfwGetKey(GLFW_KEY_RIGHT)) {
        if (player->current_dir == DEF_RIGHT)
            return;

        player->current_dir = DEF_RIGHT;
        add_body(player);
    }
}

void
update_player(Player *player) {
    int i = player->body.freq;

    switch (player->current_dir) {
        case DEF_UP:
            player->pos.y -= 5;
        break;
        case DEF_DOWN:
            player->pos.y += 5;
        break;
        case DEF_LEFT:
            player->pos.x -= 5;
        break;
        case DEF_RIGHT:
            player->pos.x += 5;
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
        free(players[i].body.data);
    }

    memset(players, 0, sizeof(Player));
}
