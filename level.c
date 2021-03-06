#include "includes.h"
#include "config.h"

int tubeCircle[2][17][2] = {
    {
        {476, 110}, {536, 123}, {588, 158}, {623, 210}, {636, 271}, {623, 331}, {588, 384}, {535, 418}, {476, 431}, {415, 418}, {363, 384}, {328, 331}, {315, 271}, {328, 210}, {363, 158}, {415, 123}, {476, 110}
     },
    {
        {476, 255}, {484, 257}, {493, 262}, {497, 270}, {500, 279}, {497, 289}, {493, 296}, {484, 301}, {476, 303}, {467, 301}, {458, 296}, {454, 289}, {451, 279}, {454, 270}, {458, 262}, {467, 257}, {476, 255}
    }
};


void drawLevel()
{
    SDL_SetRenderDrawColor(game.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    int i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 1; j++) {
            SDL_RenderDrawLine(game.renderer, tubeCircle[0][i][j], tubeCircle[0][i][j + 1], tubeCircle[1][i][j], tubeCircle[1][i][j + 1]);
            SDL_RenderDrawLine(game.renderer, tubeCircle[0][i][j], tubeCircle[0][i][j + 1], tubeCircle[0][i + 1][j], tubeCircle[0][i + 1][j + 1]);
            SDL_RenderDrawLine(game.renderer, tubeCircle[1][i][j], tubeCircle[1][i][j + 1], tubeCircle[1][i + 1][j], tubeCircle[1][i + 1][j + 1]);
            j++;
        }
    }
}
