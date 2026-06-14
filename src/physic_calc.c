#include "physic_calc.h"


double calc_norme(struct Coordinates vector){
    double norme=0.0;
    norme=pow(vector.x,2)+pow(vector.y,2)+pow(vector.z,2);
    norme=sqrt(norme);
    return norme;
}

struct Coordinates calc_acceleration(struct Coordinates vect_r){
    struct Coordinates vect_acc;
    double factor=(CONSTANTE_GRAVITATION_UNIVERSELLE*MASSE_SOLEIL_KG)/pow(calc_norme(vect_r),3);
    vect_acc.x=-1*factor*vect_r.x;
    vect_acc.y=-1*factor*vect_r.y;
    vect_acc.z=-1*factor*vect_r.z;
    return vect_acc;
}

struct Coordinates calc_vitesse(struct Coordinates vect_v, struct Coordinates vect_acc){
    struct Coordinates  vect_v_output={0};
    vect_v_output.x=vect_v.x+(H_PAS_TEMPOREL_SECONDE*vect_acc.x);
    vect_v_output.y=vect_v.y+(H_PAS_TEMPOREL_SECONDE*vect_acc.y);
    vect_v_output.z=vect_v.z+(H_PAS_TEMPOREL_SECONDE*vect_acc.z);
    return vect_v_output;
}

struct Coordinates calc_position(struct Coordinates vect_r, struct Coordinates vect_v){
    struct Coordinates  vect_r_output={0};
    vect_r_output.x=vect_r.x+(H_PAS_TEMPOREL_SECONDE*vect_v.x);
    vect_r_output.y=vect_r.y+(H_PAS_TEMPOREL_SECONDE*vect_v.y);
    vect_r_output.z=vect_r.z+(H_PAS_TEMPOREL_SECONDE*vect_v.z);
    return vect_r_output;
}

