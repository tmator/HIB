#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

int collisionCheck(SDL_Rect a, SDL_Rect b );
void DrawFCircle(SDL_Renderer* renderer, int x, int y, int radius);
void DrawCircle(SDL_Renderer* renderer, int x, int y, int raduis);
void getCoord(int x0, int y0, int x1, int y1);
#endif // UTIL_H_INCLUDED
