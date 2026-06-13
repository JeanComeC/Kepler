#include "physic_calc.h"

//Constantes globales :
const struct Coordinates r0_Earth = {.x=-1.470981E+11, .y=0.0, .z=0.0};
const struct Coordinates v0_Earth = {.x=0.0, .y=3.029113E+04, .z=0.0};

// ===

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


// ===

bool main_calculation(struct Data_output* tabmain){
    struct Coordinates vect_v=v0_Earth;
    struct Coordinates vect_r=r0_Earth;
    for(size_t i=0;i<MAX_POINT;i++){
        struct Coordinates vect_acc=calc_acceleration(vect_r);
        struct Coordinates vect_v_news=calc_vitesse(vect_v,vect_acc);
        struct Coordinates vect_r_news=calc_position(vect_r,vect_v_news);
        double d_ke=calc_e_cinetique(vect_v);
        double d_pe=calc_e_potentiel(vect_r);
        //Filling
        tabmain[i].t=H_PAS_TEMPOREL_SECONDE*i;
        tabmain[i].coordinates=vect_r;
        tabmain[i].ke=d_ke;
        tabmain[i].pe=d_pe;
        //Updates
        vect_v=vect_v_news;
        vect_r=vect_r_news;
    }
    return true;
}

