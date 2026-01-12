//Ivan Alejandro Rodriguez Ruiz 09/Junio/2025
#ifndef UI_INFO_H
#define UI_INFO_H

#include <SDL.h>
#include "graphics.h"

typedef struct{
	SDL_Texture *target,*text,*background;
	SDL_Rect rect;
}UIInfo;

UIInfo newUIInfo(SDL_Renderer* renderer,SDL_Rect rect,char* text);
void DrawUIInfo(Graphics* graphics,UIInfo uiInfo);
void FreeUIInfo(UIInfo* uiInfo);

#endif
