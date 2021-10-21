#include "includes.h"
#include "config.h"


HIB_Enemy enemy[MAX_ENEMIES];

//init enemies
void zeroEnemies(void)
{
    for (int i=0; i<MAX_ENEMIES; i++)
    {
        enemy[i].alive=0;
        enemy[i].lifes=0;
        enemy[i].bul.alive=0;
    }

}

//spawn enemies
void spawnEnemies(void)
{
    for (int i=0; i<MAX_ENEMIES; i++)
    {
        if (enemy[i].alive==0 && --game.timer <=0)
        {
            enemy[i].alive=1;
            enemy[i].lifes=(rand() % 2)+1;
#ifdef VITA
            enemy[i].img = IMG_Load("app0:/img/en1.png");
#else
            enemy[i].img = IMG_Load("img/en1.png");
#endif
            enemy[i].tex = SDL_CreateTextureFromSurface(game.renderer, enemy[i].img);
            enemy[i].x = rand() % SCREEN_WIDTH;
            enemy[i].y = 10;
            enemy[i].frame=0;
            enemy[i].dir=rand() % 2;
            enemy[i].dstrect.x=enemy[i].x;
            enemy[i].dstrect.y=enemy[i].y;
            enemy[i].dstrect.w=20;
            enemy[i].dstrect.h=20;
            game.timer = 120 - (rand() % 60);
        }
    }
}

//display enemies
void displayEnemies(void)
{
    for (int i=0; i<MAX_ENEMIES; i++)
    {

        if (enemy[i].lifes>0 )
        {
            if (enemy[i].frame==15)
            {

                if (enemy[i].dir==0)
                {
                    enemy[i].dstrect.x+=(5 + (rand() % 2));
                }
                else
                    enemy[i].dstrect.x-=(5 + (rand() % 2));

                enemy[i].frame=0;
                //fire if bullet not alive
                if (enemy[i].bul.alive==0)
                {
                    enemy[i].bul.rBull.w=5;
                    enemy[i].bul.rBull.h=15;
                    enemy[i].bul.rBull.x = enemy[i].dstrect.x-(enemy[i].bul.rBull.w/2);
                    enemy[i].bul.rBull.y = enemy[i].dstrect.y;
                    enemy[i].bul.type=2;
                    enemy[i].bul.alive=1;
                }
            }
            enemy[i].frame++;
            enemy[i].dstrect.y+=(2 + (rand() % 2));

            if (enemy[i].bul.alive==1)
            {
                SDL_SetRenderDrawColor( game.renderer, 255, 255, 0, 255 );
                if (enemy[i].bul.rBull.y>=SCREEN_HEIGHT)
                {
                    enemy[i].bul.alive=0;

                }
                else
                {
                    enemy[i].bul.rBull.y+=4;
                    SDL_RenderFillRect( game.renderer, &enemy[i].bul.rBull );
                }
                    //check coll between ship and enemiess bullets
                int collEn=0;

                collEn = collisionCheck(enemy[i].bul.rBull,vship.dstrect);
                if (collEn==1)
                {
                    enemy[i].bul.alive=0;
                    vship.lifes--;



                }

            }


            SDL_RenderCopy(game.renderer, enemy[i].tex, NULL, &enemy[i].dstrect);
        }
        if (enemy[i].dstrect.y>SCREEN_HEIGHT)
        {
            enemy[i].alive=0;
            enemy[i].lifes=0;
        }
    }
}
