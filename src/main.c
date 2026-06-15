#include "physic_calc.h"
#include "algo.h"
#include "logic.h"
#include "render.h"
#include <stdio.h>


// === MAIN ===

int main(void){
    //Initialization & Verification
    srand48(time(NULL));
    struct Tab_Earth tab_Earth=create_Tab_Earth();
    struct Tab_Rocket tab_Rocket=create_Tab_Rocket();

    //Calculation & Logic
    if(!main_logic(&tab_Earth,&tab_Rocket)){
        perror("Error in main_logic()\n");
        destroy_Tab_Earth(&tab_Earth);
        destroy_Tab_Rocket(&tab_Rocket);
        exit(1);
    }

    // for(int i=0;i<tab_Earth.size;i++){
    //     printf("xp:%E, yp:%E, zp:%E, xv:%E, yv:%E, zv:%E\n",tab_Earth.data[i].position.x,tab_Earth.data[i].position.y,tab_Earth.data[i].position.z,tab_Earth.data[i].vitesse.x,tab_Earth.data[i].vitesse.y,tab_Earth.data[i].vitesse.z);
    // }

    //Graphic render
    // if(!main_render(&tab_Earth,&tab_Rocket)){
    //     perror("Error in main_render()\n");
    //     destroy_Tab_Earth(&tab_Earth);
    //     destroy_Tab_Rocket(&tab_Rocket);
    //     exit(1);
    // }

    //Cleaning
    destroy_Tab_Earth(&tab_Earth);
    destroy_Tab_Rocket(&tab_Rocket);
    printf("Finished ...\n");
    return 0;
}
