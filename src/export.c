#include "export.h"

bool writting_json(const char* path_json, struct Data_output* tab_data){
    FILE *f0 = fopen(path_json, "w");// "w" = option for create file
    if(!f0){
        perror("Error create file\n");
        return false;
    }
    fprintf(f0,"[\n");
    for(size_t i=0;i<MAX_POINT-1;i++){//on enleve le dernier élément de la boucle
        fprintf(f0,"{ \"t\": %E,",tab_data[i].t);
        fprintf(f0," \"x\": %E,",tab_data[i].coordinates.x);
        fprintf(f0," \"y\": %E,",tab_data[i].coordinates.y);
        fprintf(f0," \"z\": %E,",tab_data[i].coordinates.z);
        fprintf(f0," \"ke\": %E,",tab_data[i].ke);
        fprintf(f0," \"pe\": %E }",tab_data[i].pe);
        fprintf(f0,",\n");
    }
    fprintf(f0,"{ \"t\": %E, \"x\": %E, \"y\": %E, \"z\": %E, \"ke\": %E, \"pe\": %E }\n",tab_data[MAX_POINT-1].t,tab_data[MAX_POINT-1].coordinates.x,tab_data[MAX_POINT-1].coordinates.y,tab_data[MAX_POINT-1].coordinates.z,tab_data[MAX_POINT-1].ke,tab_data[MAX_POINT-1].pe);
    fprintf(f0,"]");
    //
    fclose(f0);
    return true;
}

