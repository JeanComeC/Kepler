#include "physic_calc.h"
#include "algo.h"
#include "export.h"
#include <stdio.h>


int main(void){
    //Initialization & Verification
    if(MAX_POINT<3 || MAX_POINT!=(int)(365.25*(24.0/H_PAS_TEMPOREL_HEURE))){
        perror("Error MAX_POINT isn't valid.\n");
        exit(1);
    }
    struct Data_output* tabmain=create_tab_data(MAX_POINT);

    //Calculation
    if(!main_calculation(tabmain)){
        perror("Error in main_calculation()\n");
        destroy_tab_data(tabmain);
        exit(1);
    }

    //Writting & Export
    // if(!writting_json(PATH_EXPORT_JSON,tabmain)){
    //     perror("Error in writting_json()\n");
    //     destroy_tab_data(tabmain);
    //     exit(1);
    // }

    //Cleaning
    destroy_tab_data(tabmain);
    printf("Finished ...\n");
    return 0;
}
