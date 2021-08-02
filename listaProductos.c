
#include "listaProductos.h"



/// INICIALIZAR LISTA

nodoListaProducto * inicListaProducto()
{
    return NULL;
}

///CREAR nodoListaProducto CON DATO stProducto

nodoListaProducto * crearNodoListaProducto (stProducto dato)
{
    nodoListaProducto * aux= (nodoListaProducto *)malloc(sizeof(nodoListaProducto));

    aux->p=dato;

    aux->siguiente=NULL;

    return aux;
}




///AGREGAR UN nodo AL PRINCIPIO

nodoListaProducto * agregarPpio (nodoListaProducto * lista, nodoListaProducto * nuevo)
{
    ///si la lista esta vacia, ahora apunta al nuevo nodoListaProducto
    if(lista==NULL)
    {
        lista= nuevo;

    }
    else ///si la lista no está vacia, inserta al comienzo
    {
        nuevo-> siguiente= lista;
        lista= nuevo;
    }

    return lista;
}

///BUSCAR ULTIMO nodoListaProducto

nodoListaProducto * buscarUltimo (nodoListaProducto * lista)
{
    nodoListaProducto * seg=lista;

    if(seg!= NULL)
    {
        while(seg-> siguiente != NULL)
        {
            seg= seg-> siguiente;
        }
    }
    return seg;
}

///BUSCAR nodoListaProducto X NOMBRE --- si encuentra retorna su posicion de memoria y sino NULL

nodoListaProducto * buscarNodoListaProducto(nodoListaProducto * lista, char nombre[20])
{
    nodoListaProducto * seg= lista;

    while((seg!= NULL)    && (strcmp(nombre, seg->p.nombre)!=0))
    {
        seg= seg-> siguiente;
    }

    return seg;
}


///AGREGAR UN nodoListaProducto AL FINAL

nodoListaProducto * agregarFinal (nodoListaProducto * lista, nodoListaProducto * nuevo)
{
    if(lista==NULL)
    {
        lista= nuevo;
    }
    else
    {
        nodoListaProducto * ultimo= buscarUltimo(lista);
        ultimo->siguiente= nuevo;

    }
    return lista;
}



nodoListaProducto * borrarNodoListaProductoPorId (nodoListaProducto * lista, int id)
{
    nodoListaProducto * seg;
    nodoListaProducto * ante;  // apunta al nodoListaProducto anterior

    if(lista!= NULL)
    {
        if(lista->p.codigoProducto==id)
        {
            nodoListaProducto * aux = lista;
            lista= lista->siguiente; ///salteo el primer nodoListaProducto y lo elimino
            free(aux);
        }
        else
        {
            seg=lista;

            while((seg != NULL) && (id!=seg->p.codigoProducto))
            {
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg!= NULL)
            {
                ante->siguiente= seg->siguiente;
                free(seg);
            }

        }
    }
    return lista;
}


//nodoListaProducto * agregarEnOrden (nodoListaProducto *lista, nodoListaProducto * nuevo)
//{
//    if(lista==NULL)
//    {
//        lista= nuevo;
//    }
//    else
//    {
//        if(strcmp(nuevo->dato.apellido, lista->dato.apellido)<0)
//        {
//            lista=agregarPpio(lista, nuevo);
//
//        }
//        else      ///busco un lugar donde insertart el elemento
//        {
//            nodoListaProducto * ante=lista;
//            nodoListaProducto * seg= lista->siguiente;
//
//            while((seg!= NULL) && (strcmp(nuevo-> dato.nombre, seg->dato.nombre)>0))
//            {
//                ante=seg;
//                seg=seg->siguiente;
//            }
//
//            nuevo->siguiente=seg;
//            ante->siguiente= nuevo;
//
//
//        }
//    }
//    return lista;
//}

///borrar toda la lista y liberar la memoria ocupada

nodoListaProducto * borrarTodaLaLista (nodoListaProducto * lista)
{
    nodoListaProducto * proximo;
    nodoListaProducto * seg;

    seg=lista;
    while(seg!= NULL)
    {
        proximo=seg->siguiente;
        free(seg);
        seg=proximo;
    }
    return seg;   ///retorna NULL a la variable lista del main().
}




/// eliminar el primer nodoListaProducto de una lista

nodoListaProducto * eliminarPrimerNodoListaProducto (nodoListaProducto* lista)
{
    if (lista)
    {
        nodoListaProducto * seg= lista;

        lista= seg->siguiente;

        free(seg);
    }


    return lista;
}


nodoListaProducto * desvincularPrimero(nodoListaProducto * * plista)
{
    nodoListaProducto * primero=NULL;

    if(*plista!=NULL)
    {
        primero=*plista;

        *plista=(*plista)->siguiente;

        primero->siguiente=NULL;
    }

    return primero;
}
///ELIMINAR EL ULTIMO nodoListaProducto DE LA LISTA

nodoListaProducto * eliminarUltimoNodoListaProducto (nodoListaProducto * lista)
{
    nodoListaProducto * aux;
    nodoListaProducto * ante;

    if(lista)
    {
        if(lista->siguiente==NULL) /// la lista tiene un solo nodoListaProducto
        {
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        else  /// la lista tiene mas de un nodoListaProducto
        {
            aux=lista;
            while(aux->siguiente!=NULL)
            {
                ante=aux;
                aux=aux->siguiente;
            }
            free(aux);
            ante->siguiente=NULL;
        }
    }
    return lista;
}


void mostrarUnNodoListaProducto (nodoListaProducto * nodoDato)
{
    nodoListaProducto * aux= nodoDato;

    muestraUnProducto(aux->p);
}



///RECORRER Y MOSTRAR nodoListaProductoS

void recorrerYmostrar (nodoListaProducto * lista)
{
    if(lista)
    {
        nodoListaProducto * seg= lista;

        while(seg != NULL)
        {
            mostrarUnNodoListaProducto(seg);

            seg= seg->siguiente;
        }
    }
}


nodoListaProducto * agregarDatoPpioLista(nodoListaProducto * lista, stProducto dato)
{
    nodoListaProducto * nuevo= crearNodoListaProducto(dato);
    lista= agregarPpio(lista, nuevo);

    return lista;
}


stProducto verPrimerProducto(nodoListaProducto * lista)
{
    return lista->p;
}


int contarRecursivoListaProductos(nodoListaProducto * lista)
{
    int cant=0;

    if(lista)
    {

        cant=1+contarRecursivoListaProductos(lista->siguiente);
    }
    return cant;
}

float sumaListaProductosRecursiva(nodoListaProducto * lista)
{
    float rta;
    if(!lista)
    {
        rta=0;
    }
    else
    {
        rta=lista->p.precio+sumaListaProductosRecursiva(lista->siguiente);
    }

    return rta;
}

int verificarProductoExistenteEnListaProducto (nodoListaProducto * lista, int id)
{
    nodoListaProducto * seg = lista;
    int flag = 0;

   while(seg)
    {
       if(seg->p.codigoProducto==id)
       {
           flag = 1;
       }

       seg=seg->siguiente;
    }
    return flag;
}

nodoListaProducto * borrarListaDeProductos (nodoListaProducto * lista)
{
    nodoListaProducto * proximo;
    nodoListaProducto * seg = lista;
    while(seg)
        {
        proximo = seg->siguiente;   /// tomo la direccion del siguiente nodo
        free(seg);              /// libero la memoria del nodo actual
        seg = proximo;          /// me muevo al siguiente nodo
    }
    return seg;
}

