
#include "arbol.h"


nodoArbolstProducto * inicArbol()
{
    return NULL;
}

nodoArbolstProducto * crearNodoArbol(stProducto dato)
{
    nodoArbolstProducto * nuevo = (nodoArbolstProducto *) malloc(sizeof(nodoArbolstProducto));

    nuevo->p=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}


stProducto cargaUnProducto(nodoArbolstProducto* arbol, char nombre [])
{
    stProducto producto;

    strcpy(producto.nombre, nombre);
    Color (BLACK,   WHITE);
    printf("Categor%ca (1-Helados 2-Tortas 3-Bombones): ", 161);
    Color (BLACK,   LMAGENTA);
    scanf("%d", &producto.categoria);
    Color (BLACK,   WHITE);
    printf("Descripci%cn: ", 162);
    Color (BLACK,   LMAGENTA);
    fflush(stdin);
    gets(producto.descripcion);
    Color (BLACK,   WHITE);
    printf("Precio: ");
    Color (BLACK,   LMAGENTA);
    scanf("%f", &producto.precio);

    producto.codigoProducto=buscarUltimoIdArbol(arbol) +1;

    producto.alta = 1;


    return producto;

}

void recorrerInOrder (nodoArbolstProducto* arbol)  /// muestra datos en orden
{
    if(arbol)
    {

        recorrerInOrder(arbol->izq);
        mostrarUnNodo(arbol);
        recorrerInOrder(arbol->der);

    }
}


//nodoArbolstProducto* subprogramaModificaUnProductoPorId (nodoArbolstProducto* arbol)    /// no se si necesirta devolver el arbol
//{
//    nodoArbolstProducto* a=NULL;
//    stProducto producto;
//    int id;
//    char nombre [20];
//    char control='s';
//
//    while( control == 's')
//    {
//        recorrerInOrder (arbol);
//        printf("\n\nIndique el Id del producto que desea modificar: \n");
//
//        scanf("%d", &id);
//
//        a= buscarNodoArbolId(arbol, id);
//
//
//        printf("Nombre: ", 162);
//        fflush(stdin);
//        gets(a->p.nombre);
//
//        printf("Categor%ca (1-Helados 2-Tortas 3-Bombones): ", 161);
//        scanf("%d", &producto.categoria);
//
//        printf("Descripci%cn: ", 162);
//        fflush(stdin);
//        gets(a->p.descripcion);
//
//        printf("Precio: ");
//        scanf("%f", &a->p.precio);
//
//        printf("Estado del producto 1=alta/ 0=baja: ");
//        scanf("%d", &a->p.alta);
//
//        printf("Desea modificar otro producto? s/n \n");
//         fflush(stdin);
//        gets(control);
//
//
//        scanf("%s", &control);
//    }
//
//
//
//return arbol;
//}


int  buscarUltimoIdArbol (nodoArbolstProducto * a)
{
   nodoArbolstProducto* mayor=NULL;
   int rta=0;
    if(a )
    {
       mayor= nodoMasDerecha(a);
       rta= mayor->p.codigoProducto;

    }
    return rta;
}

nodoArbolstProducto *nodoMasDerecha(nodoArbolstProducto *arbol)
{
    nodoArbolstProducto *aux;
    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecha(arbol->der);
    }
    return aux;
}



void preOrden (nodoArbolstProducto * a)
{
    if(a!=NULL)
    {
        mostrarUnNodo(a);
        preOrden(a->izq);
        preOrden(a->der);
    }
}



void postOrden (nodoArbolstProducto * a)
{
    if(a!=NULL)
    {
        postOrden(a->izq);

        postOrden(a->der);

        mostrarUnNodo(a);
    }
}


void mostrarUnNodo (nodoArbolstProducto* arbol)
{
    muestraUnProducto(arbol->p);
}

