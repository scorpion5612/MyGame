//Ivan Alejandro Rodriguez Ruiz 01/01/2020
#ifndef JUGADOR_H
#define JUGADOR_H

#include "map.h"
#include "list.h"

typedef struct{
	//mapa de lo que ve el jugador
	Map mapa;
	//Unidades del jugador
	struct NodoU *unidades;
	//edificios del jugador
	struct NodoE *edificios;
	//Resources del jugador
	int resources[4];
}Player;

Player CreatePlayer(unsigned int x,unsigned int y);
bool CheckUnidad(Player *player,Unit *unidad);
void FreePlayer(Player* player);

#endif
