//Ivan Alejandro Rodriguez Ruiz 02/01/2020
#ifndef JUGADOR_C
#define JUGADOR_C

#include "player.h"
#include "definitions.h"

Player CreatePlayer(unsigned int x,unsigned int y){
	Player player;
	player.mapa = CreateEmptyMap(x,y);
	player.unidades = NULL;
	player.edificios = NULL;
	player.resources[FOOD] = 100;
	player.resources[WOOD] = 100;
	player.resources[METAL] = 50;
	player.resources[ROCK] = 50;
	return player;
}

bool CheckUnidad(Player *player,Unit *unidad){
	ListaU* aux = player->unidades;
	while(aux!=NULL){
		if(unidad==&aux->unidad.unit)return 1;
		aux = aux->siguiente;
	}
	return 0;
}

void FreePlayer(Player *player){
	FreeMap(&player->mapa);
	FreeUnidades(player->unidades);
	FreeEdificios(player->edificios);
}

#endif
