#ifndef FILAPEDIDO_H_INCLUDED
#define FILAPEDIDO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "listaProductos.h"

typedef struct
{
    nodoListaProducto* inicio;
    nodoListaProducto* fin;
}Fila;


void inicFila(Fila* fila);
void agregar(Fila* fila, stProducto dato);
stProducto primero(Fila* fila);
stProducto primeroPro(Fila* fila);
stProducto extraer(Fila* fila);
int filaVacia(Fila* fila);
void muestraFila(Fila* fila);
int contarFilaRecursiva (Fila * fila);
float sumaFilaRecursiva (Fila * fila);


#endif // FILAPEDIDO_H_INCLUDED
