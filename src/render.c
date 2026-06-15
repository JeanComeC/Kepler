#include "render.h"
#include <raylib.h>




void starInit(struct Stars star[], int n){
    
    
    for(int i = 0; i <= n; i ++){
        int positionWidth = rand()% WINDOW_WIDTH;
        int positionHeight = rand()% WINDOW_HEIGHT;
        star[i].x = positionWidth;
        star[i].y = positionHeight;

    }

}

void drawStars(struct Stars star[], int n){
    for(int i = 0; i < n; i++ ){
      DrawPixel(star[i].x, star[i].y, (Color){255, 255, 255, 255});
    }
}


bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "KEPLER");
    struct Stars stars[200];
    starInit(stars, 200);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 255});
        drawStars(stars, 200);

        EndDrawing();
    }


    return true;
}
