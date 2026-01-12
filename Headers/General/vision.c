//Ivan Alejandro Rodriguez Ruiz 07/Octubre/2020
//Last modified 05/Marzo/2021
#ifndef VISION_C
#define VISION_C

#include "game.h"
#include "map.h"
#include "vision.h"
#include "definitions.h"

void Vision(Map *mapa,unsigned int x,unsigned int y,unsigned int n){	
	int top=y,left=x,rigth=x;
	unsigned int aux=n*2+1;	
	top-=2*n;
	VisionColumna(mapa,x,top,aux);
	while(aux>n+1){
		if(top<0){
			if((top*-1)%2==1){
				rigth++;
			}else{
				left--;
			}
		}else{
			if(top%2==1){
				rigth++;
			}else{
				left--;
			}
		}
		
		aux--;
		top++;		
		VisionColumna(mapa,left,top,aux);
		VisionColumna(mapa,rigth,top,aux);
	}
}

void VisionColumna(Map *mapa,int x,int y,unsigned int n){
	if(x>=0&&x<mapa->sizex){
		for(int i=0;i<n;i++){
			if(y+i*2>=0&&y+i*2<mapa->sizey){
				mapa->tiles[x][y+i*2].vision=1;
			}
		}
	}
}

void UpdateVision(Juego* game){
	ListaU *unidad=NULL;
	ListaE *edificio=NULL;
	for(int i=0;i<game->mapa.sizey;i++){
		for(int j=0;j<game->mapa.sizex;j++){
			if(game->players[game->turno].mapa.tiles[j][i].vision==1){
				game->players[game->turno].mapa.tiles[j][i].vision=2;
			}
		}	
	}
	unidad=game->players[game->turno].unidades;
	while(unidad!=NULL){
		Vision(&game->players[game->turno].mapa,unidad->unidad.x,unidad->unidad.y,unidad->unidad.unit.attributes[VISION]);
		unidad=unidad->siguiente;
	}
	edificio=game->players[game->turno].edificios;
	while(edificio!=NULL){
		Vision(&game->players[game->turno].mapa,edificio->edificio.x,edificio->edificio.y,edificio->edificio.attributes[VISION]);
		edificio=edificio->siguiente;
	}
}

#endif
