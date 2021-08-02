#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

///LIBRERIAS///
#include "cliente.h"
#include "colores.h"
#include "listaCliente.h"
#include "arbol.h"
#include "producto.h"
#include "listaProductos.h"
#include "listaCelda.h"
#include "filaPedido.h"
#include "pila.h"
#include "pilaProducto.h"

/// ARCHIVOS ///

#define arCliente "clientes.dat"
#define arPedidos "pedidos.dat"
#define arProductos "productos.dat"

///ESTRUCTURAS///

typedef struct
{
    int idPedido;
    int idCliente;
    int idProducto;
} stPedido;

///PROTOTIPADO FUNCIONES MENU///
void menuUsProg (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod);
void menuClientesPedidosUs(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod, int id);
void menuClientesPedidosProg(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod);
void menuClientesUs(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod, int id);
void menuPedidosUs(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod, int id);
void menuClientesProg(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod);
void menuPedidosProg(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod);

///PROTOTIPADO FUNCIONES MENU - PRINTF///
void menuUsuarioProgramador();
void menuClientesOPedidos();
void menuClientesPedidosProductoAdm();
void menuClientesUsuario();
void menuClientesProgramador();
void menuPedidosUsuario();
void menuPedidosProgramador();
void menuProductosProgramador();

nodoListaCliente * archivoToLista(char archivo[], nodoListaCliente * lista);
stCelda * archivoToCeldasClientes (stCelda * celdaClientes, nodoListaCliente * lista, nodoArbolstProducto * a);
stCelda * alta (stCelda * clientes, int idCliente, int idProducto, nodoArbolstProducto * a, nodoListaCliente * c);
stCelda * altaSinPedidos (stCelda * clientes, nodoListaCliente * lista, stCliente cli);
stCelda * listaDeClientesAListaCeldaFiltradoAlta (stCelda * celdaClientes, nodoListaCliente * lista);
stCelda * buscarCeldaCliente (stCelda * celdaClientes, stCliente c);
stCelda * nuevoCliente (stCelda * cliente, nodoListaCliente ** listaCliente, nodoArbolstProducto * prod); ///
void pedidosToArchivo (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod);
void subProgramaCerrarSesion (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod);
stCelda * modificarEstructuraCliente(stCelda * celdaCliente, nodoListaCliente * cli, int idCliente);
void menuModificacionCliente ();
stCelda * darDeBajaCliente(stCelda * celdaCliente, nodoListaCliente * cli, int idCliente);
stCelda* subprogramaHacerPedido (stCelda* celdaClientes, nodoArbolstProducto* arbol, int id); ///
void cargarFilaPedidos (Fila * filaPedido, nodoArbolstProducto* arbol);
void modificarPedidoFila (Fila * filaPedido, nodoArbolstProducto * nodo);
void menuModificarPedidoFila ();
void buscarProductoFilaAEliminar (Fila * filaPedido, int idProducto);
void eliminarPedidoFila (Fila * filaPedido) ;
nodoListaProducto * filaPedidosToListaProductos (Fila * filaPedidos, nodoListaProducto * lista);
void buscarRegistroProducto(nodoArbolstProducto* arbol);
void menuBuscarRegistroProducto ();
void mostrarListasPedidosCliente (stCelda* clientes);
void mejoresClientes (stCelda * celdaClientes, int cantClientes);
void mejoresClientesPorMonto (stCelda * celdaClientes, int cantClientes);
void subprogramaProductosRecomendados (stCelda* celdaClientes, int id);
void lista2PilaRecomendados (nodoListaProducto*lista, PilaProducto * p);
int buscarSiIdEstaEnPila (PilaProducto *p, nodoListaProducto*dato);
nodoArbolstProducto * arbol2lista (nodoArbolstProducto* arbol, nodoListaProducto * lista);
nodoListaProducto* agregarEnOrdenNombreProducto(nodoListaProducto* lista, nodoListaProducto * nuevo);
void listaProductosToArchivo (nodoListaProducto * lista);
nodoListaProducto * subprogramaArbolToListaToArchivo (nodoArbolstProducto * arbol);

int main()
{

    ///AL ABRIR EL PROGRAMA SE CARGAN LAS DIFERENTES ESTRCUTURAS P/TRABAJAR EN MEMORIA DINAMICA

    ///Inicializaciones
    nodoArbolstProducto * arbolDeProductos = inicArbol ();
    nodoListaCliente * listaClientes = inicListaCliente();
    stCelda * celdaDeClientes = inicListaCelda ();
    ///Paso de archivo de clientes a lista simple de clientes
    listaClientes = archivoToLista (arCliente, listaClientes);
    ///Paso de archivo de productos a arbol de productos
    arbolDeProductos = archivo2Arbol (arProductos, arbolDeProductos);
    ///Carga por estructura pedido, la lista de listas (lista de clientes c/ sus listas de productos
    celdaDeClientes = archivoToCeldasClientes (celdaDeClientes, listaClientes, arbolDeProductos);
    ///Carga en la lista de listas, aquellos clientes activos que no poseen pedidos
    celdaDeClientes = listaDeClientesAListaCeldaFiltradoAlta (celdaDeClientes, listaClientes);
    ///Inicia el menú de opciones
    menuUsProg(celdaDeClientes, listaClientes, arbolDeProductos);  ///menú que despliega los demás///
    return 0;
}

