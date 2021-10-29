


#include "includes.h"
#include "config.h"
#include "structs.h"


int isRunning = 1;
int start=0;

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
void resetAll(void)
{

}
void initAll(void)
{
    game.type=0;
    game.guiState=0;
    game.crossP=0;
    game.squareP=0;
    game.score=0;
    game.level=2;

}

void initVshoot(void)
{

    initShip();
    vship.lifes=3;
    initStation();
    zeroEnemies();
    zeroBullet();
    game.timer=0;

}
void initAst(void)
{

    astInitShip();
    vship.lifes=3;
    zeroEnemies();
    game.timer=0;

}

void initTube()
{
	initTShip();
	tship.lifes=3;
	game.timer=0;
}



int main(int argv, char** args)
{
    //some inits
    memset(&game, 0, sizeof(SDL_App));


    init_sdl();
    initAll();

    initVBg();
    printf("c");
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
            displayVBg();

        //get inputs
	//
	    getInput();
        //game.type=1;
        if (game.type==0)
        {
            displayGui(0);
        }
        else if (game.type==1)
        {
	    if (start==0)
	    {
		    start++;
		    initVshoot();
	    }
            displayStation();
            spawnEnemies();
            displayEnemies();
            displayShip();
            vship.level=1;
            displayScore();
            displayLifes();
        }
        else if (game.type==3) //Aste
		{
			if (start==0)
			{
				start++;
				initAst();
			}
			spawnAstEnemies();
			displayAstEnemies();
            astDisplayShip();

		}
		else if (game.type==4) //tube
		{
			if (start==0)
			{
				start++;
				initTube();
			}
			
			drawLevel();
            drawShip();

		}
        else if (game.type==10)
        {
            displayVBg();
            displayGameOver();
	    SDL_Delay(3000);
	    initAll();
	    start=0;
        }

        SDL_RenderPresent(game.renderer);
    }
	quit_sdl();
	return 0;
}
