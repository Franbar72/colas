#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMA_LONGITUD_CADENA 1000

struct NodoDeLista
{
	char nombre[MAXIMA_LONGITUD_CADENA];
	// Aquí podrían ir más datos...
	struct NodoDeLista *siguiente;
};

void agregarNodoALista(struct NodoDeLista **nodo, char *nombre)
{
	struct NodoDeLista *nuevoNodo = malloc(sizeof(struct NodoDeLista));
	strcpy(nuevoNodo->nombre, nombre);
	nuevoNodo->siguiente = NULL;
	if ((*nodo) == NULL)
	{
		*nodo = nuevoNodo;
	}
	else
	{
		agregarNodoALista(&(*nodo)->siguiente, nombre);
	}
}

void imprimirLista(struct NodoDeLista *nodo)
{
	while (nodo != NULL)
	{
		printf("Encontramos un nombre en la lista: '%s'\n", nodo->nombre);
		nodo = nodo->siguiente;
	}
}

int main()
{

	struct NodoDeLista *apuntadorLista = NULL;
	agregarNodoALista(&apuntadorLista, "Francisco");
	agregarNodoALista(&apuntadorLista, "FJBY");
	agregarNodoALista(&apuntadorLista, "casa72");
	agregarNodoALista(&apuntadorLista, "franbar72");
	imprimirLista(apuntadorLista);
}