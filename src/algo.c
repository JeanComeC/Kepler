#include "algo.h"


struct Tab_Earth create_Tab_Earth(){
    struct Tab_Earth tab;
    struct Data_Earth* data=malloc(2*sizeof(struct Data_Earth));
    if(!data){
        perror("Error: memory allocation (01).\n");
        exit(1);
    }
    tab.data=data;
    tab.capacity=2;
    tab.size=0;
    return tab;
}

void add_Tab_Earth(struct Tab_Earth* tab_Earth,struct Data_Earth new_data){
    if(tab_Earth->size>=tab_Earth->capacity){
        struct Data_Earth* new_tab=malloc(tab_Earth->capacity*sizeof(struct Data_Earth)*2);
        if(!new_tab){
            perror("Error: memory allocation (02).\n");
            exit(1);
        }
        tab_Earth->capacity*=2;
        for(size_t i=0;i<tab_Earth->size;i++){
            new_tab[i]=tab_Earth->data[i];
        }
        free(tab_Earth->data);
        tab_Earth->data=new_tab;
    }
    tab_Earth->data[tab_Earth->size]=new_data;
    tab_Earth->size++;
}

void destroy_Tab_Earth(struct Tab_Earth* tab_Earth){
    free(tab_Earth->data);
    tab_Earth->data=NULL;
    tab_Earth->capacity=0;
    tab_Earth->size=0;
}

// ===

struct Tab_Rocket create_Tab_Rocket(){
    struct Tab_Rocket tab;
    struct Data_Rocket* data=malloc(2*sizeof(struct Data_Rocket));
    if(!data){
        perror("Error: memory allocation (10).\n");
        exit(1);
    }
    tab.data=data;
    tab.capacity=2;
    tab.size=0;
    return tab;
}

void add_Tab_Rocket(struct Tab_Rocket* tab_Rocket,struct Data_Rocket new_data){
    if(tab_Rocket->size >= tab_Rocket->capacity){
        struct Data_Rocket* new_tab=realloc(tab_Rocket->data,tab_Rocket->capacity*sizeof(struct Data_Rocket)*2);
        if (!new_tab){perror("Error: memory allocation (20).\n"); exit(1);}
        tab_Rocket->capacity*=2;
        tab_Rocket->data=new_tab;
    }
    tab_Rocket->data[tab_Rocket->size++]=new_data;
}

void destroy_Tab_Rocket(struct Tab_Rocket* tab_Rocket){
    free(tab_Rocket->data);
    tab_Rocket->data=NULL;
    tab_Rocket->capacity=0;
    tab_Rocket->size=0;
}

// ===

