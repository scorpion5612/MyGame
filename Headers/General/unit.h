//Ivan Alejandro Rodriguez Ruiz 1/Octubre/2020
#ifndef UNIT_H
#define UNIT_H

typedef struct{
	//HP,Attack,MeleeDefence,RangedDefence,Range,Movement,Vision
	//HP max 100
	int attributes[7];
	unsigned int type,resistance,weakness,specific; //Specific: unidad especifica
	bool move,attack;
}Unit;

Unit CreateUnit(int Attack,int MeleeDefence,int RangedDefence,int Range,int Movement,int Vision,unsigned int type,unsigned int resistance,unsigned int weakness,unsigned int specific);
char* UnitType(unsigned int type);
void getUnitInfo(char* text,Unit unit);

#endif