///MODIFICAR REGISTRO DE PRODUCTO///
nodoArbolstProducto* modificarRegistroProducto(nodoArbolstProducto* arbol, int IdProducto)
{
    char control;
    int funcion = 0;

    nodoArbolstProducto* buscado=NULL;

    if (arbol)
    {

        buscado = buscarNodoArbolId(arbol,IdProducto);


        do
        {
            system ("cls");
            muestraUnProducto(buscado->p);
            menuModificacionRegistroProducto();
            scanf("%i", &funcion);
            system("cls");

            switch(funcion)
            {

            case 1:
                Color (BLACK,   WHITE);
                printf("Ingrese nuevamente la categor%ca del producto\n", 161);
                Color (BLACK,   LMAGENTA);
                scanf ("%d", &buscado->p.categoria);
                system("cls");
                muestraUnProducto (buscado->p);
                break;

            case 2:
                Color (BLACK,   WHITE);
                printf("Ingrese nuevamente el nombre del producto\n", 162);
                Color (BLACK,   LMAGENTA);
                fflush (stdin);
                gets (buscado->p.nombre);
                system("cls");
                muestraUnProducto (buscado->p);
                break;


            case 3:
                Color (BLACK,   WHITE);
                printf("Ingrese nuevamente la descripci%cn\n", 162);
                Color (BLACK,   LMAGENTA);
                fflush (stdin);
                gets (buscado->p.descripcion);
                system("cls");
                muestraUnProducto (buscado->p);
                break;

            case 4:
                Color (BLACK,   WHITE);
                printf("Ingrese nuevamente el precio\n");
                Color (BLACK,   LMAGENTA);
                scanf("%f", &buscado->p.precio);
                system("cls");
                muestraUnProducto (buscado->p);
                break;

            default:
                printf("La funci%cn no existe \n", 162);

            }
            Color (BLACK,   WHITE);
            printf("\n\nQuiere modificar otro dato? s/n\n");
            Color (BLACK,   LMAGENTA);
            fflush(stdin);
            printf("%c\n", control = getch());

        }
        while(control == 's');



    }

    else
    {
        Color (BLACK,   WHITE);
        printf ("\nNo existe un producto con ese c%cdigo", 162);
        Color (BLACK,   LMAGENTA);

    }
    return arbol;
}

///MENU PARA MODIFICAR DATOS PRODUCTO///
void menuModificacionRegistroProducto ()
{
    Color (BLACK,   WHITE);
    printf("Qu%c dato desea modificar?\n\n", 130);
    Color (BLACK,   LMAGENTA);
    printf("1- Categor%ca\n", 161);
    printf("2- Nombre\n");
    printf("3- Descripci%cn\n", 162);
    printf("4- Precio\n");
}


void recorrerInOrderFiltro (nodoArbolstProducto* arbol)
{
    if(arbol)
    {

        recorrerInOrderFiltro(arbol->izq);
        if(arbol->p.alta==1)
        {
            mostrarUnNodo(arbol);
        }

        recorrerInOrderFiltro(arbol->der);

    }
}

void recorrerInOrderFiltroBaja (nodoArbolstProducto* arbol)
{
    if(arbol)
    {

        recorrerInOrderFiltroBaja(arbol->izq);
        if(arbol->p.alta==0)
        {
            mostrarUnNodo(arbol);
        }

        recorrerInOrderFiltroBaja(arbol->der);

    }
}

void recorrerInOrderFiltroCategoria (nodoArbolstProducto* arbol, int categoria)
{
    if(arbol)
    {

        recorrerInOrderFiltroCategoria(arbol->izq, categoria);
        if(arbol->p.categoria==categoria)
        {
            mostrarUnNodo(arbol);
        }

        recorrerInOrderFiltroCategoria(arbol->der, categoria);

    }
}


