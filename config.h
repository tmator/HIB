#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include "structs.h"
#include "gui.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544

#define MAX_BULLET 3
#define MAX_ENEMIES 10
#define STATION_SIZE_MAX 24


#ifdef VITA
#define STICK_UP 0
#define STICK_DOWN 1
#define STICK_LEFT 2
#define STICK_RIGHT 3

#define BTN_TRIANGLE 0
#define BTN_CIRCLE 1
#define BTN_CROSS 2
#define BTN_SQUARE 3
#define BTN_LTRIGGER 4
#define BTN_RTRIGGER 5
#define BTN_DOWN 6
#define BTN_LEFT 7
#define BTN_UP 8
#define BTN_RIGHT 9
#define BTN_SELECT 10
#define BTN_START 11
#endif // VITA


#endif // CONFIG_H_INCLUDED
