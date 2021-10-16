


#include "includes.h"
#include "config.h"
#include "structs.h"


int isRunning = 1;


SDL_App game;


void init_sdl(void)
{

    SDL_Init(SDL_INIT_EVERYTHING);
	game.window = SDL_CreateWindow("Hole In Black", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
    	#ifdef VITA
	police = TTF_OpenFont("app0:/font/8-bit-hud.ttf", 15);
	#else
	police = TTF_OpenFont("font/8-bit-hud.ttf", 15);
	#endif


}

void quit_sdl(void)
{

    SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	TTF_Quit();
	SDL_Quit();

}
int main(int argv, char** args)
{
    //some inits
    memset(&game, 0, sizeof(SDL_App));

    game.type=0;
    game.guiState=0;
    game.crossP=0;
    game.squareP=0;
    game.score=0;
    game.level=2;
    vship.lifes=3;

    init_sdl();
    initShip();
    initVBg();
    initStation();
    game.timer=0;
    zeroEnemies();
    zeroBullet();
    #ifdef VITA
    game.joystick = 0;
    if (SDL_NumJoysticks() > 0) {
		SDL_JoystickEventState(SDL_ENABLE);
        game.joystick = SDL_JoystickOpen(0);
    }
    #endif // VITA


	while (isRunning==1)
	{
        //main loop
	    SDL_RenderClear(game.renderer);

        //get inputs
	    getInput();

	    if (game.type==0)
        {
            displayGui(0);
        }
        else if (game.type==1)
        {
            displayVBg();
            displayStation();
            spawnEnemies();
            displayEnemies();
            displayShip();
            vship.level=1;
        }
        else if (game.type==10)
        {
            displayVBg();
            displayGameOver();
        }

        displayScore();
        displayLifes();
        SDL_RenderPresent(game.renderer);
    }
	quit_sdl();
	return 0;
}
