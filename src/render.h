#ifndef RENDER_H
#define RENDER_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdbool.h>
#include "algo.h"
#include <raylib.h>

//MACRO

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800


//struct 

struct Stars{
    int x;
    int y;
};



//CONSTANTES GLOBALES



//PROTOTYPE
bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket);
void starInit(struct Stars star[], int n);
void drawStars(struct Stars star[], int n);

#endif