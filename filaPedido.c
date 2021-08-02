#include "filaPedido.h"

void inicFila(Fila* fila)
{
    fila->inicio = inicListaProducto();
    fila->fin = inicListaProducto();
}

void agregar(Fila* fila, stProducto dato)
{
    nodoListaProducto * nuevo = crearNodoListaProducto(dato);

    fila->fin = agregarFinal(fila->fin, nuevo);

    if(fila->inicio==NULL)
    {
        fila->inicio = fila->fin;
    }

    fila->fin=nuevo;
}

stProducto primero(Fila* fila)
{
    stProducto p;
    if(fila->inicio)
    {
        p=verPrimerProducto(fila->inicio);
    }

    return p;
}


stProducto extraer(Fila* fila)
{
  stProducto p;
    if(fila->inicio)
    {
       p = verPrimerProducto(fila->inicio);
        fila->inicio = eliminarPrimerNodoListaProducto(fila->inicio);
        if(!fila->inicio)
        {
            fila->fin = inicListaProducto();
        }
    }
    return p;
}

int filaVacia(Fila* fila)
{
    int resp=0;
    if(!fila->inicio)    /// if(fila->inicio == NULL)
    {
        resp=1;
    }
    return resp;
}

void muestraFila(Fila* fila)
{
    recorrerYmostrar(fila->inicio);
}

int contarFilaRecursiva (Fila * fila)
{
    contarRecursivoListaProductos (fila->inicio);
}

float sumaFilaRecursiva (Fila * fila)
{
    sumaListaProductosRecursiva (fila->inicio);
}

