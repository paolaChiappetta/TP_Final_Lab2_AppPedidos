#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#include "cliente.h"
#include "colores.h"


typedef struct
{
    stCliente c;
    struct nodoListaCliente * sig;
} nodoListaCliente;

nodoListaCliente * inicListaCliente();
nodoListaCliente* crearNodoCliente(stCliente dato);
nodoListaCliente* agregarAlPrincipioCliente(nodoListaCliente * lista, nodoListaCliente * nuevoNodo);
nodoListaCliente * agregarEnOrdenClientePorID (nodoListaCliente * lista, nodoListaCliente * nuevo);
void muestraListaCliente(nodoListaCliente * lista);
int buscarUltimoIdCliente (nodoListaCliente * lista);
int verificarClienteExistente (nodoListaCliente * lista, int dni);
int verificarAltaClientePorDNI (nodoListaCliente * lista, int dni);
int verificarAltaClientePorId(nodoListaCliente * lista, int id);
nodoListaCliente * darAltaClienteExistente (nodoListaCliente * lista, int dni);
stCliente buscarEstructuraClienteEnListaDNI (nodoListaCliente * lista, int dni);
stCliente buscarEstructuraClienteEnListaID (nodoListaCliente * lista, int id);
int verificarCondicionDeCliente (nodoListaCliente * lista, int dni);
stCliente cargaUnCliente(nodoListaCliente * lista, int dni);
void listaClientesToArchivo (nodoListaCliente * lista);
int buscarIDEnListaPorUsuario (nodoListaCliente * lista, char usuario []);
int comprobarUsuarioYClaveDevuelveID(nodoListaCliente * lista, char usuario[], char clave []);
int verificarUsuarioYClaveEnLista (nodoListaCliente * lista, char usuario[], char clave []);
int verificarRolPorUsuario(nodoListaCliente * lista, char usuario[]);
nodoListaCliente * buscarNodoenListaCliente (nodoListaCliente * lista, int id);
nodoListaCliente * darAltaClienteExistenteID (nodoListaCliente * lista, int id);
void muestraListaClienteActivos(nodoListaCliente * lista);
void muestraListaClienteInactivos(nodoListaCliente * lista);
nodoListaCliente * buscarNodoenListaClienteDNI (nodoListaCliente * lista, int dni);
nodoListaCliente * borrarListaDeClientes (nodoListaCliente * lista);
stCliente verPrimeroCliente(nodoListaCliente * lista);
nodoListaCliente * eliminarPrimerNodoCliente(nodoListaCliente * lista);

#endif // LISTACLIENTE_H_INCLUDED
