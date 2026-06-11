#include "algo.h"

struct Data_output* create_tab_data(size_t size_tab){
    struct Data_output* tab_data = calloc(size_tab,sizeof(struct Data_output));
    if(!tab_data){
        perror("Error memory in create_tab_data()\n");
        exit(1);
    }
    return tab_data;
}

void destroy_tab_data(struct Data_output* tab_data){
    free(tab_data);
    tab_data=NULL;
}


