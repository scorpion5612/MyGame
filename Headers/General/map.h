//Ivan Alejandro Rodriguez Ruiz 1/Octubre/2020
#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdbool.h>
#include "Graphics/unitGraphics.h"
#include "building.h"

typedef struct{
	//vision: 0 not visible, 1 visible and 2 explored but not visible
	//movement: 0 not posible, 1 possible
	unsigned int terrain,vision;
	bool movement,attack;
	unitGraphics *unidad;
	Building *edificio;
}Tile;

typedef struct{
	unsigned int sizex,sizey;
	Tile **tiles;
}Map;

Map CreateEmptyMap(unsigned int x,unsigned int y);
Map CreateRandomMap(unsigned int x,unsigned int y);
bool InsideMap(Map mapa,int x,int y);
void FreeMap(Map* mapa);

#endif
