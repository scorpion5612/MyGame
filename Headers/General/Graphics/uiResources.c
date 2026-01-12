//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
#ifndef UI_TOP_C
#define UI_TOP_C

#include <SDL.h>
#include <SDL_ttf.h>
#include "uiResources.h"
#include "graphics.h"

UIResources newUIResources(SDL_Renderer* renderer,SDL_Rect rect,char* text){
	UIResources uiResources;
	TTF_Font *font;
	SDL_Color color={254,254,254};
	SDL_Surface *surface;

	uiResources.rect=rect;
	surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 100, 100, 100));
	uiResources.background = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	font=TTF_OpenFont("Fonts/Aaargh/Aaargh.ttf", 400);
	if(!(surface=TTF_RenderText_Blended_Wrapped(font,text,color,0))) {
		//handle error here, perhaps print TTF_GetError at least
	} else {
		uiResources.text=SDL_CreateTextureFromSurface(renderer, surface);
		SDL_SetTextureColorMod(uiResources.text,255,255,0);
		//perhaps we can reuse it, but I assume not for simplicity.
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		font=NULL;
	}

	uiResources.target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	SDL_SetRenderTarget(renderer, uiResources.target);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, uiResources.background, NULL, NULL);
	SDL_RenderCopy(renderer, uiResources.text, NULL, NULL);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_DestroyTexture(uiResources.text);
	SDL_DestroyTexture(uiResources.background);

	return uiResources;
}

void DrawUIResources(Graphics* graphics,UIResources uiResources){
	SDL_RenderCopy(graphics->renderer, uiResources.target, NULL, &uiResources.rect);
}

void FreeUIResources(UIResources* uiResources){
	if(uiResources->target!=NULL){
		SDL_DestroyTexture(uiResources->target);
		uiResources->target = NULL;
	}
}

#endif
