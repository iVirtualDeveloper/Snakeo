#include <GL/glfw.h>
#include <GL/glu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"
#include "player.h"

void init_GL(void);

int
main (int argc, char **argv) {
    glfwInit();

    if (glfwOpenWindow(800, 600, 8, 8, 8, 8, 0, 0, GLFW_WINDOW) == GL_FALSE) {
        glfwTerminate();
    }
    glfwSetWindowTitle("Snakeo");

    init_GL();

    Player players[8];
    memset(players, 0, sizeof(Player) * 8);

    players[0] = init_player(1);

    int running = 1;
    while (running) {
        glClear(GL_COLOR_BUFFER_BIT);

        control_player(&players[0]);

        update_players(players);
        draw_players(players);

        glfwSwapBuffers();
        running = glfwGetWindowParam(GLFW_OPENED);
    }

    clean_players(players);

    glfwTerminate();

    return 0;
}

void
init_GL(void) {
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

    glViewport(0, 0, 800, 600);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
