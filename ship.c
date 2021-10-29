#include "includes.h"
#include "config.h"

HIB_Ship vship;
HIB_TShip tship;

void initShip(void)
{
    //load ship img
#ifdef VITA
    vship.img=IMG_Load("app0:/img/ship.png");
#else
    vship.img=IMG_Load("img/ship.png");
#endif
    if(!vship.img)
	{
		SDL_Quit();
	}
	//init ship values
	vship.level=0;
	vship.tex = SDL_CreateTextureFromSurface(game.renderer, vship.img);
	vship.w=50;
	vship.h=50;
	vship.x = (SCREEN_WIDTH-vship.w) /2;
	vship.y = SCREEN_HEIGHT-(vship.h+10)-20;

}

void displayShip()
{
    //move ship
    displayBullet();
    if (game.left && vship.x>0)
        vship.x-=5;
    if (game.right && vship.x<(SCREEN_WIDTH-vship.w))
        vship.x+=5;
    if (game.up && vship.y>0)
        vship.y-=5;
    if (game.down  && vship.y<(SCREEN_HEIGHT-vship.h)-30)
        vship.y+=5;

    //display ship
    vship.dstrect.x = vship.x;
    vship.dstrect.y = vship.y;
    vship.dstrect.w = vship.w;
    vship.dstrect.h = vship.h;
    SDL_RenderCopy(game.renderer, vship.tex, NULL, &vship.dstrect);

    //init bullet values when chick X
    if (game.cross ==1 && game.crossP==0 && vship.level>0)
    {
        initBullet(vship.x+(vship.w/2), vship.y, vship.level);
        game.crossP=1;
    }

    //check coll between ship and enemiess
    int collEn=0;
    for (int i=0; i<MAX_ENEMIES; i++)
    {
        if (enemy[i].lifes >0)
        {
            collEn = collisionCheck(enemy[i].dstrect,vship.dstrect);
            if (collEn==1)
            {
                enemy[i].alive=0;
                enemy[i].lifes=0;
                vship.lifes--;
            }
        }
    }



}

void displayTShip()
{
    //move ship
    //displayBullet();
    /*/if (left && tship.x > 0)
        tship.x -= 5;
    if (right && tship.x < (SCREEN_WIDTH - tship.w))
        tship.x += 5;
    if (up && tship.y > 0)
        tship.y -= 5;
    if (down && tship.y < (SCREEN_HEIGHT - tship.h) - 30)
        tship.y += 5;
        */
    //display ship
    tship.dstrect.x = tship.x;
    tship.dstrect.y = tship.y;
    tship.dstrect.w = tship.w;
    tship.dstrect.h = tship.h;
    //SDL_RenderCopy(renderer, tship.tex, NULL, &tship.dstrect);
    SDL_RenderCopyEx(renderer, tship.tex, NULL, &tship.dstrect, tship.ang, NULL, SDL_FLIP_NONE); //keys[SDL_SCANCODE_F] ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);

}

void initTShip(void)
{
    //load ship img
#ifdef VITA
    tship.img = IMG_Load("app0:/img/ship.png");
#else
    tship.img = IMG_Load("img/ship.png");
#endif
    if (!tship.img)
    {
        printf("error loading ship img\n");
        SDL_Quit();
    }
    //init ship values
    tship.level = 0;
    tship.tex = SDL_CreateTextureFromSurface(renderer, tship.img);
    tship.w = 50;
    tship.h = 50;
    tship.x = (SCREEN_WIDTH - tship.w) / 2;
    tship.y = SCREEN_HEIGHT - (tship.h + 10) - 20;
    printf("init sh\n");
}

void drawTShip()
{

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    //get ship pos

    if (right == 1)
    {
        posX++;
    }
    else if (left == 1)
    {
        posX--;
    }
    if (posX > 15)
    {
        posX = 0;
    }
    if (posX < 0)
    {
        posX = 15;
    }

    int xMh = (tubeCircle[tab][posX][posY] + tubeCircle[tab][posX + 1][posY]) / 2;
    int yMh = (tubeCircle[tab][posX][posY + 1] + tubeCircle[tab][posX + 1][posY + 1]) / 2;

    int xMb = (tubeCircle[1][posX][posY] + tubeCircle[1][posX + 1][posY]) / 2;
    int yMb = (tubeCircle[1][posX][posY + 1] + tubeCircle[1][posX + 1][posY + 1]) / 2;

    if (cross == 1)
    {
        if (tBull.alive == 0)
        {
            tBull.alive = 1;
            memset(tBull.coBull, 0, sizeof tBull.coBull);
            tBull.cpt = 0;
            getCoord(xMh, yMh, xMb, yMb);
            tBull.coSize = (int)(sizeof(tBull.coBull) / sizeof(tBull.coBull[0]));
        }
    }

    if (tBull.alive == 1)
    {
        tBull.cpt+=5;
        if (tBull.cpt > tBull.coSize || tBull.coBull[tBull.cpt].x == 0 || tBull.coBull[tBull.cpt].y == 0)
        {
            tBull.alive = 0;
        }
        else
        {
            DrawFCircle(renderer, tBull.coBull[tBull.cpt].x, tBull.coBull[tBull.cpt].y, 3);

        }
    }
    
    SDL_RenderDrawLine(renderer, tubeCircle[0][posX][posY], tubeCircle[0][posX][posY+1], tubeCircle[1][posX][posY], tubeCircle[1][posX][posY + 1]);
    SDL_RenderDrawLine(renderer, tubeCircle[0][posX + 1][posY], tubeCircle[0][posX + 1][posY + 1], tubeCircle[1][posX + 1][posY], tubeCircle[1][posX + 1][posY + 1]);
    

    SDL_RenderDrawLine(renderer, tubeCircle[tab][posX][posY], tubeCircle[tab][posX][posY + 1], tubeCircle[tab][posX + 1][posY], tubeCircle[tab][posX + 1][posY + 1]);
    
    //int xMh = (tubeCircle[tab][posX][posY] + tubeCircle[tab][posX + 1][posY]) / 2;
    //int yMh = (tubeCircle[tab][posX][posY + 1] + tubeCircle[tab][posX + 1][posY + 1]) / 2;

    //int xMb = (tubeCircle[1][posX][posY] + tubeCircle[1][posX + 1][posY]) / 2;
    //int yMb = (tubeCircle[1][posX][posY + 1] + tubeCircle[1][posX + 1][posY + 1]) / 2;
    SDL_RenderDrawLine(renderer, xMh, yMh, xMb, yMb);
    tship.x = xMh-(tship.w/2);
    tship.y = yMh-(tship.h/2);
     
    tship.ang = (atan2(yMh - yMb, xMh - xMb) * 180 / M_PI) - 90;
    //displayShip();

}