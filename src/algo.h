#ifndef ALGO_H
#define ALGO_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

//MACRO
#define H_PAS_TEMPOREL_SECONDE 3600


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
//struct Data_output* create_tab_data(size_t size_tab);
//void destroy_tab_data(struct Data_output* tab_data);


#endif