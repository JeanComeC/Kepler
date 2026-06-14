#include "logic.h"

//



// ===

bool main_logic(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket){
    //
    return true;
}


// bool main_calculation(struct Data_output* tabmain){
//     struct Coordinates vect_v=v0_Earth;
//     struct Coordinates vect_r=r0_Earth;
//     for(size_t i=0;i<MAX_POINT;i++){
//         struct Coordinates vect_acc=calc_acceleration(vect_r);
//         struct Coordinates vect_v_news=calc_vitesse(vect_v,vect_acc);
//         struct Coordinates vect_r_news=calc_position(vect_r,vect_v_news);
//         //Filling
//         tabmain[i].t=H_PAS_TEMPOREL_SECONDE*i;
//         tabmain[i].coordinates=vect_r;
//         //Updates
//         vect_v=vect_v_news;
//         vect_r=vect_r_news;
//     }
//     return true;
// }