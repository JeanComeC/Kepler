#include "render.h"
#include "src/algo.h"
#include <raylib.h>
#include <stddef.h>




void starInit(struct Coordinates stars[], int n){
    
    
    for(int i = 0; i <= n; i ++){
        int positionWidth = rand()% WINDOW_WIDTH;
        int positionHeight = rand()% WINDOW_HEIGHT;
        stars[i].x = positionWidth;
        stars[i].y = positionHeight;

    }

}

void drawSun(struct Coordinates origin , int nbr_circle){
    for (int i = 1 ; i <= nbr_circle; i++){
        float rayon = i * 20;
        int alpha = 255 / i;
        DrawCircle(origin.x, origin.y, rayon, (Color){253, 249, 0, alpha});
    }
}

void drawStars(struct Coordinates star[], int n){
    for(int i = 0; i < n; i++ ){
      DrawPixel(star[i].x, star[i].y, (Color){255, 255, 255, 255});
    }
}


bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "KEPLER");
    struct Coordinates stars[1080];
    starInit(stars, 1080);
     struct Coordinates origin;
     origin.x = 960;
     origin.y = 540;
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 255});
        drawStars(stars, 1080);
        drawSun(origin, 5);

        EndDrawing();
    }


    return true;
}
