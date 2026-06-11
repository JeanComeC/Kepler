#ifndef ALGO_H
#define ALGO_H

//BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

//MACRO
#define H_PAS_TEMPOREL_HEURE 1
#define MAX_POINT 8766

//ENUMERATION


//STRUCTURE
struct Coordinates{
    double x;
    double y;
    double z;
};

struct Data_output{
    size_t id;
    double t;
    struct Coordinates coordinates;
    double ke;
    double pe;
};

//PROTOTYPE
struct Data_output* create_tab_data(size_t size_tab);
void destroy_tab_data(struct Data_output* tab_data);


#endif