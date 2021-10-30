rm a.out; gcc *.c `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lm; ./a.out 
