all:
	gcc -I SDL2/include/SDL2 -L SDL2/lib -o main main.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf