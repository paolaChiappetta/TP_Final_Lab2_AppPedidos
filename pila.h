#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "listaCliente.h"
#define Pila nodoListaCliente*

void inicPilaP(Pila* p);
int pilaVaciaP(Pila* p);
void apilarP(Pila* p, stCliente dato);
stCliente desapilarP(Pila * p);
stCliente topeP(Pila* p);
void mostrarPilaP(Pila* p);
int clienteExistenteEnPilaMejoresClientes (Pila * p, int idCliente);



#endif // PILA_H_INCLUDED
