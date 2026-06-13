#ifndef ALGO_H
#define ALGO_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

//MACRO
#define H_PAS_TEMPOREL_SECONDE 3600
#define MAX_POINT 8766


//STRUCTURE
struct Coordinates{
    double x;
    double y;
    double z;
};

struct Data{
    double time;
    struct Coordinates coordinates;
    struct Coordinates vitesse;
    double fuel;
};

//PROTOTYPE
//struct Data_output* create_tab_data(size_t size_tab);
//void destroy_tab_data(struct Data_output* tab_data);


#endif