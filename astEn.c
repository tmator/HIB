#include "includes.h"
#include "config.h"

HIB_Enemy astEnemy[MAX_ASTENEMIES];


void zeroAstEnemies(void)
{
    for (int i = 0; i < MAX_ASTENEMIES; i++)
    {
        astEnemy[i].alive = 0;
        astEnemy[i].lifes = 0;
        //astEnemy[i].bul.alive = 0;
    }

}

//spawn enemies
void spawnAstEnemies(void)
{
    for (int i = 0; i < MAX_ASTENEMIES; i++)
    {
        if (astEnemy[i].alive == 0 && --game.timer <= 0)
        {
            astEnemy[i].alive = 1;
            astEnemy[i].lifes = (rand() % 2) + 1;
#ifdef VITA
            astEnemy[i].img = IMG_Load("app0:/img/en1.png");
#else
            astEnemy[i].img = IMG_Load("img/en1.png");
            if (!astEnemy[i].img)
                printf("error img en \n");
#endif
            astEnemy[i].tex = SDL_CreateTextureFromSurface(game.renderer, astEnemy[i].img);
           
            astEnemy[i].x = rand() % SCREEN_WIDTH;
            astEnemy[i].y = 10;
            astEnemy[i].frame = 0;
            astEnemy[i].dir = rand() % 2;
            astEnemy[i].dstrect.x = astEnemy[i].x;
            astEnemy[i].dstrect.y = astEnemy[i].y;
            astEnemy[i].dstrect.w = 20;
            astEnemy[i].dstrect.h = 20;
            game.timer = 120 - (rand() % 60);
        }
    }
}

void displayAstEnemies(void)
{
    for (int i = 0; i < MAX_ASTENEMIES; i++)
    {

        if (astEnemy[i].lifes > 0)
        {
            if (astEnemy[i].frame == 15)
            {

                if (astEnemy[i].dir == 0)
                {
                    astEnemy[i].dstrect.x += (5 + (rand() % 2));
                }
                else
                    astEnemy[i].dstrect.x -= (5 + (rand() % 2));

                astEnemy[i].frame = 0;

            }
            astEnemy[i].frame++;
            astEnemy[i].dstrect.y += (2 + (rand() % 2));




            SDL_RenderCopy(game.renderer, astEnemy[i].tex, NULL, &astEnemy[i].dstrect);
        }
        if (astEnemy[i].dstrect.y > SCREEN_HEIGHT)
        {
            astEnemy[i].alive = 0;
            astEnemy[i].lifes = 0;
        }
    }
}