nodoArbolstProducto* subprogramaCargaUnProducto(nodoArbolstProducto* arbol)
{
    stProducto producto;
    int codigo;
    char nombre [20];
    nodoArbolstProducto* buscado=NULL;
    char control='s';
    char control2;

    while( control == 's')
    {
        system("cls");
        Color (BLACK,   WHITE);
        printf("Cargue los datos del producto: \n\n");
        Color (BLACK,   WHITE);
        printf("Nombre: ");
        Color (BLACK,   LMAGENTA);
        fflush(stdin);
        gets(nombre);

        buscado= buscarPreOrderNombreProducto(arbol, nombre);

        if(buscado != NULL )
        {   Color (BLACK,   WHITE);
            printf("Ya existe un producto con ese nombre\n");
            Color (BLACK,   LMAGENTA);
            printf("\n");
            if(buscado->p.alta==0)
            {
                Color (BLACK,   WHITE);
                printf("El producto se encuentra dado de baja, desea darlo de alta? s/n \n");
                Color (BLACK,   LMAGENTA);
                fflush(stdin);
                scanf("%s", &control2);
                if(control2=='s')
                {
                    buscado->p.alta=1;
                }
            }

        }
        else
        {
            producto= cargaUnProducto(arbol, nombre);
            arbol= insertaOrdenadoArbolCreandoNodo(arbol, producto);
            system("cls");
            muestraUnProducto (producto);
            Color (BLACK,   WHITE);
            printf("\n\nDesea cargar un producto mas? s/n \n");
            Color (BLACK,   LMAGENTA);
            fflush(stdin);
            scanf("%s", &control);
        }

    }

    return arbol;
}



nodoArbolstProducto * buscarNodoArbolId (nodoArbolstProducto * a, int idProducto)
{
    nodoArbolstProducto * rta=NULL;
    if(a !=NULL)
    {
        if(a->p.codigoProducto == idProducto)
        {
            rta=a;
        }
        else
        {
            if(idProducto > a->p.codigoProducto)
            {
                rta=buscarNodoArbolId(a->der, idProducto);
            }
            else
            {
                rta=buscarNodoArbolId(a->izq, idProducto);
            }
        }
    }
    return rta;
}

nodoArbolstProducto* buscarPreOrderNombreProducto (nodoArbolstProducto* arbol, char nombre[])   ///devielve NULL si no lo encuentrA
{
    nodoArbolstProducto* rta= NULL;

    if (arbol)
    {

        if(strcmpi (arbol->p.nombre, nombre)== 0)
        {
            rta= arbol;
        }
        else
        {
            rta= buscarPreOrderNombreProducto(arbol->izq, nombre);

            if(!rta)
            {
                rta=buscarPreOrderNombreProducto(arbol->der, nombre);
            }


        }

    }
    return rta;
}


nodoArbolstProducto * insertaOrdenadoArbolCreandoNodo(nodoArbolstProducto * a, stProducto dato)   ///crea nodo
{
    if(a==NULL)
    {
        a=crearNodoArbol(dato);
    }
    else
    {
        if(dato.codigoProducto < a->p.codigoProducto)
        {
            a->izq=insertaOrdenadoArbolCreandoNodo(a->izq, dato);
        }
        else
        {
            a->der=insertaOrdenadoArbolCreandoNodo(a->der, dato);
        }
    }
    return a;
}

nodoArbolstProducto * insertaOrdenadoArbol(nodoArbolstProducto * a, nodoArbolstProducto* datoNodo)
{
    if(a==NULL)
    {
        a=datoNodo;
    }
    else
    {
        if(datoNodo->p.codigoProducto < a->p.codigoProducto)
        {
            a->izq=insertaOrdenadoArbol(a->izq, datoNodo);
        }
        else
        {
            a->der=insertaOrdenadoArbol(a->der, datoNodo);
        }
    }
    return a;
}

