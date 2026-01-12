#ifndef DEFINITIONS
#define DEFINITIONS

enum ATTRIBUTESUNIT{
	HP = 0,
	ATT = 1,
	MELEEDEF = 2,
	RANGEDEF = 3,
	RANGE = 4,
	MOVEMENT = 5,
	VISION = 6
};

enum ATTRIBUTESBUILDING{
	HPBUILDING = 0,
	ATTBUILDING = 1,
	DEFBUILDING = 2,
	RANGEBUILDING = 3,
	VISIONBUILDING = 4
};

enum RESOURCESBUILDING{
	FOOD = 0,
	WOOD = 1,
	ROCK = 2,
	METAL = 3
};

enum Types{
	Infantry = 0,
	Cavalry = 1,
	Archer = 2,
	Demolition = 3
};

enum TerrainTypes{
	Blank = 0,
	Plains = 1,
	Forest = 2,
	Bushes = 3,
	Stone = 4,
	Ore = 5,
	Precipicio = 6
};

#endif