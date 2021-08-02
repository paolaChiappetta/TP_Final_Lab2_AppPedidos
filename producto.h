#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "colores.h"

typedef struct
{
    int categoria;  ///1-Helado 2-tortas 3-bombones
    int codigoProducto;
    char nombre [20];
    char descripcion[100];
    float precio;
    int alta;                    /// 1= alta    /    0= baja
} stProducto;






///MUESTRA UN PRODUCTO P/ EL USUARIO//

void muestraUnProducto (stProducto producto);
void muestraUnProductoCompleto (stProducto producto);





#endif // PRODUCTO_H_INCLUDED
