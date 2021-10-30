#include "includes.h"
#include "config.h"



int collisionCheck(SDL_Rect a, SDL_Rect b )
{

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    //If none of the sides from A are outside B
    return 1;
}


void DrawCircle(SDL_Renderer* renderer, int x, int y, int radius)
{
    const int diameter = (radius * 2);

    int x2 = (radius - 1);
    int y2 = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x2 >= y2)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, x + x2, y - y2);
        SDL_RenderDrawPoint(renderer, x + x2, y + y2);
        SDL_RenderDrawPoint(renderer, x - x2, y - y2);
        SDL_RenderDrawPoint(renderer, x - x2, y + y2);
        SDL_RenderDrawPoint(renderer, x + y2, y - x2);
        SDL_RenderDrawPoint(renderer, x + y2, y + x2);
        SDL_RenderDrawPoint(renderer, x - y2, y - x2);
        SDL_RenderDrawPoint(renderer, x - y2, y + x2);

        if (error <= 0)
        {
            ++y2;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x2;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void DrawFCircle(SDL_Renderer* renderer, int x, int y, int radius)
{
    
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}
void getCoord(int x0, int y0, int x1, int y1) {

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    int cpt = 0;
    for (;;) {

//        tBull.coBull[cpt].x = x0;
//        tBull.coBull[cpt].y = y0;
        cpt++;

       
        if (x0 == x1 && y0 == y1)
        {
                break;
        }
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }

}
