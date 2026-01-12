//Ivan Alejandro Rodriguez Ruiz 1/Octubre/2020
#ifndef UNIT_C
#define UNIT_C

#include <stdio.h>
#include "unit.h"
#include "definitions.h"

Unit CreateUnit(int Attack,int MeleeDefence,int RangedDefence, int Ranged,
			int Movement,int Vision,unsigned int type,
			unsigned int resistance,unsigned int weakness,
			unsigned int specific){
	Unit unidad;
	unidad.attributes[HP]=100;
	unidad.attributes[ATT]=Attack;
	unidad.attributes[MELEEDEF]=MeleeDefence;
	unidad.attributes[RANGEDEF]=RangedDefence;
	unidad.attributes[RANGE]=Ranged;
	unidad.attributes[MOVEMENT]=Movement;
	unidad.attributes[VISION]=Vision;
	unidad.type=type;
	unidad.resistance=resistance;
	unidad.weakness=weakness;
	unidad.specific=specific;
	unidad.move = 1;
	unidad.attack = 1;
	return unidad;
}

char* UnitType(unsigned int type){
	switch(type){
		case Infantry:
			return "Infantry";
		case Cavalry:
			return "Cavalry";
		case Archer:
			return "Archer";
		case Demolition:
			return "Demolition";
		default:
			return "Unknown";
	}
}

void getUnitInfo(char* text,Unit unit){
	sprintf(text,"Hp:    %d Att:   %d\nM Def: %d  R Def: %d\nRange: %d  Move: %d\nVis: %d  Type: %s\nRes: %s  Weak: %s\0",
		unit.attributes[HP],unit.attributes[ATT],unit.attributes[MELEEDEF],unit.attributes[RANGEDEF],unit.attributes[RANGE],
		unit.attributes[MOVEMENT],unit.attributes[VISION],UnitType(unit.type),UnitType(unit.resistance),UnitType(unit.weakness)
	);
}

#endif
