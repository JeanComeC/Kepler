#ifndef RENDER_H
#define RENDER_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdbool.h>
#include "algo.h"
#include <raylib.h>

//MACRO

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080





//CONSTANTES GLOBALES



//PROTOTYPE
bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket);
void starInit(struct Coordinates star[], int n);
void drawStars(struct Coordinates star[], int n);
void drawSun(struct Coordinates origin, int nbr_circle);

#endif