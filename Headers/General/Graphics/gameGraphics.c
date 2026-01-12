//Ivan Alejandro Rodriguez Ruiz 19/Enero/2021
//Last modified 05/Marzo/2021
#ifndef GAME_GRAPHICS_C
#define GAME_GRAPHICS_C

#include <stdio.h>
#include <SDL.h>
#include "gameGraphics.h"
#include "../game.h"
#include "graphics.h"
#include "../definitions.h"
#include "uiInfo.h"
#include "../unit.h"
#include "unitGraphics.h"
#include "../movement.h"


gameGraphics newGameGraphics(Graphics *graphic){
	gameGraphics graphics;
	SDL_Surface *bitmapSurface = NULL;
	
	graphics.rect.w=70;
	graphics.rect.h=70;
	graphics.rect.y=0;
	graphics.rect.x=0;
	
	bitmapSurface = SDL_LoadBMP("Images/Terrain/blank.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Blank] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	graphics.selected[0] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	graphics.selected[1] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	graphics.selected[2] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);
	SDL_SetTextureColorMod(graphics.selected[0],255,0,0);
	SDL_SetTextureColorMod(graphics.selected[1],30,255,0);
	SDL_SetTextureColorMod(graphics.selected[2],0,0,255);
	SDL_SetTextureBlendMode(graphics.selected[0],SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(graphics.selected[1],SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(graphics.selected[2],SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(graphics.selected[0],120);
	SDL_SetTextureAlphaMod(graphics.selected[1],120);
	SDL_SetTextureAlphaMod(graphics.selected[2],120);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/plains.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Plains] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/forest.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Forest] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/bushes.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Bushes] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/stone.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Stone] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/ore.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Ore] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/Precipicio.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.terrain[Precipicio] = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	bitmapSurface = SDL_LoadBMP("Images/Terrain/clouds.bmp");
	SDL_SetColorKey( bitmapSurface, SDL_TRUE, SDL_MapRGB( bitmapSurface->format, 0, 0, 0 ) );
	graphics.invisible = SDL_CreateTextureFromSurface(graphic->renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	graphics.posx=0;
	graphics.posy=0;
	graphics.numx=0;
	graphics.numy=0;
	graphics.offsetx=0;
	graphics.offsety=0;
	graphics.xaux=0;
	graphics.yaux=0;
	graphics.xSelected=0; 
	graphics.ySelected=0;

	graphics.uSelected=NULL;
	graphics.bSelected=NULL;
	graphics.uiInfo.target=NULL;
	graphics.showInfo=1;
	graphics.uiResources.target=NULL;
	graphics.Tmap=SDL_CreateTexture(graphic->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,graphic->width, graphic->height);
	graphics.EndTurn = newButton(graphic->renderer,graphics.rect,"->");
	return graphics;
}

