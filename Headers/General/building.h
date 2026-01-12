//Ivan Alejandro Rodriguez Ruiz 2/Octubre/2020
#ifndef BUILDING_H
#define BUILDING_H

typedef struct{
	//HP,Attack,Defence,Range, vision
	//HP max 100
	//Resources Production
	int attributes[5],resources[4];
	unsigned int specific; //tipo especifico del edificio
	unsigned int x,y; //coordinadas
}Building;

Building CreateBuilding(int Attack,int Defence,int Range,int Vision,int food,int wood,int rock,int metal,unsigned int specific);
void ShowBuilding(Building building);

#endif
