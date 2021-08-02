#include "listaCelda.h"


stCelda* inicListaCelda()
{
    return NULL;
}

stCelda* crearNodoCelda(stCliente dato)
{
    stCelda* nuevo = (stCelda*) malloc(sizeof(stCelda)); ///se genera el espacio en memoria
    nuevo->cliente = dato; ///le asigna a nuevo-> la estructura persona
    nuevo->totalConsumido=0.0;
    nuevo->listaDeProductos = inicListaProducto();
    nuevo->siguiente = NULL;
    return nuevo;
}

stCelda* agregarAlPrincipioCelda(stCelda* lista, stCelda* nuevoNodo){
    if(lista==NULL) ///si no hay lista, es = nuevo nodo
        {
        lista = nuevoNodo;
    }else
    {
        nuevoNodo->siguiente = lista; ///sino le asigna al siguiente del nuevo nodo la lista
        lista = nuevoNodo; ///y la lista pasa a tener la dir del nuevo nodo
    }
    return lista;
}


void muestraNodoCelda(stCelda* celdaCliente)
{
    Color (BLACK,   WHITE);
    printf("\nCliente\n");
    Color (BLACK,   LMAGENTA);
    muestraUnCliente(celdaCliente->cliente);
    Color (BLACK,   WHITE);
    printf("\nTotal Consumido: ");
    Color (BLACK,   LMAGENTA);
    printf(" %.2f\n", celdaCliente->totalConsumido);


}

void muestraListaCelda(stCelda * lista)
{
    stCelda * seg = lista;

    while(seg)
        {

        muestraNodoCelda(seg);

        recorrerYmostrar(seg->listaDeProductos);

        seg = seg->siguiente;

    }
}



stCelda* buscarUltimoCelda(stCelda* lista)
{
    stCelda * seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente != NULL)
            seg=seg->siguiente;
    }
    return seg;
}


stCelda* agregarAlFinalCelda(stCelda* lista, stCelda* nuevo){
    if(lista==NULL)
        {
        lista = nuevo;
    }else
    {
        stCelda* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

int verificarClienteExistenteEnCelda (stCelda * lista, int dni)
{
    stCelda * seg = lista;
    int flag = 0;

   while(seg)
    {
       if(seg->cliente.dni==dni)
       {
           flag = 1;
       }

       seg=seg->siguiente;
    }
    return flag;
}

//stCliente buscarEstructuraClienteEnListaID (nodoListaCliente * lista, int id)
//{
//    nodoListaCliente * seg = lista;
//    stCliente c;
//
//   while(seg)
//    {
//       if(seg->c.id==id)
//       {
//           c=seg->c;
//       }
//
//       seg=seg->sig;
//    }
//
//    return c;
//}

stCelda  * buscarCeldaPorID (stCelda * lista, int id)
{
    stCelda * seg = lista;
    stCelda * buscado = NULL;

   while(seg)
    {
       if(seg->cliente.id==id)
       {
         buscado=seg;
       }

       seg=seg->siguiente;
    }

    return buscado;
}

stCelda * borrarNodoCeldaCliente(stCelda * lista, int id)
{
    stCelda * seg;
    stCelda * ante;
    if(lista && (lista->cliente.id==id))
        {
        stCelda * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else
    {
        seg = lista;
        while(seg && (lista->cliente.id!=id))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

void muestraListaCeldaSiHayPedidos(stCelda * lista)
{
    stCelda* seg = lista;
    while(seg)
        {
        if(seg->listaDeProductos)
        {

         muestraNodoCelda(seg);

        recorrerYmostrar(seg->listaDeProductos);
        printf("\n***************************************************************************\n");
        }


        seg = seg->siguiente;
    }
}

stCelda * borrarListaCeldaDeClientes (stCelda * lista)
{
    stCelda * proximo;
    stCelda * seg = lista;
    nodoListaProducto * aux;
    while(seg)
        {
        aux = borrarListaDeProductos (seg->listaDeProductos);
        proximo = seg->siguiente;   /// tomo la direccion del siguiente nodo
        free(seg);              /// libero la memoria del nodo actual
        seg = proximo;          /// me muevo al siguiente nodo
    }
    return seg;
}



