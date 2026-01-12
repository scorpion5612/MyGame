//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "graphics.h"

typedef struct{
	SDL_Texture *target[2],*text[2],*background;
	SDL_Rect rect;
}Button;

Button newButton(SDL_Renderer* renderer,SDL_Rect rect,char* text);
void DrawButton(Graphics* graphics,Button button);
void FreeButton(Button* button);

#endif
