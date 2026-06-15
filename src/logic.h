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


//ENUMERATION
enum Code_exit{
    CRASH_SOLAIRE,
    SORTIE_VIDE_SPATIAL,
    ATTERRISSAGE,
    CRASH_TERRESTRE,
    PANNE_CARBURANT,
};


//CONSTANTES GLOBALES
#define DISTANCE_MAX_R0_ROCKET 7.5E+11
#define DISTANCE_MAX_UNIVERS 1E+12
#define NB_PAS_MAX 24*30
#define NORME_VITESSE_MAX_IMPACT 5

//PROTOTYPE
struct Coordinates init_random_position();
bool stop_condition(enum Code_exit* code_exit, struct Data_Earth data_Earth, struct Data_Rocket data_Rocket,size_t nb_pas);

//===
bool main_logic(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket);


#endif