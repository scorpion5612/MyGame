//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
#ifndef UI_INFO_C
#define UI_INFO_C

#include <SDL.h>
#include <SDL_ttf.h>
#include "uiInfo.h"
#include "graphics.h"

UIInfo newUIInfo(SDL_Renderer* renderer,SDL_Rect rect,char* text){
	UIInfo uiInfo;
	TTF_Font *font;
	SDL_Color color={254,254,254};
	SDL_Surface *surface;

	uiInfo.rect=rect;
	surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 100, 100, 100));
	uiInfo.background = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	font=TTF_OpenFont("Fonts/Aaargh/Aaargh.ttf", 400);
	if(!(surface=TTF_RenderText_Blended_Wrapped(font,text,color,0))) {
		//handle error here, perhaps print TTF_GetError at least
	} else {
		uiInfo.text=SDL_CreateTextureFromSurface(renderer, surface);
		SDL_SetTextureColorMod(uiInfo.text,255,255,0);
		//perhaps we can reuse it, but I assume not for simplicity.
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		font=NULL;
	}

	uiInfo.target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	SDL_SetRenderTarget(renderer, uiInfo.target);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, uiInfo.background, NULL, NULL);
	SDL_RenderCopy(renderer, uiInfo.text, NULL, NULL);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_DestroyTexture(uiInfo.text);
	SDL_DestroyTexture(uiInfo.background);

	return uiInfo;
}

void DrawUIInfo(Graphics* graphics,UIInfo uiInfo){
	SDL_RenderCopy(graphics->renderer, uiInfo.target, NULL, &uiInfo.rect);
}

void FreeUIInfo(UIInfo* uiInfo){
	if(uiInfo->target!=NULL){
		SDL_DestroyTexture(uiInfo->target);
		uiInfo->target = NULL;
	}
}

#endif
