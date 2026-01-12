//Ivan Alejandro Rodriguez Ruiz 1/Octubre/2020
#ifndef MAP_C
#define MAP_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graphics/unitGraphics.h"
#include "building.h"
#include "map.h"

Map CreateEmptyMap(unsigned int x,unsigned int y){
	Map mapa;
	mapa.sizex=x;
	mapa.sizey=y;

	mapa.tiles=(Tile**)calloc(x,sizeof(Tile*));
	for(int i=0;i<x;i++){
		mapa.tiles[i]=(Tile*)calloc(y,sizeof(Tile));
	}

	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			mapa.tiles[i][j].unidad=NULL;
			mapa.tiles[i][j].edificio=NULL;
		}
	}

	return mapa;
}

Map CreateRandomMap(unsigned int x,unsigned int y){	
	unsigned int random;	
	Map mapa;
	mapa.sizex=x;
	mapa.sizey=y;

	mapa.tiles=(Tile**)calloc(x,sizeof(Tile*));
	for(int i=0;i<x;i++){
		mapa.tiles[i]=(Tile*)calloc(y,sizeof(Tile));
	}
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			mapa.tiles[i][j].unidad=NULL;
			mapa.tiles[i][j].edificio=NULL;
			random = rand()%100;
			if(random<65){
				mapa.tiles[i][j].terrain=1;
			}
			else if(random<75){
				mapa.tiles[i][j].terrain=2;
			}
			else if(random<85){
				mapa.tiles[i][j].terrain=3;
			}
			else if(random<90){
				mapa.tiles[i][j].terrain=4;
			}
			else if(random<95){
				mapa.tiles[i][j].terrain=5;
			}
			else if(random<100){
				mapa.tiles[i][j].terrain=6;
			}
		}
	}

	return mapa;
}

bool InsideMap(Map mapa,int x,int y){
	if(x>=0&&x<mapa.sizex&&y>=0&&y<mapa.sizey){
		return true;
	}	
	return false;
}

void FreeMap(Map *mapa){
	for(int i=0;i<mapa->sizex;i++){
		free(mapa->tiles[i]);
	}
	free(mapa->tiles);
	return;
}

#endif
