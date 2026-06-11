#include "physic_calc.h"



double calc_norme(struct Coordinates vector){
    double norme=0.0;
    norme=pow(vector.x,2)+pow(vector.y,2)+pow(vector.z,2);
    norme=sqrt(norme);
    return norme;//l'arrondir ?
}
