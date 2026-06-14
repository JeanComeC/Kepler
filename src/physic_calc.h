#ifndef PHYSIC_CALC_H
#define PHYSIC_CALC_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "algo.h"

//MACRO
#define CONSTANTE_GRAVITATION_UNIVERSELLE 6.674184E-11
#define MASSE_SOLEIL_KG 1.989000E+30
#define R0_EARTH ((struct Coordinates){.x=-1.470981E+11, .y=0.0, .z=0.0})
#define V0_EARTH ((struct Coordinates){.x=0.0, .y=3.029113E+04, .z=0.0})


//CONSTANTES GLOBALES


//PROTOTYPE
double calc_norme(struct Coordinates vector);
struct Coordinates calc_acceleration(struct Coordinates vect_r);
struct Coordinates calc_vitesse(struct Coordinates vect_v, struct Coordinates vect_acc);
struct Coordinates calc_position(struct Coordinates vect_r, struct Coordinates vect_v_news);

// ===
//bool main_calculation(struct Data_output* tabmain);

#endif