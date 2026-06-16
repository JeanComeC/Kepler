#include "physic_calc.h"
#include "src/algo.h"

/**
@brief calcul de la norme
@param vector 
@return un double qui est la norme du vecteur entré en parametre
@notes
*/
double calc_norme(struct Coordinates vector){
    double norme=0.0;
    norme=pow(vector.x,2)+pow(vector.y,2)+pow(vector.z,2);
    norme=sqrt(norme);
    return norme;
}

/**
@brief calcul de l'acceleration
@param vect_r vecteur position
@return l'acceleration sous forme de coordonnées
@notes 
*/
struct Coordinates calc_acceleration(struct Coordinates vect_r){
    struct Coordinates vect_acc;
    double factor=(CONSTANTE_GRAVITATION_UNIVERSELLE*MASSE_SOLEIL_KG)/pow(calc_norme(vect_r),3);
    vect_acc.x=-1*factor*vect_r.x;
    vect_acc.y=-1*factor*vect_r.y;
    vect_acc.z=-1*factor*vect_r.z;
    return vect_acc;
}

/**
@brief calcul de vitesse
@param vect_v, vect_acc vecteur vitesse, et vecteur acceleration
@return vecteur vitesse
@notes
*/
struct Coordinates calc_vitesse(struct Coordinates vect_v, struct Coordinates vect_acc){
    struct Coordinates  vect_v_output={0};
    vect_v_output.x=vect_v.x+(H_PAS_TEMPOREL_SECONDE*vect_acc.x);
    vect_v_output.y=vect_v.y+(H_PAS_TEMPOREL_SECONDE*vect_acc.y);
    vect_v_output.z=vect_v.z+(H_PAS_TEMPOREL_SECONDE*vect_acc.z);
    return vect_v_output;
}

/**
@brief calcul de position
@param vect_r, vect_v_news
@return position en coordonnées
@notes vect_v_news : on prend la nouvelle vitesse en entrée pour corriger l'imprecision de la méthode d'Euler
*/
struct Coordinates calc_position(struct Coordinates vect_r, struct Coordinates vect_v_news){
    struct Coordinates  vect_r_output={0};
    vect_r_output.x=vect_r.x+(H_PAS_TEMPOREL_SECONDE*vect_v_news.x);
    vect_r_output.y=vect_r.y+(H_PAS_TEMPOREL_SECONDE*vect_v_news.y);
    vect_r_output.z=vect_r.z+(H_PAS_TEMPOREL_SECONDE*vect_v_news.z);
    return vect_r_output;
}

/**
@brief calcul de la vitesse relative
@param vect_v_1, vect_v_2
@return un vecteur vitesse
@notes
*/
struct Coordinates calc_vitesse_relative(struct Coordinates vect_v_1, struct Coordinates vect_v_2){
    struct Coordinates vect_v_output={0};
    vect_v_output.x=vect_v_2.x-vect_v_1.x;
    vect_v_output.y=vect_v_2.y-vect_v_1.y;
    vect_v_output.z=vect_v_2.z-vect_v_1.z;
    return vect_v_output;
}

// ===

/**
@brief fonction qui regroupe le calcul de vitesse, de position, et d'acceleration pour la terre
@param data_Earth
@return struct Data_Earth
@notes
*/
struct Data_Earth calc_Data_Earth(struct Data_Earth data_Earth){
    struct Data_Earth data_Earth_output={0};
    data_Earth_output.vitesse=calc_vitesse(data_Earth.vitesse,calc_acceleration(data_Earth.position));
    data_Earth_output.position=calc_position(data_Earth.position,data_Earth_output.vitesse);
    return data_Earth_output;
}

/**
@brief fonction qui regroupe le calcul de vitesse, de position, et d'acceleration pour la fusée
@param data_Rocket
@return struct Data_Rocket
@notes
*/
struct Data_Rocket calc_Data_Rocket(struct Data_Rocket data_Rocket){
    struct Data_Rocket data_Rocket_output={0};
    data_Rocket_output.vitesse=calc_vitesse(data_Rocket.vitesse,calc_acceleration(data_Rocket.position));
    data_Rocket_output.position=calc_position(data_Rocket.position,data_Rocket_output.vitesse);
    return data_Rocket_output;
}
