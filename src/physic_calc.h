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
#define CONSTANTE_GRAVITATION_UNIVERSELLE 6.674184E+11
#define MASSE_SOLEIL_KG 1.989000E+30

//ENUMERATION


//STRUCTURE


//PROTOTYPE
double calc_norme(struct Coordinates vector);
struct Coordinates calc_acceleration();


#endif