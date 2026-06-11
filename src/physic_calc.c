#include "physic_calc.h"

double calc_norme(struct Coordinates vector){
    double norme=0.0;
    norme=pow(vector.x,2)+pow(vector.y,2)+pow(vector.z,2);
    norme=sqrt(norme);
    return norme;
}

struct Coordinates calc_acceleration(struct Coordinates v_position){
    struct Coordinates acc;
    double factor=(CONSTANTE_GRAVITATION_UNIVERSELLE*MASSE_SOLEIL_KG)/pow(calc_norme(v_position),3);
    acc.x=-1*factor*v_position.x;
    acc.y=-1*factor*v_position.y;
    acc.z=-1*factor*v_position.z;
    return acc;
}

