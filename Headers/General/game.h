//Ivan Alejandro Rodriguez Ruiz
#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include "Graphics/unitGraphics.h"

typedef struct{
	Map mapa;
	Player *players;
	unsigned int n,turno;
}Juego;

Juego NewGame(unsigned int x,unsigned int y,unsigned int n);
bool ChangeTurn(Juego* game);
bool SetUnit(Juego* game,unitGraphics* unidad,unsigned int x,unsigned int y);
void ResetActions(Juego* game);
void FreeGame(Juego* game);

#endif
