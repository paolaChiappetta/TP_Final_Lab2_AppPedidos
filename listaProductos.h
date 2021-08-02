
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "listaCelda.h"





nodoListaProducto * inicListaProducto();

nodoListaProducto * crearNodoListaProducto (stProducto dato);

nodoListaProducto * agregarPpio (nodoListaProducto * lista, nodoListaProducto * nuevo);

nodoListaProducto * buscarUltimo (nodoListaProducto * lista);

nodoListaProducto * buscarNodoListaProducto(nodoListaProducto * lista, char nombre[20]);

nodoListaProducto * agregarFinal (nodoListaProducto * lista, nodoListaProducto * nuevo);

nodoListaProducto * borrarNodoListaProductoPorId (nodoListaProducto * lista, int id);

nodoListaProducto * agregarEnOrden (nodoListaProducto *lista, nodoListaProducto * nuevo);

nodoListaProducto * borrarTodaLaLista (nodoListaProducto * lista);

nodoListaProducto * eliminarPrimerNodoListaProducto (nodoListaProducto* lista);

nodoListaProducto * desvincularPrimero(nodoListaProducto * * plista);

nodoListaProducto * eliminarUltimoNodoListaProducto (nodoListaProducto * lista);

void mostrarUnNodoListaProducto (nodoListaProducto * nodoDato);

void recorrerYmostrar (nodoListaProducto * lista);

nodoListaProducto * agregarDatoPpioLista(nodoListaProducto * lista, stProducto dato);

nodoListaProducto * agregarDatoOrdenLista(nodoListaProducto * lista, stProducto dato);

nodoListaProducto * borrarNodoListaProductoFiltro (nodoListaProducto * lista, int filtro);

stProducto verPrimerProducto(nodoListaProducto * lista);

int contarRecursivoListaProductos(nodoListaProducto * lista);

float sumaListaProductosRecursiva(nodoListaProducto * lista);

int verificarProductoExistenteEnListaProducto (nodoListaProducto * lista, int id);

nodoListaProducto * borrarListaDeProductos (nodoListaProducto * lista);
