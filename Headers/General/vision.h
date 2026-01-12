//Ivan Alejandro Rodriguez Ruiz 07/Octubre/2020
//Last modified 05/Marzo/2021
#ifndef VISION_H
#define VISION_H

#include "map.h"
#include "game.h"

void Vision(Map* mapa,unsigned int x,unsigned int y,unsigned int n);
void VisionColumna(Map* mapa,int x,int y,unsigned int n);
void UpdateVision(Juego* game);

#endif
