#include "logic.h"
#include "src/algo.h"

struct Coordinates init_random_position(){
    struct Coordinates position_Rocket_output={0};
    position_Rocket_output.x=random_double_for_position();
    position_Rocket_output.y=random_double_for_position();
    position_Rocket_output.z=0.0;
    return position_Rocket_output;
}

bool stop_condition(struct Data_Earth data_Earth, struct Data_Rocket data_Rocket,size_t nb_pas){
    return false;
}


// ===

bool main_logic(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket){
    struct Data_Earth data_Earth={R0_EARTH,V0_EARTH};
    struct Data_Rocket data_Rocket={/*fonction qui recupere la réponse du joueur*/{0},init_random_position()};
    while(!stop_condition(data_Earth,data_Rocket,tab_Rocket->size)){
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
    return true;
}

