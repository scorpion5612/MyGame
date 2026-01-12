//Ivan Alejandro Rodriguez Ruiz 09/Junio/2025
#ifndef UI_TOP_H
#define UI_TOP_H

#include <SDL.h>
#include "graphics.h"

typedef struct{
	SDL_Texture *target,*text,*background;
	SDL_Rect rect;
}UIResources;

UIResources newUIResources(SDL_Renderer* renderer,SDL_Rect rect,char* text);
void DrawUIResources(Graphics* graphics,UIResources uiResources);
void FreeUIResources(UIResources* uiResources);

#endif