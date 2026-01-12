//Ivan Alejandro Rodriguez Ruiz 08/Octubre/2020
//Last modified 05/Marzo/2021
#ifndef MOVEMENT_C
#define MOVEMENT_C

#include <stdbool.h>
#include "map.h"
#include "movement.h"
#include "Graphics/unitGraphics.h"

void PossibleMovement(Map *mapa,unitGraphics* unidad,int x,int y,int n){
	if(mapa->tiles[x][y].terrain==6||n<=0||
		(mapa->tiles[x][y].unidad!=NULL && mapa->tiles[x][y].unidad!=unidad)){
		return;
	}
	mapa->tiles[x][y].movement=1;
	
	if(y-1>=0){
		if(mapa->tiles[x][y-1].terrain!=1){
			PossibleMovement(mapa,unidad,x,y-1,n-2);
		}else{
			PossibleMovement(mapa,unidad,x,y-1,n-1);
		}
		
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y-1].terrain!=1){
				PossibleMovement(mapa,unidad,x+1,y-1,n-2);
			}else{
				PossibleMovement(mapa,unidad,x+1,y-1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y-1].terrain!=1){
					PossibleMovement(mapa,unidad,x-1,y-1,n-2);
				}else{
					PossibleMovement(mapa,unidad,x-1,y-1,n-1);
				}
			}
		}
	}
	if(y+1<mapa->sizey){
		if(mapa->tiles[x][y+1].terrain!=1){
			PossibleMovement(mapa,unidad,x,y+1,n-2);
		}else{
			PossibleMovement(mapa,unidad,x,y+1,n-1);
		}
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y+1].terrain!=1){
				PossibleMovement(mapa,unidad,x+1,y+1,n-2);
			}else{
				PossibleMovement(mapa,unidad,x+1,y+1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y+1].terrain!=1){
					PossibleMovement(mapa,unidad,x-1,y+1,n-2);
				}else{
					PossibleMovement(mapa,unidad,x-1,y+1,n-1);
				}
			}
		}
	}

	if(y-2>=0){
		if(mapa->tiles[x][y-2].terrain!=1){
			PossibleMovement(mapa,unidad,x,y-2,n-2);
		}else{
			PossibleMovement(mapa,unidad,x,y-2,n-1);
		}
	}
	
	if(y+2<mapa->sizey){
		if(mapa->tiles[x][y+2].terrain!=1){
			PossibleMovement(mapa,unidad,x,y+2,n-2);
		}else{
			PossibleMovement(mapa,unidad,x,y+2,n-1);
		}
	}
}

void CancelMovement(Map *mapa,unitGraphics* unidad,int x,int y,int n){
	if(mapa->tiles[x][y].terrain==6||n<=0||
		(mapa->tiles[x][y].unidad!=NULL && mapa->tiles[x][y].unidad!=unidad)){
		return;
	}
	mapa->tiles[x][y].movement=0;
	
	if(y-1>=0){
		if(mapa->tiles[x][y-1].terrain!=1){
			CancelMovement(mapa,unidad,x,y-1,n-2);
		}else{
			CancelMovement(mapa,unidad,x,y-1,n-1);
		}
		
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y-1].terrain!=1){
				CancelMovement(mapa,unidad,x+1,y-1,n-2);
			}else{
				CancelMovement(mapa,unidad,x+1,y-1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y-1].terrain!=1){
					CancelMovement(mapa,unidad,x-1,y-1,n-2);
				}else{
					CancelMovement(mapa,unidad,x-1,y-1,n-1);
				}
			}
		}
	}
	if(y+1<mapa->sizey){
		if(mapa->tiles[x][y+1].terrain!=1){
			CancelMovement(mapa,unidad,x,y+1,n-2);
		}else{
			CancelMovement(mapa,unidad,x,y+1,n-1);
		}
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y+1].terrain!=1){
				CancelMovement(mapa,unidad,x+1,y+1,n-2);
			}else{
				CancelMovement(mapa,unidad,x+1,y+1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y+1].terrain!=1){
					CancelMovement(mapa,unidad,x-1,y+1,n-2);
				}else{
					CancelMovement(mapa,unidad,x-1,y+1,n-1);
				}
			}
		}
	}

	if(y-2>=0){
		if(mapa->tiles[x][y-2].terrain!=1){
			CancelMovement(mapa,unidad,x,y-2,n-2);
		}else{
			CancelMovement(mapa,unidad,x,y-2,n-1);
		}
	}
	
	if(y+2<mapa->sizey){
		if(mapa->tiles[x][y+2].terrain!=1){
			CancelMovement(mapa,unidad,x,y+2,n-2);
		}else{
			CancelMovement(mapa,unidad,x,y+2,n-1);
		}
	}
}

bool Move(Map *mapa,unitGraphics *unidad,int xsource,int ysource,int xdestino,int ydestino){
	if(unidad!=NULL&&mapa->tiles[xdestino][ydestino].movement!=0&&!(unidad->x==xdestino&&unidad->y==ydestino)){
		unidad->x=xdestino;
		unidad->y=ydestino;
		mapa->tiles[xsource][ysource].unidad = NULL;
		mapa->tiles[xdestino][ydestino].unidad = unidad;
		return 1;
	}
	return 0;
}

#endif
