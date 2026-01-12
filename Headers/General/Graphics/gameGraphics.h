//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
//Last modified 05/Marzo/2021
#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#include <SDL.h>
#include "graphics.h"
#include "button.h"
#include "uiInfo.h"
#include "uiResources.h"

typedef struct{
	SDL_Texture *terrain[7],*selected[3],*invisible,*Tmap;
	SDL_Rect rect;
	int posx, posy, numx, numy, offsetx, offsety, xaux, yaux;
	Button EndTurn;

	UIInfo uiInfo;
	UIResources uiResources;
	unitGraphics *uSelected;
	Building *bSelected;
	int xSelected,ySelected;
	bool showInfo;
}gameGraphics;

gameGraphics newGameGraphics(Graphics* graphic);
bool eventosGameGraphics(Graphics* graphics,Juego* game,gameGraphics* graphicsGame);
void updateUIResources(Graphics* graphics,Juego* game,gameGraphics* graphicsGame);
void updateGameGraphics(Graphics* graphics,Juego* game,gameGraphics* graphicsGame);
void DrawGameGraphics(Graphics* graphics,Juego* game,gameGraphics* graphicsGame);
void FreeGameGraphics(gameGraphics* graphics);

#endif
