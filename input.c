#include "includes.h"

#ifdef VITA
int sRight, sLeft, sDown, sUp;
int sRelease = 0;

int stick_position(int direction) {
	int axis;
	int axisValue;

	if (direction == STICK_LEFT || direction == STICK_RIGHT) axis = 0;
	if (direction == STICK_UP || direction == STICK_DOWN) axis = 1;

	axisValue = SDL_JoystickGetAxis(game.joystick,axis);

	return (axisValue < -32000 && direction == STICK_LEFT)
	  || (axisValue > 32000 && direction == STICK_RIGHT)
	  || (axisValue < -32000 && direction == STICK_UP)
	  || (axisValue > 32000 && direction == STICK_DOWN);
}


void doPadDown(int button) {
    switch (button) {
        case BTN_CROSS:
            //fire
            game.cross=1;
            break;
        case BTN_START:
            //quit
            break;
        default:
            printf("Unknown ");
    }
}

void doPadUp(int button) {
    switch (button) {
        case BTN_CROSS:
            game.cross=0;
            //fire
            break;
        case BTN_START:
            //quit
            break;
        default:
            printf("Unknown ");
    }
}
#endif // VITA

void getInput(void)
{
	SDL_Event event;
    SDL_PumpEvents();
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
				    SDL_Quit();
				    exit(0);
				}

                doKeyDown(&event.key);
				break;

			case SDL_KEYUP:
				doKeyUp(&event.key);
				break;
            #ifdef VITA
            case SDL_JOYBUTTONUP:
                doPadUp(event.jbutton.button);
                break;
            case SDL_JOYBUTTONDOWN:
                doPadDown(event.jbutton.button);
                break;
            case SDL_JOYAXISMOTION:
                sRight = stick_position(STICK_RIGHT);
                sLeft = stick_position(STICK_LEFT);
                sDown = stick_position(STICK_DOWN);
                sUp = stick_position(STICK_UP);

                if (sRight)
                {
                    game.right = 1;
                    sRelease = 1;
                }
                else if (sLeft)
                {
                    game.left = 1;
                    sRelease = 1;
                }
                else if (sDown)
                {
                    game.down = 1;
                    sRelease = 1;
                }
                else if (sUp)
                {
                    game.up = 1;
                    sRelease = 1;
                }
                else if (sRelease)
                {
                    //release
                    sRelease = 0;
                    game.up = 0;
                    game.right = 0;
                    game.left = 0;
                    game.down = 0;
                }
                break;
            #endif // VITA

			default:
				break;
		}
	}
}


void doKeyUp(SDL_KeyboardEvent *event)
{

	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			game.up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			game.down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			game.left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			game.right = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_SPACE)
		{
			game.cross = 0;

		}
		if (event->keysym.scancode == SDL_SCANCODE_RETURN

)
		{
			game.square = 0;

		}



	}
}

void doKeyDown(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			game.up = 1;

		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			game.down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			game.left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			game.right = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_SPACE)
		{
			game.cross = 1;
			game.crossP=0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_RETURN)
		{
			game.square = 1;
			game.squareP=0;
		}
	}
}

/*


void getInput(void)
{

	SDL_Event event;
	int move=0;

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{
		    case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
				    quit_sdl();

				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
				    printf('l');
				    move=1;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
				    move=2;
				}
                if (event.key.keysym.sym == SDLK_SPACE)
				{
				    //launch
				}
			case SDL_QUIT:
			    quit_sdl();
				exit(0);
				break;


			default:
				break;
		}

	}

}

*/
