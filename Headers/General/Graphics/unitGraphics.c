//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
//Last modified 05/Marzo/2021
#ifndef UNIT_GRAPHICS_C
#define UNIT_GRAPHICS_C

#include <SDL.h>
#include "unitGraphics.h"
#include "graphics.h"
#include "../definitions.h"
#include <stdio.h>


unitGraphics newUnitGraphics(Graphics *graphic,Unit unit){
	unitGraphics graphics;
	SDL_Surface *bitmapSurface = NULL;

    graphics.unit = unit;
	bitmapSurface = SDL_LoadBMP("Images/Greek/Units/Slave.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.Tunit = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);
	return graphics;
}

void DrawUnitGraphics(Graphics* graphics,unitGraphics* unit,SDL_Rect* rect){
	TTF_Font *font;
	SDL_Surface *surface;
	SDL_Rect aux;
	SDL_Color color={.r = 204, .g = 54, .b = 54};
	char text[4];

	SDL_RenderCopy(graphics->renderer,unit->Tunit, NULL,rect);

	//Show health
	aux.h = rect->h - 30;
	aux.w = rect->w - 40;
	aux.y = rect->y + rect->h - 40;
	aux.x = rect->x + 20;

	sprintf(text,"%d",unit->unit.attributes[HP]);

	font=TTF_OpenFont("Fonts/Aaargh/Aaargh.ttf", 400);
	if(!(surface=TTF_RenderText_Blended(font,text,color))) {
		//handle error here, perhaps print TTF_GetError at least
	} else {
		SDL_RenderCopy(graphics->renderer,SDL_CreateTextureFromSurface(graphics->renderer, surface), NULL,&aux);
		//perhaps we can reuse it, but I assume not for simplicity.
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		font=NULL;
	}
}

void FreeUnitGraphics(unitGraphics*  graphics){
	SDL_DestroyTexture(graphics->Tunit);
}

#endif
