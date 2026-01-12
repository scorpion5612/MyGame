//Ivan Alejandro Rodriguez Ruiz 2/Octubre/2020
#ifndef BUILDING_C
#define BUILDING_C

#include <stdio.h>
#include "building.h"
#include "definitions.h"

Building CreateBuilding(int Attack,int Defence, int Range,int Vision,
			int food,int wood,int rock,int metal,unsigned int specific){
	Building building;
	building.attributes[HPBUILDING]=100;
	building.attributes[ATTBUILDING]=Attack;
	building.attributes[DEFBUILDING]=Defence;
	building.attributes[RANGEBUILDING]=Range;
	building.attributes[VISIONBUILDING]=Vision;
	building.resources[FOOD]=food;
	building.resources[WOOD]=wood;
	building.resources[ROCK]=rock;
	building.resources[METAL]=metal;
	building.specific=specific;
	return building;
}

void ShowBuilding(Building building){
	printf("Hp: %d\n",building.attributes[HPBUILDING]);
	printf("Attack: %d\n",building.attributes[ATTBUILDING]);
	printf("Defence: %d\n",building.attributes[DEFBUILDING]);
	printf("Range: %d\n",building.attributes[RANGEBUILDING]);
	printf("Vision: %d\n",building.attributes[VISIONBUILDING]);
	printf("Food: %d\n",building.resources[FOOD]);
	printf("Wood: %d\n",building.resources[WOOD]);
	printf("Rock: %d\n",building.resources[ROCK]);
	printf("Metal: %d\n",building.resources[METAL]);
}

#endif
