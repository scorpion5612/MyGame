//Ivan Alejandro Rodriguez Ruiz 06/Octubre/2020
#ifndef COMBAT_C
#define COMBAT_C

#include "player.h"
#include "unit.h"
#include "building.h"
#include "combat.h"
#include "definitions.h"

float AttackUnitXUnit(Unit attacker,Unit defender){
	float damage,defense;
	if(defender.attributes[HP]<10){
		damage=((attacker.attributes[HP]/10)+1)*attacker.attributes[ATT]+1;
	}else{
		damage=(((attacker.attributes[HP]/10)+1)*attacker.attributes[ATT]+1)/((defender.attributes[HP]/10)+1);
	}
	
	if(attacker.attributes[RANGE]==1){
		defense=defender.attributes[MELEEDEF]+1;
	}else{
		defense=defender.attributes[RANGEDEF]+1;
	}
	damage/=(defense/7000);
	damage+=attacker.attributes[ATT];

	if(attacker.type==defender.weakness){
		damage*=2;
	}
	if(attacker.type==defender.resistance){
		damage/=2;
	}
	return damage/170;
}

float AttackBuildingXUnit(Building attacker,Unit defender){
	float damage,defense;
	defense=defender.attributes[RANGEDEF]+1;
	damage=attacker.attributes[ATTBUILDING];
	damage/=(defense/7000);
	damage+=attacker.attributes[ATTBUILDING];
	return damage/170;
}

float AttackUnitXBuilding(Unit attacker,Building defender){
	float damage;
	damage=attacker.attributes[ATT]*7;
	damage/=(defender.attributes[DEFBUILDING]+1);
	damage+=attacker.attributes[ATT];
	return damage*2;
}

float AttackBuildingXBuilding(Building attacker,Building defender){
	float damage;
	damage=attacker.attributes[ATTBUILDING]*7;
	damage/=(defender.attributes[DEFBUILDING]+1);
	damage+=attacker.attributes[ATTBUILDING];
	return damage*2;
}

void PossibleAttack(Player *player,Map *mapa,unitGraphics* unidad,int x,int y,int n){
	if(mapa->tiles[x][y].terrain==6||n<=0||mapa->tiles[x][y].terrain==0){
		return;
	}
	if(mapa->tiles[x][y].unidad!=NULL&&mapa->tiles[x][y].unidad!=unidad&&!CheckUnidad(player,&mapa->tiles[x][y].unidad->unit))mapa->tiles[x][y].attack=1;
	
	if(y-1>=0){
		if(mapa->tiles[x][y-1].terrain!=1){
			PossibleAttack(player,mapa,unidad,x,y-1,n-2);
		}else{
			PossibleAttack(player,mapa,unidad,x,y-1,n-1);
		}
		
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y-1].terrain!=1){
				PossibleAttack(player,mapa,unidad,x+1,y-1,n-2);
			}else{
				PossibleAttack(player,mapa,unidad,x+1,y-1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y-1].terrain!=1){
					PossibleAttack(player,mapa,unidad,x-1,y-1,n-2);
				}else{
					PossibleAttack(player,mapa,unidad,x-1,y-1,n-1);
				}
			}
		}
	}

	if(y+1<mapa->sizey){
		if(mapa->tiles[x][y+1].terrain!=1){
			PossibleAttack(player,mapa,unidad,x,y+1,n-2);
		}else{
			PossibleAttack(player,mapa,unidad,x,y+1,n-1);
		}

		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y+1].terrain!=1){
				PossibleAttack(player,mapa,unidad,x+1,y+1,n-2);
			}else{
				PossibleAttack(player,mapa,unidad,x+1,y+1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y+1].terrain!=1){
					PossibleAttack(player,mapa,unidad,x-1,y+1,n-2);
				}else{
					PossibleAttack(player,mapa,unidad,x-1,y+1,n-1);
				}
			}
		}
	}

	if(y-2>=0){
		if(mapa->tiles[x][y-2].terrain!=1){
			PossibleAttack(player,mapa,unidad,x,y-2,n-2);
		}else{
			PossibleAttack(player,mapa,unidad,x,y-2,n-1);
		}
	}
	
	if(y+2<mapa->sizey){
		if(mapa->tiles[x][y+2].terrain!=1){
			PossibleAttack(player,mapa,unidad,x,y+2,n-2);
		}else{
			PossibleAttack(player,mapa,unidad,x,y+2,n-1);
		}
	}
}

void CancelAttack(Map *mapa,unitGraphics* unidad,int x,int y,int n){
	if(mapa->tiles[x][y].terrain==6||n<=0||mapa->tiles[x][y].terrain==0){
		return;
	}
	mapa->tiles[x][y].attack=0;
	
	if(y-1>=0){
		if(mapa->tiles[x][y-1].terrain!=1){
			CancelAttack(mapa,unidad,x,y-1,n-2);
		}else{
			CancelAttack(mapa,unidad,x,y-1,n-1);
		}
		
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y-1].terrain!=1){
				CancelAttack(mapa,unidad,x+1,y-1,n-2);
			}else{
				CancelAttack(mapa,unidad,x+1,y-1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y-1].terrain!=1){
					CancelAttack(mapa,unidad,x-1,y-1,n-2);
				}else{
					CancelAttack(mapa,unidad,x-1,y-1,n-1);
				}
			}
		}
	}

	if(y+1<mapa->sizey){
		if(mapa->tiles[x][y+1].terrain!=1){
			CancelAttack(mapa,unidad,x,y+1,n-2);
		}else{
			CancelAttack(mapa,unidad,x,y+1,n-1);
		}
		if(y%2==1&&x+1<mapa->sizex){
			if(mapa->tiles[x+1][y+1].terrain!=1){
				CancelAttack(mapa,unidad,x+1,y+1,n-2);
			}else{
				CancelAttack(mapa,unidad,x+1,y+1,n-1);
			}
		}else{
			if(x-1>=0){
				if(mapa->tiles[x-1][y+1].terrain!=1){
					CancelAttack(mapa,unidad,x-1,y+1,n-2);
				}else{
					CancelAttack(mapa,unidad,x-1,y+1,n-1);
				}
			}
		}
	}

	if(y-2>=0){
		if(mapa->tiles[x][y-2].terrain!=1){
			CancelAttack(mapa,unidad,x,y-2,n-2);
		}else{
			CancelAttack(mapa,unidad,x,y-2,n-1);
		}
	}
	
	if(y+2<mapa->sizey){
		if(mapa->tiles[x][y+2].terrain!=1){
			CancelAttack(mapa,unidad,x,y+2,n-2);
		}else{
			CancelAttack(mapa,unidad,x,y+2,n-1);
		}
	}
}

bool Attack(Map *mapa,int xsource,int ysource,int xdestino,int ydestino){
	if(mapa->tiles[xsource][ysource].unidad!=NULL&&mapa->tiles[xdestino][ydestino].unidad!=NULL&&mapa->tiles[xdestino][ydestino].attack!=0){
		mapa->tiles[xdestino][ydestino].unidad->unit.attributes[HP] -= AttackUnitXUnit(mapa->tiles[xsource][ysource].unidad->unit,mapa->tiles[xdestino][ydestino].unidad->unit);
		return 1;
	}
	return 0;
}

#endif
