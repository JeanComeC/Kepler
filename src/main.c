#include "physic_calc.h"
#include "algo.h"
#include "export.h"
#include <stdio.h>

int main(void){
    struct Data_output* tabmain=create_tab_data(MAX_POINT);

    if(!writting_json(PATH_EXPORT_JSON,tabmain)){
        perror("Error in writting_json()\n");
        exit(1);
    }

    destroy_tab_data(tabmain);
    return 0;
}
