#include "pilaProducto.h"

///TDA PILA

void inicPila(PilaProducto * p)
{
    (*p) = inicListaProducto();
}

int pilaVacia(PilaProducto * p)
{
    int rta=0;

    if ((*p)==NULL)
    {
        rta = 1;
    }
    else
    {
        rta = 0;
    }
    return rta;
}



void apilar(PilaProducto * p, stProducto dato)
{
    (*p)= agregarDatoPpioLista ((*p),dato);
}




stProducto verPrimerostProducto(PilaProducto * p)
{
    stProducto pe;

   pe= (*p)->p;

    return pe;
}

stProducto desapilar(PilaProducto* p)
{
    stProducto pe = verPrimerostProducto(p);
    (*p)=eliminarPrimerNodoListaProducto(*p);
    return pe;
}



stProducto tope(PilaProducto * p)
{
    stProducto pe= verPrimerostProducto(p);

    return pe;
}



void muestraPila (PilaProducto *p)
{
    recorrerYmostrar(*p);
}
