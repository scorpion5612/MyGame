//Ivan Alejandro Rodriguez Ruiz 06/Octubre/2020
#ifndef COMBAT_H
#define COMBAT_H

#include "map.h"
#include "unit.h"
#include "building.h"

float AttackUnitXUnit(Unit attacker,Unit defender);
float AttackBuildingXUnit(Building attacker,Unit defender);
float AttackUnitXBuilding(Unit attacker,Building defender);
float AttackBuildingXBuilding(Building attacker,Building defender);
void PossibleAttack(Player* player,Map* mapa,unitGraphics* unidad,int x,int y,int n);
void CancelAttack(Map* mapa,unitGraphics* unidad,int x,int y,int n);
bool Attack(Map* mapa,int xsource,int ysource,int xdestino,int ydestino);

#endif
