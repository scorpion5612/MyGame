//Ivan Alejandro Rodriguez Ruiz 08/Octubre/2020
//Last modified 05/Marzo/2021
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdbool.h>
#include "map.h"
#include "Graphics/unitGraphics.h"

void PossibleMovement(Map* mapa,unitGraphics* unidad,int x,int y,int n);
void CancelMovement(Map* mapa,unitGraphics* unidad,int x,int y,int n);
bool Move(Map* mapa,unitGraphics* unidad,int xsource,int ysource,int xdestino,int ydestino);

#endif
