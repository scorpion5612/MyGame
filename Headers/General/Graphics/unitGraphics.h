//Ivan Alejandro Rodriguez Ruiz 28/Marzo/2024
#ifndef UNIT_GRAPHICS_H
#define UNIT_GRAPHICS_H

#include <SDL.h>
#include "graphics.h"
#include "../unit.h"

typedef struct{
	SDL_Texture *Tunit;
	Unit unit;

    unsigned int x,y; //coordenadas
}unitGraphics;

unitGraphics newUnitGraphics(Graphics* graphic,Unit unit);
void DrawUnitGraphics(Graphics* graphics,unitGraphics* unit,SDL_Rect* rect);
void FreeUnitGraphics(unitGraphics* graphics);

#endif
