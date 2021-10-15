#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "SDL2/SDL.h"
#include "config.h"

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	int type;
	int up;
	int down;
	int left;
	int right;

	int cross;
	int square;
	int crossP;
	int squareP;

    int level;
	int guiState;
    int timer;
	int score;
#ifdef VITA
    SDL_Joystick * joystick;
#endif // VITA
} SDL_App;

typedef struct {
	int x;
	int y;
	int w;
	int h;

	int lifes;
	int score;
	int level;
	int bonnus;
	SDL_Surface *img;
	SDL_Texture *tex;
	SDL_Rect dstrect;
} HIB_Ship;

typedef struct {
	int x;
	int y;
	int w;
	int h;

	int alive;
	int type; //0 green, 1 orange, 2 red
	SDL_Rect rBull;

} HIB_Bullet;

typedef struct {
    char *type; //(1,2,3...)
    int alive;
    int lifes;
    int x;
    int y;
    int w;
    int h;
	SDL_Surface *img;
	SDL_Texture *tex;
	SDL_Rect dstrect;
} HIB_Station;


typedef struct {
    char *type; //(1,2,3...)
    int alive;
    int lifes;
    int x;
    int y;
    int frame;
    int dir;
    int w;
    int h;
    HIB_Bullet bul;
	SDL_Surface *img;
	SDL_Texture *tex;
	SDL_Rect dstrect;
} HIB_Enemy;


#endif // STRUCTS_H_INCLUDED
