#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "colores.h"

#include <string.h>
#define arCliente "clientes.dat"


///ESTRUCTURA DIRECCION - VA DENTRO DE ESTRUCTURA CLIENTE///
struct stDireccion
{
    char calle [30];
    int numero;
    int piso;
    char departamento [4];
};

///ESTRUCTURA CLIENTE///
typedef struct
{
    int id;          ///unico y todos consecutivos
    int dni;
    char nombre[30];
    char apellido[30];
    int movil;
    char mail[30];
    struct stDireccion dir;
    char username [30];
    char password [30];
    int rol;        ///       1= administrador   /  0 = usuario
    int baja;       ///       0= alta    /    1= baja
} stCliente;

void muestraUnCliente (stCliente cliente);

#endif // CLIENTE_H_INCLUDED
