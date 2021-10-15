#include "config.h"
#include "includes.h"

HIB_Bullet bul[MAX_BULLET];

//init bullets
void zeroBullet(void)
{
    for (int i=0; i<MAX_BULLET; i++)
    {
        bul[i].alive=0;
    }
}


void initBullet(int x, int y, int type)
{
    int cpt=0;
    //check if slot enmpy
    for (int i=0; i<MAX_BULLET; i++)
    {
        if (cpt>0)
            break;
        if (bul[i].alive==0)
        {

            //we can create
            bul[i].rBull.w=5;
            bul[i].rBull.h=15;
            bul[i].rBull.x = x-(bul[i].rBull.w/2);
            bul[i].rBull.y = y;
            bul[i].type=type;
            bul[i].alive=1;
            cpt=1;
        }
    }
}


void displayBullet(void)
{

    for (int i=0; i<MAX_BULLET; i++)
    {
        if (bul[i].alive==1)
        {
            SDL_SetRenderDrawColor( game.renderer, 0, 0, 255, 255 );
            if (bul[i].rBull.y<=0)
            {
                bul[i].alive=0;

            }
            else
            {
                bul[i].rBull.y-=4;
                SDL_RenderFillRect( game.renderer, &bul[i].rBull );
            }
        }
    }

    //check coll between station and bullet
    
    int collSt=0;
    for (int i=0; i<STATION_SIZE_MAX; i++)
    {
        if (station[i].lifes >0)
        {
            for (int j=0; j<MAX_BULLET; j++)
            {
                if (bul[j].alive==1)
                {
                    collSt = collisionCheck(station[i].dstrect,bul[j].rBull);
                    if (collSt==1)
                    {
                        bul[j].alive=0;
                        station[i].lifes--;
                        game.score+=10;
                    }
                }

            }
        }
    }
    
    //check coll between enemies and bullet
    int collEn=0;
    for (int i=0; i<MAX_ENEMIES; i++)
    {
        if (enemy[i].lifes >0)
        {
            for (int j=0; j<MAX_BULLET; j++)
            {
                if (bul[j].alive==1)
                {
                    collEn = collisionCheck(enemy[i].dstrect,bul[j].rBull);
                    if (collEn==1)
                    {
                        bul[j].alive=0;
                        enemy[i].lifes--;
                        if (enemy[i].lifes<=0)
                            enemy[i].alive=0;
                        game.score+=5;
                    }
                }

            }
        }

    }
}
