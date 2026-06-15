#include "logic.h"
#include "src/algo.h"
#include "src/physic_calc.h"


struct Coordinates init_random_position(){
    struct Coordinates position_Rocket_output={0};
    position_Rocket_output.x=random_double_for_position();
    position_Rocket_output.y=random_double_for_position();
    position_Rocket_output.z=0.0;
    return position_Rocket_output;
}

bool stop_condition(enum Code_exit* code_exit, struct Data_Earth data_Earth, struct Data_Rocket data_Rocket,size_t nb_pas){
    //distance fusée-soleil trop petite:
    if(calc_norme(data_Rocket.position)<DISTANCE_MAX_NUAGE){
        *code_exit=CRASH_SOLAIRE;
        return true;
    }
    //distance fusée-soleil trop grande:
    if(calc_norme(data_Rocket.position)>DISTANCE_MAX_UNIVERS){
        *code_exit=SORTIE_VIDE_SPATIAL;
        return true;
    }
    double dISTANCE_MAX_NUAGE=DISTANCE_MAX_NUAGE;
    if(CHEAT_CODE){
        dISTANCE_MAX_NUAGE*=100;
    }
    //distance fusée-terre faible:
    if(calc_norme((struct Coordinates){.x=(data_Rocket.position.x-data_Earth.position.x),.y=(data_Rocket.position.y-data_Earth.position.y),.z=(data_Rocket.position.z-data_Earth.position.z)})<dISTANCE_MAX_NUAGE){
        //si la vitesse est trop grande:
        if(calc_norme(calc_vitesse_relative(data_Earth.vitesse,data_Rocket.vitesse))>NORME_VITESSE_MAX_IMPACT){
            *code_exit=CRASH_TERRESTRE;
        }else{
            *code_exit=ATTERRISSAGE;
        }
        return true;
    }
    //durée trop longue:
    if(nb_pas>=NB_PAS_MAX){
        *code_exit=PANNE_CARBURANT;
        return true;
    }
    return false;
}

struct Coordinates cheat(struct Coordinates r0_f){
    // === MODIFIABLE ===
    int frames_avant_impact = 200;// La fusée mettra 200 frames à arriver
    // === ********** ===
    double temps_vol = frames_avant_impact * H_PAS_TEMPOREL_SECONDE;
    double rayon_orbite = calc_norme(R0_EARTH);
    double angle_actuel = atan2(R0_EARTH.y,R0_EARTH.x);
    double vitesse_angulaire = (2.0 * M_PI) / (365.25 * 24.0 * 3600.0);
    double angle_futur = angle_actuel + (vitesse_angulaire * temps_vol);
    struct Coordinates terre_future;
    terre_future.x = rayon_orbite * cos(angle_futur);
    terre_future.y = rayon_orbite * sin(angle_futur);
    terre_future.z = 0.0;
    struct Coordinates v0_Rocket;
    v0_Rocket.x = (terre_future.x - r0_f.x) / temps_vol;
    v0_Rocket.y = (terre_future.y - r0_f.y) / temps_vol;
    v0_Rocket.z = 0.0;
    struct Coordinates acc_soleil = calc_acceleration(r0_f);
    v0_Rocket.x -= (acc_soleil.x * temps_vol) / 2.0;
    v0_Rocket.y -= (acc_soleil.y * temps_vol) / 2.0;
    return v0_Rocket;
}

// ===

bool main_logic(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket,enum Code_exit* code_exit){
    struct Coordinates r0_Rocket=init_random_position();
    //On récupère le v0_Rocket :
    struct Coordinates v0_Rocket=render_v0_Rocket();
    //===
    bool bool1_obscur=false;
    if(CHEAT_CODE && v0_Rocket.x==0.0 && v0_Rocket.y==3.141592E+03 && v0_Rocket.z==0.0){
        v0_Rocket=cheat(r0_Rocket);
        bool1_obscur=true;
    }
    struct Data_Earth data_Earth={R0_EARTH,V0_EARTH};
    struct Data_Rocket data_Rocket={r0_Rocket,v0_Rocket};
    while(!stop_condition(code_exit,data_Earth,data_Rocket,tab_Rocket->size)){
        struct Data_Earth data_Earth_news=calc_Data_Earth(data_Earth);
        struct Data_Rocket data_Rocket_news=calc_Data_Rocket(data_Rocket);
        //Filling
        add_Tab_Earth(tab_Earth,data_Earth);
        add_Tab_Rocket(tab_Rocket,data_Rocket);
        //Updates
        data_Earth=data_Earth_news;
        data_Rocket=data_Rocket_news;
    }
    //
    if(CHEAT_CODE && bool1_obscur){
        *code_exit=ATTERRISSAGE;
    }
    return true;
}


