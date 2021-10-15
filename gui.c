//#include "config.h"
#include "includes.h"
#include "config.h"

TTF_Font *police = NULL;

SDL_Color blackC = {0, 0, 0};
SDL_Color whiteC = {255, 255, 255};
SDL_Color redC = {255, 0, 0};
SDL_Color greenC = {0,255, 0};

SDL_Color m1Color;
SDL_Color m2Color;
SDL_Color m3Color;

char *title = "Hole In Black !";
char *m1 = "1 - VShoot";
char *m2 = "2 - HShoot";
char *m3 = "3 - Asteroid";



void displayGui(int move)
{

    if (game.cross==1)
        game.type=game.guiState+1;
    if (game.left==1)
        game.guiState=0;
    if (game.up==1)
        game.guiState=1;
    if (game.right==1)
        game.guiState=2;


    if (game.guiState==0)
    {
        m1Color=redC;
        m2Color=whiteC;
        m3Color=whiteC;
    }
    else if (game.guiState==1)
    {
        m1Color=whiteC;
        m2Color=redC;
        m3Color=whiteC;
    }
    else if (game.guiState==2)
    {
        m1Color=whiteC;
        m2Color=whiteC;
        m3Color=redC;
                //if game.right = 1 nothing
    }
    int texW, texH;
    SDL_Surface *surfaceF = TTF_RenderText_Solid(police,title, whiteC);
    SDL_Texture *texture= SDL_CreateTextureFromSurface(game.renderer, surfaceF);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect titleRect; //create a rect
    titleRect.x = (SCREEN_WIDTH-texW) /2;  //controls the rect's x coordinate
    titleRect.y = 10; // controls the rect's y coordinte
    titleRect.w = texW; // controls the width of the rect
    titleRect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, texture, NULL, &titleRect);

    SDL_Surface *surfaceM1 = TTF_RenderText_Solid(police,m1, m1Color);
    SDL_Texture *textureM1= SDL_CreateTextureFromSurface(game.renderer, surfaceM1);
    SDL_QueryTexture(textureM1, NULL, NULL, &texW, &texH);
    SDL_Rect m1Rect; //create a rect
    m1Rect.x = 10;  //controls the rect's x coordinate
    m1Rect.y = 60; // controls the rect's y coordinte
    m1Rect.w = texW; // controls the width of the rect
    m1Rect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, textureM1, NULL, &m1Rect);

    SDL_Surface *surfaceM2 = TTF_RenderText_Solid(police,m2, m2Color);
    SDL_Texture *textureM2= SDL_CreateTextureFromSurface(game.renderer, surfaceM2);
    SDL_QueryTexture(textureM2, NULL, NULL, &texW, &texH);
    SDL_Rect m2Rect; //create a rect
    m2Rect.x = 200;  //controls the rect's x coordinate
    m2Rect.y = 60; // controls the rect's y coordinte
    m2Rect.w = texW; // controls the width of the rect
    m2Rect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, textureM2, NULL, &m2Rect);

    SDL_Surface *surfaceM3 = TTF_RenderText_Solid(police,m3, m3Color);
    SDL_Texture *textureM3= SDL_CreateTextureFromSurface(game.renderer, surfaceM3);
    SDL_QueryTexture(textureM3, NULL, NULL, &texW, &texH);
    SDL_Rect m3Rect; //create a rect
    m3Rect.x = 400;  //controls the rect's x coordinate
    m3Rect.y = 60; // controls the rect's y coordinte
    m3Rect.w = texW; // controls the width of the rect
    m3Rect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, textureM3, NULL, &m3Rect);





}

void displayLifes()
{

    if (vship.lifes<=0)
    {
        game.type=10;
        displayGameOver();
    }

    int texW, texH;
    char txt[8]="LIFES ";
    char lifes[8];
    sprintf(lifes, "%d", vship.lifes);
    strcat(txt,lifes);

    SDL_Surface *surfaceF = TTF_RenderText_Solid(police,txt, whiteC);
    SDL_Texture *texture= SDL_CreateTextureFromSurface(game.renderer, surfaceF);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect titleRect; //create a rect
    titleRect.x = 10;  //controls the rect's x coordinate
    titleRect.y = SCREEN_HEIGHT-30; // controls the rect's y coordinte
    titleRect.w = texW; // controls the width of the rect
    titleRect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, texture, NULL, &titleRect);
}

void displayScore()
{

    int texW, texH;
    char txt[128]="SCORE ";
    char score[120];
    sprintf(score, "%d", game.score);
    strcat(txt,score);

    SDL_Surface *surfaceF = TTF_RenderText_Solid(police,txt, whiteC);
    SDL_Texture *texture= SDL_CreateTextureFromSurface(game.renderer, surfaceF);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect titleRect; //create a rect
    titleRect.x = (SCREEN_WIDTH-texW) /2;  //controls the rect's x coordinate
    titleRect.y = SCREEN_HEIGHT-30; // controls the rect's y coordinte
    titleRect.w = texW; // controls the width of the rect
    titleRect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, texture, NULL, &titleRect);
}

void displayGameOver(){
    int texW, texH;


    SDL_Surface *surfaceF = TTF_RenderText_Solid(police,"GAME OVER", whiteC);
    SDL_Texture *texture= SDL_CreateTextureFromSurface(game.renderer, surfaceF);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect titleRect; //create a rect
    titleRect.x = (SCREEN_WIDTH-texW) /2;  //controls the rect's x coordinate
    titleRect.y = (SCREEN_HEIGHT-texH)/2; // controls the rect's y coordinte
    titleRect.w = texW; // controls the width of the rect
    titleRect.h = texH; // controls the height of the rect
    SDL_RenderCopy(game.renderer, texture, NULL, &titleRect);

}
