#ifndef ALGO_H
#define ALGO_H

//BIBLIOTHEQUE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

//MACRO
#define H_PAS_TEMPOREL_SECONDE 60


//STRUCTURE
struct Coordinates{
    double x;
    double y;
    double z;
};

struct Data_Earth{
    struct Coordinates position;
    struct Coordinates vitesse;
};

struct Data_Rocket{
    struct Coordinates position;
    struct Coordinates vitesse;
    double fuel;
};

struct Tab_Earth{
    struct Data_Earth* data;
    size_t size;
    size_t capacity;
};

struct Tab_Rocket{
    struct Data_Rocket* data;
    size_t size;
    size_t capacity;
};

struct Player{
    char pseudo[16];
    int nb_life;
};

//PROTOTYPE
struct Tab_Earth create_Tab_Earth();
void add_Tab_Earth(struct Tab_Earth* tab_Earth,struct Data_Earth new_data);
void destroy_Tab_Earth(struct Tab_Earth* tab_Earth);
//===
struct Tab_Rocket create_Tab_Rocket();
void add_Tab_Rocket(struct Tab_Rocket* tab_Rocket,struct Data_Rocket new_data);
void destroy_Tab_Rocket(struct Tab_Rocket* tab_Rocket);


#endif