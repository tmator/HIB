#include "includes.h"
#include "config.h"
#include <string.h>

#define ST_SIZE 20

HIB_Station station[STATION_SIZE_MAX];

SDL_Surface *dest;
SDL_Texture *texDest;

void initStation(void)
{
    #ifdef VITA
    dest = IMG_Load("app0:/img/sd.png");
    #else
    dest = IMG_Load("img/sd.png");
    #endif
    texDest= SDL_CreateTextureFromSurface(game.renderer, dest);
    int cptx=0,cpty=0,cpt=0;
    char filename[ST_SIZE]="";
    char name[ST_SIZE];
    char ch;

    #ifdef VITA
    //dest = IMG_Load("app0:/level/");
    //strcat(filename,"ux0:/app/HIB000001/level/");
    #else
    strcat(filename,"level/");
    #endif
    //TODO
    //itoa(game.level,name,10);
    strcat(name, ".txt");
    strcat(filename, name);
    #ifdef VITA
    FILE* f = fopen("app0:/level/2.txt","rb");
    #else
    FILE* f = fopen("level/2.txt","rb");
    #endif
    if (f == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
	exit(0);
    }

char buffer[100];
    fread(buffer, 200, 1, f);
    
    for (int col=0; col<26;col++)
    {
		if (buffer[col]!=0x0A)
		{
		    if (buffer[col]!='0')
            {


            station[cpt].x=(cptx*100)+100;
            station[cpt].y=(cpty*100)+10;
            station[cpt].lifes=3;

            station[cpt].type=&buffer[col];

            memset(filename, 0, sizeof(filename));
            memset(name, 0, sizeof(name));
    	    #ifdef VITA
    	    strcat(filename,"app0:/img/");
    	    #else
    	    strcat(filename,"img/");
    	    #endif
            strncat(name, &buffer[col], 1);
            strcat(name, ".png");
            strcat(filename, name);
            station[cpt].img=IMG_Load(filename);

            if(!station[cpt].img)
            {
                printf("IMG_Load: %s\n", IMG_GetError());
                SDL_Quit();
            }

            station[cpt].tex = SDL_CreateTextureFromSurface(game.renderer, station[cpt].img);
            station[cpt].dstrect.x = station[cpt].x;
            station[cpt].dstrect.y = station[cpt].y;
            station[cpt].dstrect.w = 100;
            station[cpt].dstrect.h = 100;
            cptx++;
            cpt++;
            }
            else
                cptx++;
		}
		else
		{
		//new line
		cptx=0;
		cpty++;
		}

    }
    
}

void displayStation(void)
{
    for (int i=0; i<(int)( sizeof(station) / sizeof(station[0])); i++)
    {
        if (station[i].lifes<=0)
            SDL_RenderCopy(game.renderer, texDest, NULL, &station[i].dstrect);
        else
            SDL_RenderCopy(game.renderer, station[i].tex, NULL, &station[i].dstrect);
    }
}

