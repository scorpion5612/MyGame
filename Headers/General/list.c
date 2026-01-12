//Ivan Alejandro Rodriguez Ruiz 02/01/2020
#ifndef LISTA_C
#define LISTA_C

#include "Graphics/unitGraphics.h"
#include "building.h"
#include "list.h"

ListaU *AgregarUnidad(ListaU* lista,unitGraphics unidad){
	ListaU *nuevo;
	nuevo=malloc(sizeof(ListaU));
	nuevo->unidad=unidad;
	nuevo->siguiente=lista;
	return nuevo;
}

ListaE* AgregarEdificio(ListaE* lista,Building edificio){
	ListaE *nuevo;
	nuevo=malloc(sizeof(ListaE));
	nuevo->edificio=edificio;
	nuevo->siguiente=lista;
	return nuevo;
}

void FreeUnidades(ListaU* lista){
	ListaU *aux1,*aux2;
	if(lista==NULL){
		return;
	}
	aux1=lista;
	do{
		FreeUnitGraphics(&aux1->unidad);
		aux2=aux1->siguiente;
		free(aux1);
		aux1=aux2;
	}while(aux1!=NULL);
}

void FreeEdificios(ListaE* lista){
	ListaE *aux1,*aux2;
	if(lista==NULL){
		return;
	}
	aux1=lista;
	do{
		aux2=aux1->siguiente;
		free(aux1);
		aux1=aux2;
	}while(aux1!=NULL);
}

#endif
