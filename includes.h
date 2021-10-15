#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "structs.h"
#include "gui.h"
#include "enemy.h"
#include "display.h"
#include "input.h"
#include "bullet.h"
#include "ship.h"
#include "spacestation.h"
#include "util.h"
#include "config.h"

#ifdef VITA

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#endif // VITA

extern SDL_App game;
extern HIB_Ship vship;
extern HIB_Station station[STATION_SIZE_MAX];
extern HIB_Enemy enemy[MAX_ENEMIES];


extern TTF_Font *police;
extern SDL_Color blackC;
extern SDL_Color whiteC;
extern SDL_Color redC;
extern SDL_Color greenC;


#endif // INCLUDES_H_INCLUDED