//////////////////////MENU OPCION USUARIO O ADMINISTRADOR  O REGISTRARSE ///////////
void menuUsProg (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{

    int menuUP; // menu usuario / administrador
    char controlUP; // control menu usuario / administrador

    int id = 0;
    char usuario[20];
    char contrasena[20];
    int rol = 0;
    int alta = 0;

    do
    {
        system("cls");
        menuUsuarioProgramador();  //// OPCION DE USUARIO / ADMINISTRADOR / REGISTRARSE / SALIR
        scanf("%i", &menuUP);
        system("cls");
        switch(menuUP)
        {
        case 1:
            Color (BLACK, WHITE);
            printf ("\n                   #define dulC - Una constante de dulzura-                    \n");
            Color (BLACK, LMAGENTA);
            printf ("\nIngrese usuario: ");
            Color (BLACK, WHITE);
            fflush(stdin);
            gets(usuario);
            Color (BLACK, LMAGENTA);
            printf ("\nIngrese contrase%ca: ", 164);
            Color (BLACK, WHITE);
            fflush(stdin);
            gets(contrasena);
            id=comprobarUsuarioYClaveDevuelveID (cli, usuario, contrasena);
            alta = verificarAltaClientePorId (cli, id);
            if(id>=0) ///si el id es mayor o igual a 0, significa que el cliente existe en la lista simple de clientes, ya que comienzan de 0
            {
                if(alta==0)  ///verifica q el cliente esté dado de alta para ingresar
                {
                    system("cls");
                    menuClientesPedidosUs (celdaClientes, cli, prod, id); ///opcion clientes o pedidos para el usuario
                }
                else  ///si no está de alta y existe, se le consulta si se quiere volver a dar de alta
                {
                    char opcion = 'n';
                    Color (BLACK, LMAGENTA);
                    printf("\nUd fue cliente de #define dulC, desea darse de alta nuevamente? s/n\n");
                    Color (BLACK, WHITE);
                    fflush(stdin);
                    scanf("%c", &opcion);
                    if(opcion=='s') ///si el cliente acepta, procede con reactivarse:
                    {
                        stCliente c;

                        nodoListaCliente * encontrado = buscarNodoenListaCliente (cli, id);  ///se modifica el cliente en la lista simple

                        encontrado->c.baja=0; ///busco el cliente en la lista y le modifico el alta

                        c= buscarEstructuraClienteEnListaID(cli, id); ///busco la estructura completa del cliente en la lista

                        stCelda * nuevaCelda = crearNodoCelda (c); ///genero nueva celda (no existe, ya que no estaba dado de alta

                        celdaClientes = agregarAlPrincipioCelda (celdaClientes, nuevaCelda);

                        system("cls");

                        menuClientesPedidosUs (celdaClientes, cli, prod, id); ///redirijo al menu

                    }

                }
            }
            break;

        case 2:
            Color (BLACK, WHITE);
            printf ("\n                   #define dulC - Una constante de dulzura-                    \n");
            Color (BLACK, LMAGENTA);
            printf ("\nIngrese usuario: ");
            Color (BLACK, WHITE);
            fflush(stdin);
            gets(usuario);
            Color (BLACK, LMAGENTA);
            printf ("\nIngrese contrase%ca: ", 164);
            Color (BLACK, WHITE);
            fflush(stdin);
            gets(contrasena);
            id=comprobarUsuarioYClaveDevuelveID (cli, usuario, contrasena);
            rol = verificarRolPorUsuario(cli, usuario);
            if(id>=0)  ///si el id es mayor o igual a 0, significa que el usuario existe en la lista simple de clientes, ya que comienzan de 0
            {
                if(rol==1)  ///verifico que el rol sea de administrador para ingresar
                {
                    system("cls");
                    menuClientesPedidosProg (celdaClientes, cli, prod); ///opcion clientes o pedidos para el ADMINISTRADOS
                }
                else  ///sino, lo redirijo al sector de usuarios/clientes
                {
                    system("cls");
                    menuClientesPedidosUs (celdaClientes, cli, prod, id); ///opcion clientes o pedidos para el usuario
                }

            }
            break;

        case 3:
            celdaClientes = nuevoCliente (celdaClientes, &cli, prod);  ///función p/registrarse
            break;

        case 4:
            subProgramaCerrarSesion (celdaClientes, cli, prod);
            exit (menuUsProg);
            break;


        default:
            Color (BLACK, WHITE);
            printf("\nEl n%cmero de men%c ingresado no existe \n", 163,163);
            Color (BLACK, LMAGENTA);
        }


        printf("\n\nQuiere ver otra funci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlUP = getch());


    }
    while(controlUP == 's');



}

/////////////////////MENU OPCION CLIENTES O PEDIDOS PARA EL USUARIO////////////
void menuClientesPedidosUs (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod, int id)
{
    int menuElegido; //menu clientes / pedidos
    char controlMenuCP; //control menu clientes / pedidos

    do
    {

        menuClientesOPedidos();
        scanf("%i", &menuElegido);
        system("cls");
        switch(menuElegido)
        {

        case 1:
            menuClientesUs(celdaClientes, cli, prod, id);  ///menu de mis datos para el usuario
            break;

        case 2:
            menuPedidosUs(celdaClientes, cli, prod, id);   ///menu de pedidos para el usuario
            break;

        case 98:
            menuUsProg(celdaClientes, cli, prod); ///volver al menú ppal
            break;

        case 99:
            subProgramaCerrarSesion (celdaClientes, cli, prod);
            exit (menuUsProg);
            break;


        default:
            Color (BLACK, WHITE);
            printf("\nEl n%cmero de men%c ingresado no existe \n", 163,163);
            Color (BLACK, LMAGENTA);

        }


        printf("\n\nQuiere ver otra funci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlMenuCP = getch());
    }
    while(controlMenuCP == 's');

    system("cls");
    menuUsProg(celdaClientes, cli, prod);

}
///////////////////////OPCION CLIENTES O PEDIDOS PARA EL ADMINISTRADOR////////////
void menuClientesPedidosProg (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{
    int menuElegido; //menu clientes / pedidos
    char controlMenuCP; //control menu clientes / productos / pedidos

    do
    {
        system("cls");
        menuClientesPedidosProductoAdm();
        scanf("%i", &menuElegido);
        system("cls");
        switch(menuElegido)
        {

        case 1:
            menuClientesProg(celdaClientes, cli, prod);   ///menu de clientes para el administrador
            break;

        case 2:
            menuProductosProg(celdaClientes, cli, prod);    ///menu de productos para el administrador
            break;

        case 3:
            menuPedidosProg(celdaClientes, cli, prod);    ///menu de pedidos para el administrador
            break;

        case 98:
            menuUsProg(celdaClientes, cli, prod);   ///volver al menú ppal
            break;

        case 99:
            subProgramaCerrarSesion (celdaClientes, cli, prod);
            exit (menuUsProg);
            break;

        default:
            Color (BLACK,   WHITE);
            printf("\nEl n%cmero de men%c ingresado no existe \n", 163,163);
            Color (BLACK, LMAGENTA);

        }


        printf("\n\nQuiere ver otra funci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlMenuCP = getch());
    }
    while(controlMenuCP == 's');

    system("cls");
    menuUsProg(celdaClientes, cli, prod);



}

/////////////////////////////MENU CLIENTES PARA EL USUARIO///////////////////////////////
void menuClientesUs(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod, int id)
{
    int menuC;  //menu clientes
    char controlClientes;  //control menu clientes

    stCliente c;
    int dni = 0;

    do
    {
        system("cls");
        menuClientesUsuario();
        scanf("%i", &menuC);
        system("cls");
        switch(menuC)
        {

        case 1:
            c=buscarEstructuraClienteEnListaID (cli, id);   ///busco estructura cliente por el id, que se conserva p/no solicitar datos al cliente p/ las dif funciones
            muestraUnCliente(c);  ///muestra sus datos

            break;

        case 2:
            celdaClientes = modificarEstructuraCliente (celdaClientes, cli, id); ///modificar datos
            break;

        case 3:
            celdaClientes = darDeBajaCliente (celdaClientes, cli, id);  ///da de baja (en lista simple de clientes) y elimina el nodo de la lista de listas
            menuUsProg(celdaClientes, cli, prod);  ///redirige al menú ppal, ya que debe estar dado de alta p/operar
            break;


        case 98:
            menuClientesPedidosUs(celdaClientes, cli, prod, id);   ///VOLVER AL MENU CLIENTES O PEDIDOS P/ EL USUARIO
            break;


        case 99:
            menuUsProg(celdaClientes, cli, prod);  ///VOLVER AL MENU PPAL
            break;

        default:
            Color (BLACK, WHITE);
            printf("La opci%cn ingresada no existe \n", 162);
            Color (BLACK, LMAGENTA);

        }

        printf("\n\nQuiere ver otra opci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlClientes = getch());

    }
    while(controlClientes == 's');

    system("cls");
    menuClientesPedidosUs(celdaClientes, cli, prod, id);
}

///////////////////////////////////////MENU PEDIDOS PARA EL USUARIO/////////////////////////////////
void menuPedidosUs(stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod, int id)
{
    int menuP;  //menu pedidos
    char controlPedidos;  //control menu pedidos

    stCelda * aux = NULL;

    do
    {
        system("cls");
        menuPedidosUsuario();
        scanf("%i", &menuP);
        system("cls");
        switch(menuP)
        {

        case 1:
            Color (BLACK, WHITE);
            printf("\n                    Nuestro Men%c - #define DulC:           \n\n", 163);
            Color (BLACK, LMAGENTA);
            recorrerInOrderFiltro(prod);  ///muestra el menu a través del arbol
            break;

        case 2:
            Color (BLACK, WHITE);
            printf("\n                    Nuestros helados - #define DulC:           \n\n", 163);
            Color (BLACK, LMAGENTA);
            recorrerInOrderFiltroCategoria(prod, 1);
            break;

        case 3:
            Color (BLACK, WHITE);
            printf("\n                    Nuestras tortas - #define DulC:           \n\n", 163);
            Color (BLACK, LMAGENTA);
            recorrerInOrderFiltroCategoria(prod, 2);
            break;

        case 4:
            Color (BLACK, WHITE);
            printf("\n                    Nuestros bombones - #define DulC:           \n\n", 163);
            Color (BLACK, LMAGENTA);
            recorrerInOrderFiltroCategoria(prod, 3);
            break;

        case 5:

            celdaClientes = subprogramaHacerPedido (celdaClientes, prod, id);  ///hacer un pedido
            break;

        case 6:
            Color (BLACK, WHITE);
            printf("\nMis consumos: \n\n");
            Color (BLACK, LMAGENTA);
            aux = buscarCeldaPorID (celdaClientes, id);  ///muestra los consumos dentro de la lista de productos del cte
            if(aux)
            {
                if(aux->listaDeProductos)
                {
                    recorrerYmostrar(aux->listaDeProductos);
                    float total = sumaListaProductosRecursiva (aux->listaDeProductos);
                    Color (BLACK, LMAGENTA);
                    printf("\nTotal consumido: ");
                    Color (BLACK, WHITE);
                    printf(" %.2f", total);
                }
                else
                {
                    printf("\nUd. no realiz%c consumos hasta el momento", 162);
                }
            }
            break;

        case 7:
            Color (BLACK, WHITE);
            printf("\nProductos recomendados: \n\n");
            Color (BLACK, LMAGENTA);
            subprogramaProductosRecomendados(celdaClientes, id);
            break;

        case 98:
            menuClientesPedidosUs(celdaClientes, cli, prod, id);   ///VOLVER AL MENU CLIENTES O PEDIDOS P/ EL USUARIO
            break;

        case 99:
            menuUsProg(celdaClientes, cli, prod);    ///VOLVER AL MENU PPAL
            break;


        default:
            Color (BLACK, WHITE);
            printf("La opci%cn ingresada no existe \n", 162);
            Color (BLACK, LMAGENTA);

        }

        printf("\n\nQuiere ver otra opci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlPedidos = getch());

    }
    while(controlPedidos == 's');

    system("cls");
    menuClientesPedidosUs(celdaClientes, cli, prod, id);


}
////////////////////////////MENU CLIENTES PARA EL ADMINISTRADOR////////////////////////////////
void menuClientesProg (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{
    int menuC;  //menu clientes
    char controlClientes;  //control menu clientes

    int id = 0;
    stCliente cliente;
    int flag=0;

    Pila pilaMejores;
    inicPilaP(&pilaMejores);

    int cantidad = 0;

    do
    {
        system("cls");
        menuClientesProgramador();
        scanf("%i", &menuC);
        system("cls");
        switch(menuC)
        {

        case 1:
            celdaClientes = nuevoCliente (celdaClientes, &cli, prod);   ///registrar un cliente nuevo
            break;

        case 2:
            Color (BLACK, LMAGENTA);
            printf("\nIngrese el ID del cliente que desea modificar ");
            Color (BLACK, WHITE);
            scanf("%d", &id);
            celdaClientes = modificarEstructuraCliente (celdaClientes, cli, id);  ///modificar un cliente
            break;

        case 3:
            Color (BLACK, LMAGENTA);
            printf("\nIngrese el ID del cliente que desea dar de baja ");  ///dar de baja un cliente
            Color (BLACK, WHITE);
            scanf("%d", &id);
            celdaClientes = darDeBajaCliente (celdaClientes, cli, id);
            break;

        case 4:
            Color (BLACK, LMAGENTA);
            printf("\nIngrese el ID del cliente que desea ver  ");  ///ver cliente por id
            Color (BLACK, WHITE);
            scanf("%d", &id);
            cliente = buscarEstructuraClienteEnListaID (cli, id);
            flag = verificarClienteExistenteID (cli, id);
            if(flag==1)
            {
                muestraUnCliente(cliente);
            }
            else
            {
                Color (BLACK, LMAGENTA);
                printf("\nEl ID ingresado no existe..");
            }

            break;

        case 5:
            Color (BLACK, WHITE);
            printf("Clientes activos\n\n");   ///muestra los clientes dados de alta de la lista simple de clientes
            Color (BLACK, LMAGENTA);
            muestraListaClienteActivos(cli);
            break;

        case 6:
            Color (BLACK, WHITE);
            printf("Clientes inactivos\n\n");  ///muestra los clientes dados de baja de la lista simple de clientes
            Color (BLACK, LMAGENTA);
            muestraListaClienteInactivos(cli);
            break;

        case 7:
            Color (BLACK, WHITE);
            printf("\nIngrese la cantidad de mejores clientes que desea ver\n");
            Color (BLACK, LMAGENTA);
            scanf("%d", &cantidad);
            system("cls");
            printf("Mejores clientes por cantidad de productos\n");
            mejoresClientes (celdaClientes, cantidad);
            break;

        case 8:
            Color (BLACK, WHITE);
            printf("\nIngrese la cantidad de mejores clientes que desea ver\n");
            Color (BLACK, LMAGENTA);
            scanf("%d", &cantidad);
            system("cls");
            printf("Mejores clientes por monto consumido\n");
            mejoresClientesPorMonto (celdaClientes, cantidad);
            break;


        case 98:
            menuClientesPedidosProg(celdaClientes, cli, prod);   ///VOLVER AL MENU CLIENTES / PEDIDOS / PRODUCTOS PARA EL ADM
            break;

        case 99:
            menuUsProg(celdaClientes, cli, prod);   ///VOLVER AL MENU PPAL
            break;


        default:
            Color (BLACK, WHITE);
            printf("La opci%cn ingresada no existe \n", 162);
            Color (BLACK, LMAGENTA);

        }

        printf("\n\nQuiere ver otra opci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlClientes = getch());

    }
    while(controlClientes == 's');

    system("cls");
    menuClientesPedidosProg(celdaClientes, cli, prod);

}
//////////////////////////////////MENU PEDIDOS PARA EL ADMINISTRADOR////////////////////////////////////
void menuPedidosProg (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{
    int menuP;  //menu pedidos
    char controlPedidos;  //control menu pedidos

    do
    {
        system("cls");
        menuPedidosProgramador();
        scanf("%i", &menuP);
        system("cls");
        switch(menuP)
        {

        case 1:
            Color (BLACK, WHITE);
            printf("\n                    Nuestro Men%c - #define DulC:           \n\n", 163);
            recorrerInOrderFiltro(prod);  ///muestra el menú a través del arbol de productos
            break;

        case 2:
            Color (BLACK, WHITE);
            printf("\nPedidos\n\n");   ///muestra la lista de listas, solo usuarios con pedidos efectuados
            muestraListaCeldaSiHayPedidos(celdaClientes);
            break;

        case 3:
            mostrarListasPedidosCliente(celdaClientes);  ///muestra la celda de la lista con sus productos de un cliente en particualr
            break;




        case 98:
            menuClientesPedidosProg(celdaClientes, cli, prod);   ///VOLVER AL MENU CLIENTES / PEDIDOS / PRODUCTOS PARA EL ADM
            break;

        case 99:
            menuUsProg(celdaClientes, cli, prod);   ///VOLVER AL MENU PPAL
            break;




        default:
            Color (BLACK, WHITE);
            printf("La opci%cn ingresada no existe \n", 162);
            Color (BLACK, LMAGENTA);

        }

        printf("\n\nQuiere ver otra opci%cn? s/n\n", 162);
        fflush(stdin);
        printf("%c\n", controlPedidos = getch());

    }
    while(controlPedidos == 's');

    system("cls");
    menuClientesPedidosProg(celdaClientes, cli, prod);

}

//////////////////////////////////MENU PRODUCTOS PARA EL ADMINISTRADOR/////////////////////////////////////
void menuProductosProg (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{
    int menuP;  //menu pedidos
    char controlProductos;  //control menu producto

    int categoria = 0;
    int id=0;

    do
    {
        system("cls");
        menuProductosProgramador();
        scanf("%i", &menuP);
        system("cls");
        switch(menuP)
        {

        case 1:

            prod = subprogramaCargaUnProducto (prod);   ///cargar un producto nuevo
            break;

        case 2:
             Color (BLACK, WHITE);
            printf("\nListado completo de productos\n");
            Color (BLACK, LMAGENTA);
            recorrerInOrder (prod);  ///ver los productos
            break;

        case 3:
            Color (BLACK, WHITE);
            printf("\nQue categoria desea ver? \n");  ///ver productos por categoria
            Color (BLACK, LMAGENTA);
            printf("\n1-Helados\n\n2-Tortas\n\n3-Bombones\n\n");
            scanf("%d", &categoria);
            recorrerInOrderFiltroCategoria(prod, categoria);
            break;

        case 4:
             Color (BLACK, WHITE);
            printf("\nListado de productos activos\n");
            Color (BLACK, LMAGENTA);
            recorrerInOrderFiltro (prod);  ///ver productos dados de alta
            break;

        case 5:
             Color (BLACK, WHITE);
            printf("\nListado de productos inactivos\n");
            Color (BLACK, LMAGENTA);
            recorrerInOrderFiltroBaja(prod);  ///ver productos dados de baja
            break;

        case 6:
            recorrerInOrder (prod);
            Color (BLACK, WHITE);
            printf("\Que producto desea modificar? Ingrese el ID\n");  ///modificar datos de un producto
            Color (BLACK, LMAGENTA);
            scanf("%d", &id);
            prod = modificarRegistroProducto (prod, id);
            break;

        case 7:
            Color (BLACK, WHITE);
             recorrerInOrderFiltro (prod); ///le muestro los productos activos
            printf("\Que producto desea dar de baja? Ingrese el ID\n");  ///dar de baja un producto (falta de stock x ej)
            Color (BLACK, LMAGENTA);
            scanf("%d", &id);
            prod = darDeBajaProducto (prod, id);
            break;

        case 8:
            Color (BLACK, WHITE);
            recorrerInOrderFiltroBaja(prod); ///le muestro los productos inactivos
            printf("\Que producto desea dar de alta nuevamente? Ingrese el ID\n");   ///dar de alta un producto ya cargado (reincorporacion x ej)
            Color (BLACK, LMAGENTA);
            scanf("%d", &id);
            prod = darDeAltaProducto(prod, id);
            break;

        case 9:
            buscarRegistroProducto(prod);  ///buscar un producto
            break;


        case 98:
            menuClientesPedidosProg(celdaClientes, cli, prod);     ///VOLVER AL MENU CLIENTES / PEDIDOS / PRODUCTOS PARA EL ADM
            break;

        case 99:
            menuUsProg(celdaClientes, cli, prod);  ///VOLVER AL MENU PPAL
            break;


        default:
            Color (BLACK, WHITE);
            printf("La opci%cn ingresada no existe \n", 162);
            Color (BLACK, LMAGENTA);

        }
        Color (BLACK, WHITE);
        printf("\n\nQuiere ver otra opci%cn? s/n\n", 162);
        Color (BLACK, LMAGENTA);
        fflush(stdin);
        printf("%c\n", controlProductos = getch());

    }
    while(controlProductos == 's');

    system("cls");
    menuClientesPedidosProg(celdaClientes, cli, prod);

}

nodoListaCliente * archivoToLista(char archivo[], nodoListaCliente * lista)  ///pasa el archivo de clientes a la lista simple de clientes
{
    FILE *pArchi = fopen(archivo, "rb");
    stCliente c;
    if(pArchi)
    {
        while(fread(&c, sizeof(stCliente), 1, pArchi)>0)
        {
            nodoListaCliente * aux = crearNodoCliente (c);
            lista=agregarEnOrdenClientePorID(lista, aux);
        }
        fclose(pArchi);
    }
    return lista;
}

stCelda * archivoToCeldasClientes (stCelda * celdaClientes, nodoListaCliente * lista, nodoArbolstProducto * a) ///toma los datos del archivo de pedidos
{
    ///p/cargar la lista de listas
    FILE * arch=fopen(arPedidos, "rb");
    int altaCliente = 0;


    if(arch)
    {
        stPedido p;

        while (fread(&p, sizeof(stPedido), 1, arch) > 0)
        {
            altaCliente = verificarAltaClientePorId(lista, p.idCliente); ///verifica si el cte está de alta para pasar a la lista ppal
            if(altaCliente==0) ///si está dado de alta
            {

                celdaClientes = alta (celdaClientes, p.idCliente, p.idProducto, a, lista);

            }

        }
        fclose (arch);

    }
    return celdaClientes;
}

stCelda * alta (stCelda * clientes, int idCliente, int idProducto, nodoArbolstProducto * a, nodoListaCliente * c)
{
    stProducto prod;
    stCliente cli;

    prod = buscarEstructuraProductoEnArbolId (a, idProducto); ///busca el prod en el arbol por id y lo retorna
    cli = buscarEstructuraClienteEnListaID (c, idCliente);  ///busca el cliente en la lista de clientes y lo retorna


    stCelda * encontrado = buscarCeldaCliente (clientes, cli);  ///verifica si el cliente ya se encuentra en la lista de listas

    if (encontrado==NULL)
    {

        stCelda * nuevaCelda = crearNodoCelda (cli); ///si no se encuentra crea el nodo

        clientes = agregarAlPrincipioCelda (clientes, nuevaCelda);  ///lo carga al ppio de la lista ppal

        clientes->listaDeProductos = agregarFinal (clientes->listaDeProductos, (crearNodoListaProducto(prod))); ///le carga el producto

        nuevaCelda->totalConsumido = sumaListaProductosRecursiva(nuevaCelda->listaDeProductos); ///suma el total de la lista y se carga al total consumido

    }
    else
    {
        encontrado->listaDeProductos = agregarFinal (encontrado->listaDeProductos, (crearNodoListaProducto(prod)));  ///si existe el cte en la lista, agrega alli el producto a su lista
        encontrado->totalConsumido = sumaListaProductosRecursiva(encontrado->listaDeProductos);  ///suma el total de la lista y se carga al total consumido
    }

    return clientes;
}

stCelda * altaSinPedidos (stCelda * clientes, nodoListaCliente * lista, stCliente cli) ///carga en lista de listas los clientes sin consumo que estan de alta
{

    stCelda * encontrado = buscarCeldaCliente (clientes, cli); ///verifica si el cliente se encuentra en la lista de listas

    if (encontrado==NULL)
    {

        stCelda * nuevaCelda = crearNodoCelda (cli);  ///genera nuevo nodo, con la lista de productos en null y consumo en $0

        clientes = agregarAlPrincipioCelda (clientes, nuevaCelda);  /// lo agrega a la lista ppal

    }

    return clientes;
}

stCelda * listaDeClientesAListaCeldaFiltradoAlta (stCelda * celdaClientes, nodoListaCliente * lista)
{
    stCelda * nuevaLista = celdaClientes;
    nodoListaCliente * aux = lista;

    while (aux)
    {
        if (aux->c.baja==0) ///si los clientes no estan dados de naja
        {
            nuevaLista = altaSinPedidos (nuevaLista, lista, aux->c);  ///se cargan en la lista ppal
        }

        aux = aux->sig;

    }
    return nuevaLista;
}

stCelda * buscarCeldaCliente (stCelda * celdaClientes, stCliente c) ///retorna la dir de memoria del nodo si se encuentra en la lista
{

    stCelda * seg = celdaClientes;
    stCelda * celdaEncontrada = NULL;  ///o retorna null si no se encuentra

    int flag = 0;

    while ((seg!=NULL) && flag==0)
    {

        if(seg->cliente.id==c.id)  ///verifica por id del cliente
        {
            celdaEncontrada=seg;
            flag=1;
        }
        seg=seg->siguiente;

    }

    return celdaEncontrada;
}


stCelda * nuevoCliente (stCelda * cliente, nodoListaCliente ** listaCliente, nodoArbolstProducto * prod) ///opción registrase
{
    stCliente c;
    int dni=0;
    int verificarExistencia = 0;
    int altaC=0;
    int rol = 0;

    Color (BLACK, LMAGENTA);
    printf("\nIngrese sus datos:\n\n");  ///consulta de dni primero para hacer las búsquedas
    Color (BLACK, WHITE);
    printf("DNI:");
    Color (BLACK, LMAGENTA);
    scanf("%d", &dni);

    verificarExistencia = verificarClienteExistente ((*listaCliente), dni);  ///verifica con flag en la lista completa de cliente
    ///si el cliente existe
    if(verificarExistencia==0)
    {
        c=cargaUnCliente ((*listaCliente), dni); ///permite ingresar los datos del cliente, devuelve una estructura de cliente


        nodoListaCliente * aux = crearNodoCliente (c); ///genera nuevo nodo del tipo lista cliente

        (*listaCliente)=agregarEnOrdenClientePorID((*listaCliente), aux); ///carga el nuevo nodo en la lista de clientes

        stCelda * nuevaCelda = crearNodoCelda (c); ///crea el nodo de la lista de listas

        cliente = agregarAlPrincipioCelda (cliente, nuevaCelda);  ///lo agrega

    }
    else if ((altaC=verificarAltaClientePorDNI((*listaCliente), dni))==1) ///si el cliente existe pero está dado de baja
    {
        char opcion = 'n';
        Color (BLACK, WHITE);
        printf("\nUd fue cliente de #define dulC, desea darse de alta nuevamente? s/n\n");
        Color (BLACK, LMAGENTA);
        fflush(stdin);
        scanf("%c", &opcion);
        if(opcion =='s') ///si el cliente procede con reactivarse:
        {
            nodoListaCliente * encontrado = buscarNodoenListaClienteDNI ((*listaCliente), dni);

            encontrado->c.baja=0; ///busco el cliente en la lista y le modifico el alta

            c= buscarEstructuraClienteEnListaDNI((*listaCliente), dni); ///busco la estructura completa del cliente en la lista

            stCelda * nuevaCelda = crearNodoCelda (c); ///crea el nodo de la lista de listas

            cliente = agregarAlPrincipioCelda (cliente, nuevaCelda); ///lo agrega (no está, porque el mismo estaba dado de baja)
        }
    }
    else  ///el cliente existe y está dado de alta
    {
        int hayCelda = 0;
        hayCelda=verificarClienteExistenteEnCelda (cliente, dni);
        if(hayCelda==0) ///verifico que se encuentra en la lista de listas
        {


            c= buscarEstructuraClienteEnListaDNI((*listaCliente), dni); ///busco la estructura completa del cliente en la lista

            stCelda * nuevaCelda = crearNodoCelda (c);

            cliente = agregarAlPrincipioCelda (cliente, nuevaCelda);

        }
        Color (BLACK, WHITE);
        printf("\nUd ya es cliente de #define dulC\n\n");  ///le indico que es cliente
        Color (BLACK, LMAGENTA);

        system("pause");


    }
    system("cls");

    menuUsProg (cliente, (*listaCliente), prod);  ///todos los  resultados posibles se redirigen al menu ppal



    return cliente;
}

void pedidosToArchivo (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{
    FILE * arch = fopen (arPedidos, "wb");  ///abro el archivo en modo sobre escritura, para que los datos esten actualizados

    stPedido ped;

    stCelda * aux = celdaClientes;

    int idPedido=0;

    if(arch)
    {
        while  (aux) ///recorro la lista ppal
        {
            ped.idCliente= aux->cliente.id;  ///asigno id del cliente

            nodoListaProducto * seg = aux->listaDeProductos;

            while (seg)  ///recorro la lista de productos del cliente
            {
                ped.idProducto=seg->p.codigoProducto;  ///asigno id del producto

                idPedido=idPedido+1;  ///id autoincremental

                ped.idPedido = idPedido;

                fwrite(&ped, sizeof(stPedido), 1, arch);  ///cargo el pedido en el archivo

                seg=seg->siguiente;
            }
            aux=aux->siguiente;

        }
        fclose(arch);
    }


}



void subProgramaCerrarSesion (stCelda * celdaClientes, nodoListaCliente * cli, nodoArbolstProducto * prod)
{
    ///PASO DE ESTRUCTURAS DINAMICAS A LOS DISTINTOS ARCHIVOS
    pedidosToArchivo (celdaClientes, cli, prod);

    listaClientesToArchivo (cli);
    arbol2Archivo (prod);

    nodoListaProducto * aux = inicListaProducto();
    aux = subprogramaArbolToListaToArchivo (prod);

    ///SE BORRAN ESTRUCTURAS DINAMICAS PARA LIBERAR MEMORIA
    celdaClientes = borrarListaCeldaDeClientes (celdaClientes);
    cli = borrarListaDeClientes (cli);
    prod=borrarArbol(prod);

}



///MODIFICAR REGISTRO DE CLIENTE///
stCelda * modificarEstructuraCliente(stCelda * celdaCliente, nodoListaCliente * cli, int idCliente) ///se modifica el cliente en ambas listas
{
    char control;
    int funcion = 0;

    stCelda * buscado = buscarCeldaPorID (celdaCliente, idCliente);  ///busco dir de mem en la lista ppal
    nodoListaCliente * encontrado = buscarNodoenListaCliente (cli, idCliente); ///busco dir de mem en la lista clientes

    stCliente cliente;
    Color (BLACK, WHITE);
    printf("\nDatos actuales\n\n");
    Color (BLACK, LMAGENTA);
    cliente = buscarEstructuraClienteEnListaID (cli, idCliente);
    muestraUnCliente (cliente);
    printf("\n");
    system("pause");


    char nombre[30];
    char apellido [30];
    char calle[30];
    char dpto [30];
    char mail[30];
    int dni = 0;
    int nro = 0;
    int piso =0;
    int telefono =0;

    if (buscado && encontrado)  ///debe estar en ambas listas ya que está dado de alta p/poder ingresar a la opcion
    {

        do
        {
            system ("cls");
            menuModificacionCliente();
            Color (BLACK, WHITE);
            scanf("%i", &funcion);
            Color (BLACK, LMAGENTA);
            system("cls");

            switch(funcion)
            {

            case 1:
                Color (BLACK, WHITE);
                printf("Ingrese nuevamente su nombre\n");
                Color (BLACK, LMAGENTA);
                fflush (stdin);
                gets(nombre);
                strcpy(buscado->cliente.nombre, nombre);
                strcpy(encontrado->c.nombre, nombre);

                break;

            case 2:
                Color (BLACK, WHITE);
                printf("Ingrese nuevamente su apellido\n");
                Color (BLACK, LMAGENTA);
                fflush (stdin);
                gets (apellido);
                strcpy(buscado->cliente.apellido, apellido);
                strcpy(encontrado->c.apellido, apellido);
                break;


            case 3:
                Color (BLACK, WHITE);
                printf("Ingrese su DNI");
                Color (BLACK, LMAGENTA);
                scanf("%d", &dni);
                buscado->cliente.dni = dni;
                encontrado->c.dni=dni;
                break;



            case 4:
                Color (BLACK, WHITE);
                printf("Ingrese nuevamente su domicilio\n");
                printf("Calle:");
                Color (BLACK, LMAGENTA);
                fflush(stdin);
                gets(calle);
                strcpy(buscado->cliente.dir.calle, calle);
                strcpy(encontrado->c.dir.calle, calle);
                Color (BLACK, WHITE);
                printf("N%cmero:", 163);
                Color (BLACK, LMAGENTA);
                scanf ("%d", &nro);
                buscado->cliente.dir.numero = nro;
                encontrado->c.dir.numero = nro;
                Color (BLACK, WHITE);
                printf("Piso:");
                Color (BLACK, LMAGENTA);
                scanf ("%d", &piso);
                buscado->cliente.dir.piso = piso;
                encontrado->c.dir.piso = piso;
                Color (BLACK, WHITE);
                printf("Departamento:");
                Color (BLACK, LMAGENTA);
                fflush(stdin);
                gets(dpto);
                strcpy(buscado->cliente.dir.departamento, dpto);
                strcpy(encontrado->c.dir.departamento, dpto);
                break;

            case 5:
                Color (BLACK, WHITE);
                printf("Ingrese su tel%cfono", 130);
                Color (BLACK, LMAGENTA);
                scanf("%d", &telefono);
                buscado->cliente.movil = telefono;
                encontrado->c.movil = telefono;
                break;

            case 6:
                Color (BLACK, WHITE);
                printf("Ingrese nuevamente su mail\n");
                Color (BLACK, LMAGENTA);
                fflush (stdin);
                gets (mail);
                strcpy(buscado->cliente.mail, mail);
                strcpy(encontrado->c.mail, mail);
                break;


            default:
                printf("La funci%cn no existe \n", 162);

            }


            Color (BLACK, WHITE);
            printf("\n\nQuiere modificar otro dato? s/n\n");
            Color (BLACK, LMAGENTA);
            fflush(stdin);
            printf("%c\n", control = getch());

        }
        while(control == 's');

    }

    return celdaCliente;
}


///MENU PARA MODIFICAR DATOS CLIENTE///
void menuModificacionCliente ()
{
    Color (BLACK, WHITE);
    printf("Qu%c dato desea modificar?\n\n", 130);
    Color (BLACK, LMAGENTA);
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- DNI\n");
    printf("4- Direcci%cn\n", 162);
    printf("5- Tel%cfono\n", 130);
    printf("6- Mail\n");
}

stCelda * darDeBajaCliente(stCelda * celdaCliente, nodoListaCliente * cli, int idCliente)
{
    stCelda * buscado = buscarCeldaPorID (celdaCliente, idCliente); ///busco dir de mem en lista ppal
    nodoListaCliente * encontrado = buscarNodoenListaCliente (cli, idCliente);  ///busco dir de mem en lista cliente

    if (buscado && encontrado)
    {

        encontrado->c.baja=1; ///le modifico la baja en la lista de clientes
        celdaCliente = borrarNodoCeldaCliente (celdaCliente, idCliente);  ///elimino el nodo en la lista de listas
    }

    Color (BLACK, WHITE);
    printf("\n\nHa sido dado de baja, esperamos verlo pronto!!\n\n");
    Color (BLACK, LMAGENTA);
    system("pause");

    return celdaCliente;
}



stCelda* subprogramaHacerPedido (stCelda* celdaClientes, nodoArbolstProducto* arbol, int id)
{

    stCelda* nodoCliente;
    Fila filaPedido;
    inicFila  (&filaPedido);
    char opcion = 'n';
    float total = 0;

    nodoCliente= buscarCeldaPorID (celdaClientes, id);  ///busco dir de mem del cliente en la lista ppal

    cargarFilaPedidos (&filaPedido, arbol);  /// se procede a la carga de productos en la fila
    Color (BLACK, WHITE);
    printf("\nDesea modificar su pedido? s/n\n");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    scanf("%c", &opcion);

    if(opcion=='s')  ///si al ver el pedido se desean hacer cambios
    {
        modificarPedidoFila (&filaPedido, arbol);  ///permite eliminar y agregar productos o cancelar el pedido
    }


    nodoCliente->listaDeProductos = filaPedidosToListaProductos (&filaPedido, nodoCliente->listaDeProductos);  ///paso los productos de la fila a la lista de consumos del cliente

    total = sumaListaProductosRecursiva (nodoCliente->listaDeProductos);  ///sumo el total consumido por medio de la lista

    nodoCliente->totalConsumido = total;  ///lo asigno
    Color (BLACK, WHITE);
    printf("\nMuchas gracias por su pedido, ya lo estamos preparando!\n");
    Color (BLACK, LMAGENTA);


    return celdaClientes;
}

void cargarFilaPedidos (Fila * filaPedido, nodoArbolstProducto* arbol)
{
    int pedido=0;
    char control='s';
    float totalParcial=0.0;
    float total = 0.0;
    int cantidad = 0;
    nodoArbolstProducto* nodoP;

    do
    {
        system ("cls");
        Color (BLACK,   WHITE);
        printf("\n                    Nuestro Men%c - #define DulC:           \n\n", 163);
        recorrerInOrderFiltro(arbol);
        Color (BLACK,   WHITE);
        printf("\nIndique el Id del producto que desea pedir: \n\n");
        Color (BLACK,   LMAGENTA);
        scanf("%d", &pedido);

        nodoP=buscarNodoArbolId(arbol, pedido);

        if (nodoP)  ///si el producto existe
        {
            printf("\n");

            agregar(filaPedido, nodoP->p);  ///agrego el producto a la fila
            Color (BLACK,   WHITE);
            system("cls");
            printf("\nSu pedido en #define DulC \n");
            Color (BLACK,   LMAGENTA);
            muestraFila(filaPedido);   ///voy mostrando el pedido
            totalParcial=totalParcial + nodoP->p.precio;
            Color (BLACK,   WHITE);
            printf("\n\nTotal parcial: ", totalParcial); ///voy mostrando el total parcial
            Color (BLACK,   LMAGENTA);
            printf(" %.2f\n\n", totalParcial);

        }
        else
        {
            Color (BLACK,   WHITE);
            printf("\nEl id ingresado no existe. \n");
            Color (BLACK,   LMAGENTA);
        }

        Color (BLACK,   WHITE);
        printf("Desea agregar otro producto: s/n \n");
        Color (BLACK,   LMAGENTA);
        fflush(stdin);
        scanf("%c",&control);

    }
    while( control == 's');

    system("cls");
    Color (BLACK,   WHITE);
    printf("\nSu pedido en #define DulC \n\n");
    Color (BLACK,   LMAGENTA);
    muestraFila (filaPedido);   ///finaliza la carga mostrando el pedido
    cantidad = contarFilaRecursiva (filaPedido);
    Color (BLACK,   WHITE);
    printf("\n\nTotal de productos: ");   ///cant de productos
    Color (BLACK,   LMAGENTA);
    printf(" %d\n", cantidad);   ///cant de productos
    total = sumaFilaRecursiva (filaPedido);
    Color (BLACK,   WHITE);
    printf("\nTotal de la compra: ");   ///total del pedido
    Color (BLACK,   LMAGENTA);
    printf(" %.2f\n\n", total);   ///total del pedido
}


void modificarPedidoFila (Fila * filaPedido, nodoArbolstProducto * nodo)
{
    char control;
    int funcion = 0;
    int id = 0;



    do
    {
        system ("cls");
        Color (BLACK, WHITE);
        printf("\nSu pedido en #define DulC \n\n");
        Color (BLACK,   LMAGENTA);
        muestraFila (filaPedido);  ///muestra el pedido para seleccionar modificacion
        printf("\n\n");
        menuModificarPedidoFila();
        Color (BLACK,   WHITE);
        scanf("%i", &funcion);
        system("cls");

        switch(funcion)
        {

        case 1:
            cargarFilaPedidos(filaPedido, nodo);  ///agrega un producto
            break;

        case 2:
            Color (BLACK,   WHITE);
            printf("\nSu pedido en #define DulC \n\n");
            Color (BLACK,   LMAGENTA);
            muestraFila (filaPedido);
            Color (BLACK,   WHITE);
            printf("\nIngrese el ID del producto que desea eliminar de su pedido\n");
            Color (BLACK,   LMAGENTA);
            scanf("%d", &id);
            buscarProductoFilaAEliminar(filaPedido, id);  ///elimina producto por id
            break;

        case 3:
            eliminarPedidoFila(filaPedido);  ///elimina el  total del pedido al extraer todos sus productos
            Color (BLACK,   WHITE);
            printf("\nSu pedido ha sido cancelado");
            Color (BLACK,   LMAGENTA);
            break;

        default:
            printf("La funci%cn no existe \n", 162);

        }
        Color (BLACK,   WHITE);
        printf("\n\nDesea hacer otra modificaci%cn? s/n\n", 162);
        Color (BLACK,   LMAGENTA);
        fflush(stdin);
        printf("%c\n", control = getch());

    }
    while(control == 's');



}

void menuModificarPedidoFila ()
{
    Color (BLACK, WHITE);
    printf("\nQu%c modificaci%cn desea realizar?\n\n", 130, 162);
    Color (BLACK, LMAGENTA);
    printf("\n1- Agregar un producto\n");
    printf("\n2- Eliminar un producto\n");
    printf("\n3- Cancelar mi pedido\n\n");

}


void buscarProductoFilaAEliminar (Fila * filaPedido, int idProducto)
{
    stProducto extraido;
    int flag = 0;



    flag = verificarProductoExistenteEnListaProducto (filaPedido->inicio, idProducto); ///verifica si el id se encuentra en la fila

    if(flag==1)
    {
        while(!filaVacia(filaPedido) && (filaPedido->inicio->p.codigoProducto!=idProducto))
        {
            extraido = extraer (filaPedido);  ///mientras no sea el id que solicita eliminar lo extrae
            agregar(filaPedido, extraido);  ///y lo agrega al final de la fila p/no perderlo
        }

        if(filaPedido->inicio->p.codigoProducto==idProducto)
        {

            extraido = extraer (filaPedido);  ///si es el q desea eliminar, se extrae de la fila
        }
    }
    else
    {
        Color (BLACK,   WHITE);
        printf("\nEl ID ingresado no existe en su pedido");
        Color (BLACK,   LMAGENTA);
    }


}

void eliminarPedidoFila (Fila * filaPedido)  ///elimina fila completa / pedido completo
{
    stProducto extraido;

    while(!filaVacia(filaPedido))
    {
        extraido = extraer (filaPedido);

    }

}

nodoListaProducto * filaPedidosToListaProductos (Fila * filaPedidos, nodoListaProducto * lista) ///pasa los productos de la fila a la lista de consumos gral
{
    stProducto prod;

    while (!filaVacia(filaPedidos))
    {
        prod = primero (filaPedidos);
        lista = agregarPpio (lista, crearNodoListaProducto(prod));

        extraer (filaPedidos);

    }
    return lista;
}

///BUSCAR UN REGISTRO DE PRODUCTO///
void buscarRegistroProducto(nodoArbolstProducto* arbol)
{
    char control;
    int funcion = 0;

    int id;
    char nombre [50];

    nodoArbolstProducto* buscado=NULL;


    if (arbol)
    {



        do
        {
            system ("cls");
            menuBuscarRegistroProducto();
            scanf("%i", &funcion);
            system("cls");

            switch(funcion)
            {

            case 1:
                Color (BLACK,   WHITE);
                printf("Ingrese el ID del producto\n");
                Color (BLACK,   LMAGENTA);
                scanf ("%d", &id);
                buscado = buscarNodoArbolId(arbol,id);
                if(buscado)
                {
                    Color (BLACK,   WHITE);
                    printf("El producto es: \n");
                    Color (BLACK,   LMAGENTA);
                    mostrarUnNodo(buscado);
                }
                else
                {
                    Color (BLACK,   WHITE);
                    printf("no existe ese producto\n");
                    Color (BLACK,   LMAGENTA);
                }

                break;

            case 2:
                Color (BLACK,   WHITE);
                printf("Ingrese el nombre del producto:\n");
                Color (BLACK,   LMAGENTA);
                fflush (stdin);
                gets (nombre);
                buscado= buscarPreOrderNombreProducto(arbol,nombre);
                if(buscado)
                {
                    Color (BLACK,   WHITE);
                    printf("El producto es: \n");
                    Color (BLACK,   LMAGENTA);
                    mostrarUnNodo(buscado);
                }
                else
                {
                    Color (BLACK,   WHITE);
                    printf("no existe ese producto\n");
                    Color (BLACK,   LMAGENTA);
                }


                break;


            default:
                printf("La funci%cn no existe \n", 162);

            }
            Color (BLACK,   WHITE);
            printf("\n\nQuiere buscar otro producto? s/n\n");
            Color (BLACK,   LMAGENTA);
            fflush(stdin);
            printf("%c\n", control = getch());

        }
        while(control == 's');

    }


    return arbol;
}

///MENU PARA MODIFICAR DATOS PRODUCTO///
void menuBuscarRegistroProducto ()
{
    Color (BLACK,   WHITE);
    printf("Indique como desea buscar su producto\n\n");
    Color (BLACK,   LMAGENTA);
    printf("1- Id\n\n", 161);
    printf("2- Nombre\n\n");

}


void mostrarListasPedidosCliente (stCelda* clientes) ///muestra la lista de productos junto con los datos del cliente  seleccionado
{
    int id;
    stCelda *cliente;

    char control='s';

    do
    {
        system("cls");
        Color (BLACK,   WHITE);
        printf("Indique el ID del Cliente del que desea ver pedidos: \n");
        Color (BLACK,   LMAGENTA);
        scanf("%d", &id);
        printf("\n");
        cliente = buscarCeldaPorID(clientes, id);

        if(cliente)
        {
            if(cliente->listaDeProductos)
            {
                muestraUnCliente (cliente->cliente);
                recorrerYmostrar(cliente->listaDeProductos);
            }
            else
            {
                 Color (BLACK,   LMAGENTA);
                printf("\nEl cliente no ha realizado pedidos\n\n");

            }
        }else
        {
                Color (BLACK,   LMAGENTA);
                printf("\nEl cliente no existe o no se encuentra activo\n\n");

        }


        Color (BLACK,   WHITE);
        printf("Desea ver otra lista? s/n \n");
        Color (BLACK,   LMAGENTA);
        fflush(stdin);
        scanf("%c", &control);

    }
    while( control == 's');

}

void mejoresClientes (stCelda * celdaClientes, int cantClientes)
{

    Pila pilaMejores;
    inicPilaP (&pilaMejores);

    int flag = 0;

    stCelda * mayorCliente;


    for (int i=0; i<cantClientes; i++)
    {
        int cantidad=0;
        int mayor=0;
        stCelda * seg = celdaClientes;

        while(seg)
        {

            cantidad = contarRecursivoListaProductos (seg->listaDeProductos);
            flag=clienteExistenteEnPilaMejoresClientes(&pilaMejores, seg->cliente.id);
            if(cantidad>=mayor)
            {
                if(flag==0)
                {
                    mayor=cantidad;
                    mayorCliente=seg;

                }

            }
            seg=seg->siguiente;
        }

        apilarP(&pilaMejores, mayorCliente->cliente);


    }

    mostrarPilaP(&pilaMejores);
    desapilarP(&pilaMejores);
}

void mejoresClientesPorMonto (stCelda * celdaClientes, int cantClientes)
{


    Pila pilaMejores;
    inicPilaP (&pilaMejores);
    int flag = 0;

    stCelda * mayorCliente;


    for (int i=0; i<cantClientes; i++)
    {
        float monto=0;
        float mayor=0;
        stCelda * seg = celdaClientes;

        while(seg)
        {

            monto = seg->totalConsumido;
            flag=clienteExistenteEnPilaMejoresClientes(&pilaMejores, seg->cliente.id);
            if(monto>=mayor)
            {
                if(flag==0)
                {
                    mayor=monto;
                    mayorCliente=seg;

                }

            }
            seg=seg->siguiente;
        }

        apilarP(&pilaMejores, mayorCliente->cliente);


    }

    mostrarPilaP(&pilaMejores);
    desapilarP(&pilaMejores);
}



void subprogramaProductosRecomendados (stCelda* celdaClientes, int id)
{

    stCelda* nodoCliente;
    PilaProducto recomendado;
    inicPila (&recomendado);


    nodoCliente= buscarCeldaPorID (celdaClientes, id);  ///busco dir de mem del cliente en la lista ppal


    lista2PilaRecomendados(nodoCliente->listaDeProductos, &recomendado);


    muestraPila(&recomendado);
    desapilar(&recomendado);
}

void lista2PilaRecomendados (nodoListaProducto*lista, PilaProducto * p)
{
    PilaProducto aux;
    inicPila(&aux);
    nodoListaProducto*seg= lista;
    int buscar=0;

    while(seg)
    {
        buscar= buscarSiIdEstaEnPila(p, seg);

        if( buscar == 0)
        {
            apilar(p, seg->p);
        }

        seg=seg->siguiente;
    }

}



int buscarSiIdEstaEnPila (PilaProducto *p, nodoListaProducto*dato)
{
    int esta=0;
    PilaProducto aux;
    inicPila(&aux);

    while(!pilaVacia(p))
    {
        if(dato->p.codigoProducto == tope(p).codigoProducto)
        {

            esta=1;
        }
        apilar(&aux, desapilar(p));
    }

    while(!pilaVacia(&aux))
    {
        apilar(p, desapilar(&aux));

    }

    return esta;
}

nodoArbolstProducto * arbol2lista (nodoArbolstProducto* arbol, nodoListaProducto * lista) ///para desordenar productos por id se genera lista ordena por nombre
{
    if (arbol)
    {

        lista= arbol2lista(arbol->izq, lista);
        lista= agregarEnOrdenNombreProducto(lista, crearNodoListaProducto(arbol->p));
        lista=arbol2lista(arbol->der, lista);
    }
    return lista;
}

nodoListaProducto* agregarEnOrdenNombreProducto(nodoListaProducto* lista, nodoListaProducto * nuevo)
{
    if(lista==NULL)
        {
        lista=nuevo;
    }else
    {
        if((strcmp(nuevo->p.nombre,lista->p.nombre)) < 0) ///compara alfabéticamente
        {
            lista=agregarPpio(lista, nuevo);
        }else
        {
            nodoListaProducto* ante = lista;
            nodoListaProducto* seg = lista->siguiente;
            while(seg && (strcmp(nuevo->p.nombre, seg->p.nombre) > 0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

void listaProductosToArchivo (nodoListaProducto * lista)
{
    FILE *pArch = fopen(arProductos,"wb");
    stProducto aux;

    if(pArch)
    {
        while(lista)
        {

            aux = lista->p;
            fwrite(&aux, sizeof(stProducto), 1, pArch);

            lista = lista->siguiente;
        }
        fclose(pArch);
    }



}

nodoListaProducto * subprogramaArbolToListaToArchivo (nodoArbolstProducto * arbol)
{
    nodoListaProducto * aux;

    aux = arbol2lista (arbol, aux);
    listaProductosToArchivo(aux);

    return aux;

}

///////////////////////////////////////////////////MENU/////////////////////////////////////////////////////////
void menuUsuarioProgramador()
{
    system ("Color 011");
    printf("\n");
    Color (BLACK, LGREY);
    printf("             ------------------- BIENVENIDOS -------------------    \n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("                   #define dulC, -Una constante de dulzura-        \n" );
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Escriba el n%cmero de men%c al que se quiera dirigir:", 163, 163);
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- USUARIO\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- ADMINISTRADOR\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- REGISTRARSE\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 4- SALIR\n");
    printf("\n");
    printf("\n");
}

void menuClientesOPedidos()
{

    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("                #define dulC, -Una constante de dulzura-   \n");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Escriba el n%cmero de men%c al que se quiera dirigir:", 163, 163);
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- MIS DATOS\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- PEDIDOS");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c principal\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("99- SALIR\n");
    printf("\n");
    printf("\n");
}

void menuClientesPedidosProductoAdm()
{

    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("                 #define dulC, -Una constante de dulzura-  \n");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Escriba el n%cmero de men%c al que se quiera dirigir:", 163, 163);
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- CLIENTES\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- PRODUCTOS\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- PEDIDOS");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c principal\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("99- SALIR\n");
    printf("\n");
    printf("\n");
}

void menuClientesUsuario()
{
    printf("\n");
    Color (BLACK,LGREY);
    printf("MIS DATOS");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Ingrese la opci%cn a la que desea dirigirse:\n", 162);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- Ver mis datos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- Modificar mis datos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- Darme de baja\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c Mis datos/Pedidos\n", 163);
    Color (BLACK, LMAGENTA);
    printf("99- Volver al men%c principal\n", 163);
    printf("\n");
    printf("\n");
}

void menuClientesProgramador()
{
    printf("\n");
    Color (BLACK,LGREY);
    printf("CLIENTES");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Ingrese la opci%cn a la que desea dirigirse:\n", 162);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- Registrar nuevo cliente\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- Modificar datos de un cliente\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- Dar de baja un cliente\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 4- Ver cliente por ID\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 5- Listado de clientes activos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 6- Listado de clientes inactivos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 7- Listado de los mejores clientes por cantidad de productos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 8- Listado de los mejores clientes por monto gastado\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c Clientes/Productos/Pedidos\n", 163);
    Color (BLACK, LMAGENTA);
    printf("99- Volver al men%c principal\n", 163);
    printf("\n");
    printf("\n");
}

void menuPedidosUsuario()
{
    printf("\n");
    Color (BLACK,LGREY);
    printf("PEDIDOS");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Ingrese la opci%cn a la que desea dirigirse:\n", 162);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- Ver men%c completo\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- Ver men%c de helados\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- Ver men%c de tortas\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 4- Ver men%c de bombones\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 5- Hacer un pedido\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 6- Ver mis consumos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 7- Productos recomendados\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c Mis datos/Pedidos\n", 163);
    Color (BLACK, LMAGENTA);
    printf("99- Volver al men%c principal\n", 163);
    printf("\n");
    printf("\n");
}

void menuPedidosProgramador()
{
    printf("\n");
    Color (BLACK,LGREY);
    printf("PEDIDOS");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Ingrese la opci%cn a la que desea dirigirse:\n", 162);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- Ver men%c\n", 163);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- Ver pedidos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- Ver pedidos por cliente\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c Clientes/Productos/Pedidos\n", 163);
    Color (BLACK, LMAGENTA);
    printf("99- Volver al men%c principal\n", 163);
    printf("\n");
    printf("\n");
}


void menuProductosProgramador()
{
    printf("\n");
    Color (BLACK,LGREY);
    printf("PRODUCTOS");
    printf("\n");
    printf("\n");
    Color (BLACK, WHITE);
    printf("Ingrese la opci%cn a la que desea dirigirse:\n", 162);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 1- Cargar nuevo producto\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 2- Ver listado  completo de productos activos e inactivos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 3- Ver listado de productos por categor%ca\n", 161);
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 4- Ver listado de productos activos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 5- Ver listado de productos inactivos\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 6- Modificar un producto\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 7- Dar de baja un producto\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 8- Dar de alta un producto\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf(" 9- Buscar registro de un producto\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("98- Volver al men%c Clientes/Productos/Pedidos\n", 163);
    Color (BLACK, LMAGENTA);
    printf("99- Volver al men%c principal\n", 163);
    printf("\n");
    printf("\n");
}
