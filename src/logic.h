#ifndef LOGIC_H
#define LOGIC_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "algo.h"
#include "physic_calc.h"


//MACRO


//CONSTANTES GLOBALES
#define DISTANCE_MAX_R0_ROCKET 7.5E+11
#define DISTANCE_MAX_UNIVERS 1E+12

//PROTOTYPE
struct Coordinates init_random_position();
bool stop_condition(struct Data_Earth data_Earth, struct Data_Rocket data_Rocket,size_t nb_pas);

//===
bool main_logic(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket);


#endif