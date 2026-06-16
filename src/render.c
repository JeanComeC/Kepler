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
   // Trace de l'orbite parcourue
    for (int j = 0; j < i; j++)
    {
        double x = origin.x + tab->data[j].position.x * scale;
        double y = origin.y + tab->data[j].position.y * scale;

        DrawPixel((int)x, (int)y, DARKBLUE);
    }

    // Position actuelle
    double px = origin.x + tab->data[i].position.x * scale;
    double py = origin.y + tab->data[i].position.y * scale;

    DrawCircle((int)px, (int)py, 15, BLUE);
}

void drawRocket(struct Tab_Rocket* tab, int i, struct Coordinates origin, double scale){
    for(int j = 0; j <= i; j++){
    double px = origin.x + tab->data[j].position.x * scale;
    double py = origin.y - tab->data[j].position.y * scale;
    DrawCircle((int)px, (int)py, 2, RED);
}
// point actuel plus grand
double px = origin.x + tab->data[i].position.x * scale;
double py = origin.y - tab->data[i].position.y * scale;
DrawCircle((int)px, (int)py, 5, RED);
}

void drawEcranFin(enum Code_exit code){
    switch(code){
    case CRASH_SOLAIRE:
        DrawText("Vous avez brûlé dans le soleil", 960, 540, 50, RED);
        break;
    case ATTERRISSAGE:
        DrawText("Misson Accomplie !", 960, 540, 50, GREEN);
        break;
    case SORTIE_VIDE_SPATIAL:
        DrawText("Perdu dans le vide spacial", 960, 540, 50, RED);
        break;
    case CRASH_TERRESTRE:
         DrawText("crash sur la terre!", 960, 540, 50, RED);
         break;
    case PANNE_CARBURANT:
         DrawText("Panne de carburant", 960, 540, 50, RED);
         break;
    }
}


struct Coordinates render_v0_Rocket(){
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Intro Kepler");
    struct InputState input = {"", "", 0};
    struct Coordinates v0 = {0};
    bool finished = false;
    struct Coordinates stars[1080];
    
    while(!WindowShouldClose() && !finished){
        BeginDrawing();
        ClearBackground(BLACK);
        drawStars(stars, 1080);
       // Texte d'introduction
        DrawText(
            "Nous sommes le 3 Janvier 3026, après un millénaire dans une autre galaxie,\n"
            "l'humanité souhaite retourner sur Terre. On vous envoie avec votre équipage,\n"
            "en éclaireur, pour voir si la vie est de nouveau viable sur notre planète.\n"
            "Après un voyage de plusieurs années, vous arrivez enfin dans notre système solaire.\n"
            "Vous devez donc faire atterrir votre navette spatiale sur Terre.\n"
            "Y arriverez-vous ? L'avenir de l'humanité dépend de vous.",
            180, 120, 24, WHITE
        );

        // Instructions
        DrawText(
            "Entrez la vitesse initiale de la fusée (format : x.xxxxxxE+xx)",
            450, 380, 28, RAYWHITE
        );

        DrawText(
            "TAB : champ suivant    |    ENTREE : valider",
            650, 430, 22, GRAY
        );

        // Champs de saisie
        DrawText("Entrez vx :", 650, 560, 30, WHITE);
        DrawText(input.vx,      900, 560, 30, GREEN);

        DrawText("Entrez vy :", 650, 640, 30, WHITE);
        DrawText(input.vy,      900, 640, 30, GREEN);

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
    size_t i = 0;
    double scale = 300.0 / 3e+11;
    printf("size rocket: %zu\n", tab_Rocket->size);
    printf("size earth: %zu\n", tab_Earth->size);
    Camera2D camera = {0};
    camera.target = (Vector2){origin.x, origin.y};
    camera.offset = (Vector2){WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f};
    camera.zoom = 1.0f;
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 255});
        BeginMode2D(camera);
        drawStars(stars, 1080);
        drawSun(origin, 5);
        if(i >= tab_Rocket->size){
            drawEcranFin(*code_exit);
            } else {
            double px = origin.x + tab_Rocket->data[i].position.x * scale;
            double py = origin.y - tab_Rocket->data[i].position.y * scale;
            printf("rocket px:%f py:%f\n", px, py);  
            drawEarth(tab_Earth, i, origin, scale);
            drawRocket(tab_Rocket, i, origin, scale);
            }
        EndDrawing();
        camera.zoom += GetMouseWheelMove() * 0.1f;
        i+=10;

    }
    return true;
}