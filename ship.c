#include "includes.h"
#include "config.h"

HIB_Ship vship;

void initShip(void)
{
    //load ship img
    vship.img=IMG_Load("img/ship.png");
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
