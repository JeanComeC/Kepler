#ifndef RENDER_H
#define RENDER_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "algo.h"
#include <raylib.h>

//MACRO

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


//structure 

struct InputState {
    char vx[20];
    char vy[20];
    int champ_actif; // 0 = vx, 1 = vy
};


//CONSTANTES GLOBALES



//PROTOTYPE
struct Coordinates render_v0_Rocket();
bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket, enum Code_exit* code_exit);
void starInit(struct Coordinates star[], int n);
void drawStars(struct Coordinates star[], int n);
void drawSun(struct Coordinates origin, int nbr_circle);
void drawEarth(struct Tab_Earth* tab, int index, struct Coordinates origin, double scale);
void drawRocket(struct Tab_Rocket* tab, int i, struct Coordinates origin, double scale);

#endif