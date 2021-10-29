#include "includes.h"
#include "config.h"

void drawLevel()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    int i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 1; j++) {
            SDL_RenderDrawLine(renderer, tubeCircle[0][i][j], tubeCircle[0][i][j + 1], tubeCircle[1][i][j], tubeCircle[1][i][j + 1]);
            SDL_RenderDrawLine(renderer, tubeCircle[0][i][j], tubeCircle[0][i][j + 1], tubeCircle[0][i + 1][j], tubeCircle[0][i + 1][j + 1]);
            SDL_RenderDrawLine(renderer, tubeCircle[1][i][j], tubeCircle[1][i][j + 1], tubeCircle[1][i + 1][j], tubeCircle[1][i + 1][j + 1]);
            j++;
        }
    }
}