bool eventosGameGraphics(Graphics* graphics,Juego* game,gameGraphics* graphicsGame){
	SDL_Event e;
	SDL_Rect rect;
	char text[1024];
	rect.h = graphics->height/4;
	rect.w = graphics->width/2;
	rect.x = graphics->width/20;
	rect.y = graphics->height*5/7;
	while (SDL_PollEvent(&e)!=0) {
		switch(e.type){
			case SDL_QUIT:
				FreeGameGraphics(graphicsGame);
				FreeGame(game);
				return true;
			case SDL_MOUSEMOTION:
				SDL_GetGlobalMouseState(&graphics->xMouse,&graphics->yMouse);
				graphicsGame->yaux=(graphics->yMouse+graphicsGame->posy)/(graphicsGame->rect.h/2);
				graphicsGame->xaux=(graphics->xMouse+graphicsGame->posx)/(graphicsGame->rect.w*3/2);
				graphicsGame->rect.y=graphicsGame->yaux*(graphicsGame->rect.h/2)-graphicsGame->posy;
				graphicsGame->rect.x=graphicsGame->xaux*(graphicsGame->rect.w*3/2)-graphicsGame->posx;
				if(graphicsGame->yaux%2!=0){
					graphicsGame->rect.x+=(graphicsGame->rect.w*3/4);
				}
				if(!inside(graphics,&graphicsGame->rect)){
					graphicsGame->yaux--;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(e.button.button == SDL_BUTTON_RIGHT){
					graphicsGame->showInfo = !graphicsGame->showInfo;
					DrawGameGraphics(graphics,game,graphicsGame);
				}
				if(e.button.button != SDL_BUTTON_LEFT)return false;
				//mouse button actions
				if(inside(graphics,&graphicsGame->EndTurn.rect)){
					//change Turn
					ChangeTurn(game);
					updateUIResources(graphics,game,graphicsGame);
					ResetActions(game);
					DrawGameGraphics(graphics,game,graphicsGame);
				}else if(graphicsGame->uiInfo.target != NULL&&inside(graphics,&graphicsGame->uiInfo.rect)){
					//inside UIInfo
				}else if(InsideMap(game->mapa,graphicsGame->xaux,graphicsGame->yaux)){
					if(graphicsGame->uSelected!=NULL){
						//actions for selected unit
						if(CheckUnidad(&game->players[game->turno],&graphicsGame->uSelected->unit)){
							if(Move(&game->mapa,graphicsGame->uSelected,graphicsGame->xSelected,graphicsGame->ySelected,graphicsGame->xaux,graphicsGame->yaux)){
								Vision(&game->players[game->turno].mapa,graphicsGame->xaux,graphicsGame->yaux,graphicsGame->uSelected->unit.attributes[VISION]);
								graphicsGame->uSelected->unit.move = 0;
							}else if(Attack(&game->mapa,graphicsGame->xSelected,graphicsGame->ySelected,graphicsGame->xaux,graphicsGame->yaux)){
								graphicsGame->uSelected->unit.attack = 0;
							}
						}
						
						//cancels
						CancelMovement(&game->mapa,graphicsGame->uSelected,graphicsGame->xSelected,graphicsGame->ySelected,graphicsGame->uSelected->unit.attributes[MOVEMENT]+1);
						CancelAttack(&game->mapa,graphicsGame->uSelected,graphicsGame->xSelected,graphicsGame->ySelected,graphicsGame->uSelected->unit.attributes[RANGE]+1);
						graphicsGame->uSelected=NULL;
						FreeUIInfo(&graphicsGame->uiInfo);
						DrawGameGraphics(graphics,game,graphicsGame);
					}else if(graphicsGame->bSelected!=NULL){
						//actions for selected building
						graphicsGame->bSelected=NULL;
						DrawGameGraphics(graphics,game,graphicsGame);
					}else{
						//Selects unit or building
						if(game->mapa.tiles[graphicsGame->xaux][graphicsGame->yaux].unidad!=NULL){
							//Selects unit and possible actions
							graphicsGame->xSelected=graphicsGame->xaux;
							graphicsGame->ySelected=graphicsGame->yaux;
							graphicsGame->uSelected=game->mapa.tiles[graphicsGame->xSelected][graphicsGame->ySelected].unidad;
							if(graphicsGame->uSelected->unit.move)PossibleMovement(&game->mapa,graphicsGame->uSelected,graphicsGame->xSelected,graphicsGame->ySelected, graphicsGame->uSelected->unit.attributes[MOVEMENT]+1);
							if(graphicsGame->uSelected->unit.attack)PossibleAttack(&game->players[game->turno],&game->mapa,graphicsGame->uSelected,graphicsGame->xSelected,graphicsGame->ySelected, graphicsGame->uSelected->unit.attributes[RANGE]+1);
							//shows unit info
							FreeUIInfo(&graphicsGame->uiInfo);
							getUnitInfo(text,graphicsGame->uSelected->unit);
							graphicsGame->uiInfo = newUIInfo(graphics->renderer,rect,text);
							//draws
							DrawGameGraphics(graphics,game,graphicsGame);
						}else if(game->mapa.tiles[graphicsGame->xaux][graphicsGame->yaux].edificio!=NULL){
							graphicsGame->bSelected=game->mapa.tiles[graphicsGame->xaux][graphicsGame->yaux].edificio;
							DrawGameGraphics(graphics,game,graphicsGame);
						}
					}
				}
				break;
			case SDL_KEYDOWN:
				if(e.key.keysym.sym == SDLK_ESCAPE){
					FreeGameGraphics(graphicsGame);
					FreeGame(game);
					return true;
				}
				break;
			case SDL_WINDOWEVENT:
				SDL_GetWindowPosition(graphics->win,&graphics->winx,&graphics->winy);
				SDL_GetWindowSize(graphics->win, &graphics->width,&graphics->height);
				graphicsGame->numx=graphics->width/(graphicsGame->rect.w*3/2)+5;
				graphicsGame->numy=graphics->height/(graphicsGame->rect.h/2)+5;
				graphicsGame->EndTurn.rect.h = graphics->height/15;
				graphicsGame->EndTurn.rect.w = graphics->width/15;
				graphicsGame->EndTurn.rect.x = graphics->width*0.85-graphics->winx;
				graphicsGame->EndTurn.rect.y = graphics->height*0.85-graphics->winy;
				DrawGameGraphics(graphics,game,graphicsGame);
				break;
			default:
				break;	
		}
	}
	return false;
}

void updateUIResources(Graphics* graphics,Juego* game,gameGraphics* graphicsGame){
	SDL_Rect rect;
	char text[1024];
	rect.h = graphics->height/16;
	rect.w = graphics->width/3;
	rect.x = graphics->width/20;
	rect.y = 10;
	sprintf(text,"f: %d  w: %d  o: %d  s: %d",game->players[game->turno].resources[FOOD],game->players[game->turno].resources[WOOD],game->players[game->turno].resources[METAL],game->players[game->turno].resources[ROCK]);
	FreeUIResources(&graphicsGame->uiResources);
	graphicsGame->uiResources = newUIResources(graphics->renderer,rect,text);
}

void updateGameGraphics(Graphics* graphics,Juego* game,gameGraphics* graphicsGame){
	bool change=false;
	if(graphics->width*0.15>graphics->xMouse-graphics->winx && graphicsGame->posx>0 ){
		graphicsGame->posx-=3;
		change=true;
	}
	else if(graphics->width-graphics->width*0.15<graphics->xMouse-graphics->winx && 
		graphicsGame->posx < game->mapa.sizex*graphicsGame->rect.w*3/2-graphics->width +graphicsGame->rect.w/4 &&
		graphicsGame->numx<game->mapa.sizex + 5){
		graphicsGame->posx+=3;
		change=true;
	}
	if(graphics->height*0.15>graphics->yMouse-graphics->winy && graphicsGame->posy>0){
		graphicsGame->posy-=3;
		change=true;
	}
	else if(graphics->height-graphics->height*0.15<graphics->yMouse-graphics->winy &&
		graphicsGame->posy < game->mapa.sizey*graphicsGame->rect.h/2-graphics->height+graphicsGame->rect.h/2 &&
		graphicsGame->numy<game->mapa.sizey){
		graphicsGame->posy+=3;
		change=true;
	}
	if(change){
		DrawGameGraphics(graphics,game,graphicsGame);
	}
}

void DrawGameGraphics(Graphics* graphics,Juego* game,gameGraphics* graphicsGame){
	SDL_SetRenderTarget(graphics->renderer, graphicsGame->Tmap);
	SDL_RenderClear(graphics->renderer);
	for(int i=0;i<graphicsGame->numy;i++){
		for(int j=0;j<graphicsGame->numx;j++){
			graphicsGame->offsetx=j+graphicsGame->posx/(graphicsGame->rect.w*3/2)-1;
			graphicsGame->offsety=i+graphicsGame->posy/(graphicsGame->rect.h/2)-1;
			graphicsGame->rect.y=graphicsGame->offsety*(graphicsGame->rect.h/2)-graphicsGame->posy;
			graphicsGame->rect.x=graphicsGame->offsetx*(graphicsGame->rect.w*3/2)-graphicsGame->posx;
			if(graphicsGame->offsety%2!=0){
				graphicsGame->rect.x+=(graphicsGame->rect.w*3/4);
			}
			if(!InsideMap(game->mapa,graphicsGame->offsetx,graphicsGame->offsety)){
				SDL_RenderCopy(graphics->renderer, graphicsGame->terrain[Blank], NULL, &graphicsGame->rect);
			}
			else{
				if(game->players[game->turno].mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].vision==0){
					SDL_RenderCopy(graphics->renderer, graphicsGame->invisible, NULL, &graphicsGame->rect);
				}else{
					SDL_RenderCopy(graphics->renderer,graphicsGame->terrain[game->mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].terrain],NULL, &graphicsGame->rect);
					if(game->players[game->turno].mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].vision==1
						&&game->mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].unidad!=NULL){
						DrawUnitGraphics(graphics,game->mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].unidad,&graphicsGame->rect);
					}
				}
				if(game->mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].movement==1){
					SDL_RenderCopy(graphics->renderer, graphicsGame->selected[2], NULL, &graphicsGame->rect);
				}
				if(game->mapa.tiles[graphicsGame->offsetx][graphicsGame->offsety].attack==1){
					SDL_RenderCopy(graphics->renderer, graphicsGame->selected[0], NULL, &graphicsGame->rect);
				}
			}
		}
	}
	if(graphicsGame->uiInfo.target != NULL && !graphicsGame->showInfo){
		SDL_RenderCopy(graphics->renderer,graphicsGame->uiInfo.target,NULL,&graphicsGame->uiInfo.rect);
	}
	if(graphicsGame->uiResources.target != NULL){
		SDL_RenderCopy(graphics->renderer,graphicsGame->uiResources.target,NULL,&graphicsGame->uiResources.rect);
	}
	DrawButton(graphics,graphicsGame->EndTurn);
	SDL_SetRenderTarget(graphics->renderer, NULL);
	SDL_RenderCopy(graphics->renderer,graphicsGame->Tmap,NULL,NULL);
}

void FreeGameGraphics(gameGraphics* graphics){
	for(int i=0;i<7;i++){
		SDL_DestroyTexture(graphics->terrain[i]);
	}
	SDL_DestroyTexture(graphics->selected[0]);
	SDL_DestroyTexture(graphics->selected[1]);
	SDL_DestroyTexture(graphics->selected[2]);
	SDL_DestroyTexture(graphics->invisible);
	SDL_DestroyTexture(graphics->Tmap);
	FreeButton(&graphics->EndTurn);
	FreeUIInfo(&graphics->uiInfo);
	FreeUIResources(&graphics->uiResources);
}

#endif
