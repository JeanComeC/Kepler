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

// int nb_random0(int min, int max, int* tab_prohibited, int size_tab_prohibited){//fonction qui retourne un entier aléatoire avec tableau interdit, et appel récursif.
//     int nbra=rand()%(max-min+1)+min;
//     if(size_tab_prohibited==0)return nbra;//si le tableau est vide, on return direct
//     if(size_tab_prohibited>=(max-min)+1)return -1;//et si le tableau est supérieur ou égale eux nombres de choix, c'est qu'il n'y a aucun choix possible.
//     for(int i=0;i<size_tab_prohibited;i++){
//         if(nbra==tab_prohibited[i]){
//             return nb_random0(min,max,tab_prohibited,size_tab_prohibited);
//         }
//     }
//     return nbra;
// }

// int nb_random1(int* tab_authorized, int size_tab_authorized){//fonction qui retourne aléatoirement un élément d'une liste d'entiers autorisés.
//     if(size_tab_authorized<1 || tab_authorized==NULL)return -1;//gestion d'erreur
//     int index_random=rand()%size_tab_authorized;
//     return tab_authorized[index_random];
// }
