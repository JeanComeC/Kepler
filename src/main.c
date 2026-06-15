#include "physic_calc.h"
#include "algo.h"
#include "logic.h"
#include "render.h"
#include <stdio.h>


// === MAIN ===

int main(void){
    //Initialization & Verification
    srand48(time(NULL));
    // if(MAX_POINT<3 || MAX_POINT!=(int)((365.25*24.0*3600.0)/H_PAS_TEMPOREL_SECONDE)){
    //     perror("Error MAX_POINT isn't valid.\n");
    //     exit(1);
    // }
    struct Tab_Earth tab_Earth=create_Tab_Earth();
    struct Tab_Rocket tab_Rocket=create_Tab_Rocket();

    //Calculation & Logic
    // if(!main_calculation(tabmain)){
    //     perror("Error in main_calculation()\n");
    //     destroy_tab_data(tabmain);
    //     exit(1);
    // }

    //Graphic render
    if(!main_render(&tab_Earth,&tab_Rocket)){
        perror("Error in main_render()\n");
        destroy_Tab_Earth(&tab_Earth);
        destroy_Tab_Rocket(&tab_Rocket);
        exit(1);
    }

    //Cleaning
    destroy_Tab_Earth(&tab_Earth);
    destroy_Tab_Rocket(&tab_Rocket);
    printf("Finished ...\n");
    return 0;
}
