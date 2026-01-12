//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
#ifndef BUTTON_C
#define BUTTON_C

#include <SDL.h>
#include <SDL_ttf.h>
#include "button.h"
#include "graphics.h"

Button newButton(SDL_Renderer* renderer,SDL_Rect rect,char* text){
	Button button;
	TTF_Font *font;
	SDL_Color color={254,254,254};
	SDL_Surface *surface;

	button.rect=rect;
	surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 100, 100, 100));
	button.background = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	font=TTF_OpenFont("Fonts/Aaargh/Aaargh.ttf", 400);
	if(!(surface=TTF_RenderText_Blended(font,text,color))) {
		//handle error here, perhaps print TTF_GetError at least
	} else {
		button.text[0]=SDL_CreateTextureFromSurface(renderer, surface);
		button.text[1]=SDL_CreateTextureFromSurface(renderer, surface);
		SDL_SetTextureColorMod(button.text[1],255,255,0);
		//perhaps we can reuse it, but I assume not for simplicity.
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		font=NULL;
	}

	button.target[0] = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	button.target[1] = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	SDL_SetRenderTarget(renderer, button.target[0]);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, button.background, NULL, NULL);
	SDL_RenderCopy(renderer, button.text[0], NULL, NULL);
	SDL_SetRenderTarget(renderer, button.target[1]);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, button.background, NULL, NULL);
	SDL_RenderCopy(renderer, button.text[1], NULL, NULL);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_DestroyTexture(button.text[0]);
	SDL_DestroyTexture(button.text[1]);
	SDL_DestroyTexture(button.background);

	return button;
}

void DrawButton(Graphics* graphics,Button button){
	if(inside(graphics,&button.rect)){
		SDL_RenderCopy(graphics->renderer, button.target[1], NULL, &button.rect);
	}else{
		SDL_RenderCopy(graphics->renderer, button.target[0], NULL, &button.rect);
	}
}

void FreeButton(Button* button){
	SDL_DestroyTexture(button->target[0]);
	SDL_DestroyTexture(button->target[1]);
}

#endif
