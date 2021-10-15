#include "config.h"
#include "includes.h"


SDL_Surface *vbg;
SDL_Texture *tex;

//display background
void displayVBg(void){
    SDL_RenderCopy(game.renderer, tex, NULL, NULL);

}

//init and load background
void initVBg(void){
    vbg=IMG_Load("img/bg2.jpg");
    if(!vship.img)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		SDL_Quit();
	}
	tex = SDL_CreateTextureFromSurface(game.renderer, vbg);

}
