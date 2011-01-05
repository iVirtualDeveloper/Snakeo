#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#define DEF_UP 1
#define DEF_DOWN 2
#define DEF_LEFT 3
#define DEF_RIGHT 4

typedef struct {
    int x;
    int y;
} Vertex2d;

typedef struct {
    Vertex2d pos[2];
} Quad;

typedef struct {
    double r, g, b;
} Colour;

#endif // DEFS_H_INCLUDED
