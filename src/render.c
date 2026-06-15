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

void drawEarth(struct Tab_Earth* tab, int i, struct Coordinates origin, double scale){
    double px = origin.x + tab->data[i].position.x * scale;
    double py = origin.y - tab->data[i].position.y * scale;
    DrawCircle((int)px, (int)py, 5, BLUE);
}

struct Coordinates render_v0_Rocket(){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Intro Kepler");
    struct InputState input = {"", "", 0};
    struct Coordinates v0 = {0};
    bool finished = false;
    while(!WindowShouldClose() && !finished){
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Entrez la vitesse initiale de la fusée (format: x.xxxxxxE+xx)", 100, 40, 18, RAYWHITE);
        DrawText("Utilisez TAB pour passer au champ suivant, ENTREE pour valider.", 100, 65, 16, GRAY);

        DrawText("Entrez vx:", 100, 120, 20, WHITE);
        DrawText(input.vx, 300, 120, 20, GREEN);
        DrawText("Entrez vy:", 100, 170, 20, WHITE);
        DrawText(input.vy, 300, 170, 20, GREEN);

        int touche = GetCharPressed();
        if((touche>='0' && touche<='9')||(touche=='.')||(touche=='E'||touche=='e')||(touche=='+'||touche=='-')){
            if (input.champ_actif == 0)
                strncat(input.vx, (char[]){touche, 0}, 1);
            else
                strncat(input.vy, (char[]){touche, 0}, 1);
        }
        if (IsKeyPressed(KEY_TAB))
            input.champ_actif = 1;
        if (IsKeyPressed(KEY_ENTER))
        {
            v0.x = atof(input.vx);
            v0.y = atof(input.vy);
            finished = true;
        }
        EndDrawing();
    }
    CloseWindow();
    return v0;
}

bool main_render(struct Tab_Earth* tab_Earth,struct Tab_Rocket* tab_Rocket, enum Code_exit* code_exit){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "KEPLER");
    struct Coordinates stars[1080];
    starInit(stars, 1080);
    struct Coordinates origin;
    origin.x = 960;
    origin.y = 540;
    int i = 0;
    double scale = 500.0 / 1.47e+11;
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 255});
        drawStars(stars, 1080);
        drawSun(origin, 5);
        drawEarth(tab_Earth, i, origin, scale);
        EndDrawing();
    
    }

    return true;

}