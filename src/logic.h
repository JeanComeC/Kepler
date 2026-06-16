#ifndef LOGIC_H
#define LOGIC_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "algo.h"
#include "physic_calc.h"
#include "render.h"


//MACRO
#define DISTANCE_MAX_R0_ROCKET 7.5E+10
#define DISTANCE_MAX_UNIVERS 1E+11
#define NB_PAS_MAX 24*1000
#define NORME_VITESSE_MAX_IMPACT 5
#define CHEAT_CODE true

//PROTOTYPE
struct Coordinates init_random_position();
bool stop_condition(enum Code_exit* code_exit, struct Data_Earth data_Earth, struct Data_Rocket data_Rocket,size_t nb_pas);
struct Coordinates cheat(struct Coordinates r0_f);

//===
bool main_logic(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket, enum Code_exit* code_exit);


#endif