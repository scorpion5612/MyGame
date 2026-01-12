//Ivan Alejandro Rodriguez Ruiz 08/Octubre/2020
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>

typedef struct{
	SDL_Window *win;
	int xMouse, yMouse,height, width, winx, winy;
	SDL_Renderer *renderer;
}Graphics;

bool Start();
bool Game(Graphics* graphics);
bool Menu(Graphics* graphics);
bool inside(Graphics* graphics,SDL_Rect* rect);

#endif
