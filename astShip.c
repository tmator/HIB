#include "includes.h"
#include "config.h"

HIB_Ship astShip;



void astDisplayShip()
{
    //move ship
    //displayBullet();
    if (game.left && astShip.x > 0)
        astShip.x -= 5;
    if (game.right && astShip.x < (SCREEN_WIDTH - astShip.w))
        astShip.x += 5;
    if (game.up && astShip.y > 0)
        astShip.y -= 5;
    if (game.down && astShip.y < (SCREEN_HEIGHT - astShip.h) - 30)
        astShip.y += 5;

    //display ship
    astShip.dstrect.x = astShip.x;
    astShip.dstrect.y = astShip.y;
    astShip.dstrect.w = astShip.w;
    astShip.dstrect.h = astShip.h;
    SDL_RenderCopy(game.renderer, astShip.tex, NULL, &astShip.dstrect);

   
    //printf("disp sh x %d y %d\n", astShip.x , astShip.y);

    int collEn = 0;
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (astEnemy[i].lifes > 0)
        {
            collEn = collisionCheck(astEnemy[i].dstrect, astShip.dstrect);
            if (collEn == 1)
            {
                astEnemy[i].alive = 0;
                astEnemy[i].lifes = 0;
                astShip.lifes--;
                printf("pouf ! \n");
            }
        }
    }
}

void astInitShip(void)
{
    //load ship img
#ifdef VITA
    astShip.img = IMG_Load("app0:/img/ship.png");
#else
    astShip.img = IMG_Load("img/ship.png");
#endif
    if (!astShip.img)
    {
        printf("error loading ship img\n");
        SDL_Quit();
    }
    //init ship values
    astShip.level = 0;
    astShip.tex = SDL_CreateTextureFromSurface(game.renderer, astShip.img);
    astShip.w = 50;
    astShip.h = 50;
    astShip.x = (SCREEN_WIDTH - astShip.w) / 2;
    astShip.y = SCREEN_HEIGHT - (astShip.h + 10) - 20;
    printf("init sh\n");
}
