//Ivan Alejandro Rodriguez Ruiz 02/01/2020
#ifndef GAME_C
#define GAME_C

#include "game.h"
#include "Graphics/unitGraphics.h"

Juego NewGame(unsigned int x,unsigned int y,unsigned int n){
	Juego game;
	game.mapa = CreateRandomMap(x,y);
	game.turno=0;
	if (n<=1){game.n=2;}else{game.n = n;}
	
	game.players = (Player*)calloc(game.n,sizeof(Player));
	for(int i=0;i<game.n;i++){
		game.players[i] = CreatePlayer(x,y);
	}
	return game;
}

bool ChangeTurn(Juego *game){
	game->turno++;
	if(game->turno>=game->n)game->turno=0;
	UpdateVision(game);
	return true;
}

bool SetUnit(Juego* game,unitGraphics* unidad,unsigned int x,unsigned int y){
	if(game->mapa.tiles[x][y].unidad!=NULL){return false;}
	game->mapa.tiles[x][y].unidad=unidad;
	unidad->x=x;
	unidad->y=y;
	return true;
}

void ResetActions(Juego* game){
	ListaU *unidades = game->players[game->turno].unidades;
	while(unidades!=NULL){
		unidades->unidad.unit.attack = 1;
		unidades->unidad.unit.move = 1;
		unidades = unidades->siguiente;
	}
}

void FreeGame(Juego *game){
	FreeMap(&game->mapa);
	for(int i=0;i<game->n;i++){
		FreePlayer(&game->players[i]);
	}
	free(game->players);
}

#endif
