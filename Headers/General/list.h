//Ivan Alejandro Rodriguez Ruiz 02/01/2020
#ifndef LISTA_H
#define LISTA_H

#include "Graphics/unitGraphics.h"
#include "building.h"
#include "player.h"

typedef struct NodoU{
	unitGraphics unidad;
	struct NodoU *siguiente;
}ListaU;

typedef struct NodoE{
	Building edificio;
	struct NodoE *siguiente;
}ListaE;

ListaU* AgregarUnidad(ListaU* lista,unitGraphics unidad);
ListaE* AgregarEdificio(ListaE* lista,Building edificio);

void FreeUnidades(ListaU* lista);
void FreeEdificios(ListaE* lista);

#endif
