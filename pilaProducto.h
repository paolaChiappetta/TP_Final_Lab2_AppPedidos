#ifndef PILAPRODUCTO_H_INCLUDED
#define PILAPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "listaProductos.h"


#define PilaProducto nodoListaProducto*

void inicPila(PilaProducto * p);

int pilaVacia(PilaProducto * p);

void apilar(PilaProducto * p, stProducto dato);

stProducto verPrimerostPersona (PilaProducto * p);

stProducto desapilar(PilaProducto * p);

stProducto tope(PilaProducto * p);

void muestraPila(PilaProducto * p);



#endif // PILAPRODUCTO_H_INCLUDED