stProducto buscarEstructuraProductoEnArbolId (nodoArbolstProducto * a, int idProducto)
{
    stProducto prod;

    if(a !=NULL)
    {
        if(a->p.codigoProducto == idProducto)
        {
            prod=a->p;
        }
        else
        {
            if(idProducto > a->p.codigoProducto)
            {
                prod=buscarEstructuraProductoEnArbolId(a->der, idProducto);
            }
            else
            {
                prod=buscarEstructuraProductoEnArbolId(a->izq, idProducto);
            }
        }
    }
    return prod;
}


///ARCHIVO to arbol

nodoArbolstProducto* archivo2Arbol (char archivo [], nodoArbolstProducto* arbol)
{
    FILE * archi =fopen(archivo, "rb");
    nodoArbolstProducto* nuevo;
    stProducto p;

    if(archi!=NULL)
    {
        while (fread(&p, sizeof(stProducto), 1, archi)>0 )
        {
            nuevo= crearNodoArbol(p);

            arbol= insertaOrdenadoArbol(arbol,nuevo);
        }

        fclose(archi);
    }
    return arbol;
}


/// arbol a archivo

void arbol2Archivo (nodoArbolstProducto * arbol )
{
    FILE* arch =fopen(arProductos, "wb");
    if(arch)
    {
        guardaArbolRecursivo(arch, arbol);

        fclose(arch);
    }


}

void guardaArbolRecursivo (FILE * pArch, nodoArbolstProducto* arbol)
{


    if(arbol)
    {
          fwrite (&arbol->p, sizeof(stProducto), 1, pArch);
          guardaArbolRecursivo(pArch, arbol->izq);
          guardaArbolRecursivo(pArch, arbol->der);
    }

}


nodoArbolstProducto *borrarNodoArbol(nodoArbolstProducto *arbol,int idProducto)
{

    if(arbol!=NULL)
    {
        if(idProducto > arbol->p.codigoProducto)
        {
            arbol->der=borrarNodoArbol(arbol->der,idProducto);
        }
        else if(idProducto < arbol->p.codigoProducto)
        {
            arbol->izq=borrarNodoArbol(arbol->izq,idProducto);
        }
        else
        {
            if(arbol->izq!=NULL)
            {
                arbol->p=(nodoMasDerecha(arbol->izq)->p);
                arbol->izq=borrarNodoArbol(arbol->izq,arbol->p.codigoProducto);
            }
            else if(arbol->der!=NULL)
            {
                arbol->p=(nodoMasIzquierda(arbol->der)->p);
                arbol->der=borrarNodoArbol(arbol->der,arbol->p.codigoProducto);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}

nodoArbolstProducto *nodoMasIzquierda(nodoArbolstProducto *arbol)
{
    nodoArbolstProducto *aux;
    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierda(arbol->izq);
    }
    return aux;
}

nodoArbolstProducto* darDeBajaProducto(nodoArbolstProducto* arbol, int idProducto)
{

    nodoArbolstProducto* buscado=NULL;

    if (arbol)
    {
        buscado= buscarNodoArbolId(arbol, idProducto);


        buscado->p.alta=0;

    }
    return arbol;
}

nodoArbolstProducto* darDeAltaProducto(nodoArbolstProducto* arbol, int idProducto)
{

    nodoArbolstProducto* buscado=NULL;

    if (arbol)
    {
        buscado= buscarNodoArbolId(arbol, idProducto);


        buscado->p.alta=1;

    }
    return arbol;
}

int esHoja (nodoArbolstProducto* arbol)
{
    int rta=0;
    if(arbol)
    {
        if(arbol->izq== NULL && arbol->der==NULL)
        {
            rta=1;
        }
    }
    return rta;
}


nodoArbolstProducto* borrarArbol (nodoArbolstProducto* arbol)
{
    if(arbol)
    {

        arbol->der=borrarArbol(arbol->der);
        arbol->der=borrarArbol(arbol->izq);

        if(esHoja(arbol))
        {
            free(arbol);
            arbol=NULL;
        }

    }

    return arbol;
}

