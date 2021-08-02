#ifndef LISTACELDA_H_INCLUDED
#define LISTACELDA_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "colores.h"
#include "cliente.h"
#include"producto.h"

typedef struct
{
    stProducto p;
    struct nodoListaProducto * siguiente;
} nodoListaProducto;

typedef struct
{
    stCliente cliente;
    struct nodoListaProducto * listaDeProductos;
    struct stCelda * siguiente;
    float totalConsumido;
} stCelda;


stCelda* inicListaCelda();
stCelda* crearNodoCelda(stCliente dato);
stCelda* agregarAlPrincipioCelda(stCelda* lista, stCelda* nuevoNodo);
void muestraNodoCelda(stCelda *stCelda);
void muestraListaCelda(stCelda* lista);
stCelda* buscarUltimoCelda(stCelda* lista);
stCelda* agregarAlFinalCelda(stCelda* lista, stCelda* nuevo);
int verificarClienteExistenteEnCelda (stCelda * lista, int dni);
stCelda  * buscarCeldaPorID (stCelda * lista, int id);
stCelda * borrarNodoCeldaCliente(stCelda * lista, int id);
void muestraListaCeldaSiHayPedidos(stCelda * lista);



#endif // LISTACELDA_H_INCLUDED
