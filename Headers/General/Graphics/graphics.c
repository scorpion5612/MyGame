//Ivan Alejandro Rodriguez Ruiz 08/Octubre/2020
//Last modified 05/Marzo/2021
#ifndef GRAPHICS_C
#define GRAPHICS_C

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include "unitGraphics.h"
#include "../game.h"
#include "button.h"
#include "graphics.h"
#include "gameGraphics.h"
#include "../definitions.h"

bool Start(){
	Graphics graphics;
	SDL_DisplayMode displayMode;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_GetCurrentDisplayMode(0,&displayMode);
	graphics.win = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w, displayMode.h, 0);
	graphics.renderer = SDL_CreateRenderer(graphics.win, -1, SDL_RENDERER_ACCELERATED);
	SDL_GetGlobalMouseState(&graphics.xMouse,&graphics.yMouse);
	SDL_GetWindowPosition(graphics.win,&graphics.winx,&graphics.winy);
	SDL_GetWindowSize(graphics.win, &graphics.width,&graphics.height);
	Menu(&graphics);
	SDL_DestroyRenderer(graphics.renderer);
	SDL_DestroyWindow(graphics.win);
	TTF_Quit();
	SDL_Quit();
}

bool Menu(Graphics *graphics){
	Button play,exit;
	SDL_Rect rect;
	rect.w=140;
	rect.h=70;
	rect.x=(graphics->width-rect.w)/2;
	rect.y=(graphics->height-rect.h)/2-20;

	play = newButton(graphics->renderer,rect,"Play");
	rect.y+=rect.h+20;
	exit = newButton(graphics->renderer,rect,"Exit");
	while (1) {
		SDL_Event e;
		//eventos del menu
		while (SDL_PollEvent(&e)!=0) {
			switch(e.type){
				case SDL_QUIT:
					FreeButton(&play);
					FreeButton(&exit);
					return true;
				case SDL_MOUSEMOTION:
					SDL_GetGlobalMouseState(&graphics->xMouse,&graphics->yMouse);
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(!SDL_BUTTON(SDL_BUTTON_LEFT))break;
					if(inside(graphics,&play.rect)){
						FreeButton(&play);
						FreeButton(&exit);
						Game(graphics);
						return true;
					}else if(inside(graphics,&exit.rect)){
						FreeButton(&play);
						FreeButton(&exit);
						return true;
					}
					break;
				case SDL_WINDOWEVENT:
					SDL_GetWindowPosition(graphics->win,&graphics->winx,&graphics->winy);
					SDL_GetWindowSize(graphics->win, &graphics->width,&graphics->height);
					break;
				default:
					break;	
			}
		}
		SDL_RenderClear(graphics->renderer);
		DrawButton(graphics,play);
		DrawButton(graphics,exit);
		SDL_RenderPresent(graphics->renderer);
		SDL_Delay(1);
	}
}

bool Game(Graphics *graphics){
	gameGraphics graphicsGame;
	Juego game;
	ListaU *aux;
	
	game = NewGame(20,40,2);
	game.players[0].unidades = AgregarUnidad(game.players[0].unidades,newUnitGraphics(graphics,CreateUnit(10,5,1,1,2,3,1,1,1,1)));
	SetUnit(&game,&game.players[0].unidades->unidad,5,5);
	game.players[0].unidades = AgregarUnidad(game.players[0].unidades,newUnitGraphics(graphics,CreateUnit(10,5,1,1,2,3,1,1,1,1)));
	SetUnit(&game,&game.players[0].unidades->unidad,5,6);
	game.mapa.tiles[5][5].terrain = Plains;
	game.mapa.tiles[5][6].terrain = Plains;
	UpdateVision(&game);
	
	game.players[1].unidades = AgregarUnidad(game.players[1].unidades,newUnitGraphics(graphics,CreateUnit(7,5,1,1,2,3,1,1,1,1)));
	SetUnit(&game,&game.players[1].unidades->unidad,5,7);
	game.mapa.tiles[5][7].terrain = Plains;

	graphicsGame = newGameGraphics(graphics);
	graphicsGame.EndTurn.rect.h = graphics->height/15;
	graphicsGame.EndTurn.rect.w = graphics->width/15;
	graphicsGame.EndTurn.rect.x = graphics->width*0.85-graphics->winx;
	graphicsGame.EndTurn.rect.y = graphics->height*0.85-graphics->winy;

	graphicsGame.numx=graphics->width/(graphicsGame.rect.w*3/2)+5;
	graphicsGame.numy=graphics->height/(graphicsGame.rect.h/2)+5;

	updateUIResources(graphics,&game,&graphicsGame);
	DrawGameGraphics(graphics,&game,&graphicsGame);

	while (1) {
		//eventos del juego
		if(eventosGameGraphics(graphics,&game,&graphicsGame)){return true;}
		
		//otras acciones
		updateGameGraphics(graphics,&game,&graphicsGame);
		
		//dibujar en pantalla
		SDL_RenderClear(graphics->renderer);
		SDL_RenderCopy(graphics->renderer,graphicsGame.Tmap,NULL,NULL);
		SDL_RenderPresent(graphics->renderer);
		
		SDL_Delay(1);
	}
}

bool inside(Graphics *graphics,SDL_Rect *rect){
	if(graphics->xMouse>=rect->x+graphics->winx && graphics->xMouse<=rect->x+graphics->winx+rect->w &&
		graphics->yMouse>=rect->y+graphics->winy && graphics->yMouse<=rect->y+graphics->winy+rect->h){
		return true;
	}
	return false;
}

#endif
