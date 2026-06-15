#include "render.h"
#include <raylib.h>

/*
    === TERRITOIRE DE JULES ===
*/


void starInit(struct Stars star[], int n){
    
    
    for(int i = 0; i <= n; i ++){
        int positionWidth = rand()% WINDOW_WIDTH;
        int positionHeight = rand()% WINDOW_HEIGHT;
        star[i].x = positionWidth;
        star[i].y = positionHeight;

    }

}

void drawSTars(struct Stars star[], int n){
    for(int i = 0; i < n; i++ ){
      Drawpixel(star[i].x, star[i].y, (Color){255, 255, 255, 255});
    }
}


bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "KEPLER");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 255});
        
    }


    return true;
}
