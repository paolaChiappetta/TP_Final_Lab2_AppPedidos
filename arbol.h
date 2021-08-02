#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "producto.h"

#define arProductos "productos.dat"

typedef struct
{
    stProducto p;
    struct nodoArbolstProducto * izq;
    struct nodoArbolstProducto * der;
} nodoArbolstProducto;


nodoArbolstProducto * inicArbol();
nodoArbolstProducto * crearNodoArbol(stProducto dato);
stProducto cargaUnProducto(nodoArbolstProducto* arbol, char nombre []);
nodoArbolstProducto* subprogramaModificaUnProductoPorId (nodoArbolstProducto* arbol) ;
int  buscarUltimoIdArbol (nodoArbolstProducto * a);
nodoArbolstProducto *nodoMasDerecha(nodoArbolstProducto *arbol);
void preOrden (nodoArbolstProducto * a);
void recorrerInOrder (nodoArbolstProducto* arbol) ;
void postOrden (nodoArbolstProducto * a);
void mostrarUnNodo (nodoArbolstProducto* arbol);
nodoArbolstProducto* modificarRegistroProducto(nodoArbolstProducto* arbol, int IdProducto);
void recorrerInOrderFiltro (nodoArbolstProducto* arbol) ;
nodoArbolstProducto* subprogramaCargaUnProducto(nodoArbolstProducto* arbol);
nodoArbolstProducto * buscarNodoArbolId (nodoArbolstProducto * a, int idProducto);
nodoArbolstProducto* buscarPreOrderNombreProducto (nodoArbolstProducto* arbol, char nombre[]) ;
nodoArbolstProducto * insertaOrdenadoArbolCreandoNodo(nodoArbolstProducto * a, stProducto dato);
nodoArbolstProducto * insertaOrdenadoArbol(nodoArbolstProducto * a, nodoArbolstProducto* datoNodo);
stProducto buscarEstructuraProductoEnArbolId (nodoArbolstProducto * a, int idProducto);
nodoArbolstProducto* archivo2Arbol (char archivo [], nodoArbolstProducto* arbol);
void arbol2Archivo (nodoArbolstProducto * arbol );
void guardaArbolRecursivo (FILE * pArch, nodoArbolstProducto* arbol);
nodoArbolstProducto *nodoMasIzquierda(nodoArbolstProducto *arbol);
nodoArbolstProducto* darDeBajaProducto(nodoArbolstProducto* arbol, int idProducto);
nodoArbolstProducto* darDeAltaProducto(nodoArbolstProducto* arbol, int idProducto);
int esHoja (nodoArbolstProducto* arbol);
nodoArbolstProducto* borrarArbol (nodoArbolstProducto* arbol);














#endif // ARBOL_H_INCLUDED
