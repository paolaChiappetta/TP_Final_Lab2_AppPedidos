#include "producto.h"


/// stProducto

///MUESTRA UN PRODUCTO P/ EL USUARIO//

void muestraUnProducto (stProducto producto)
{
    Color (BLACK, WHITE);
    printf("----------------------------------------------------------------------------\n");
    Color (BLACK, LMAGENTA);
    printf("Id: %d", producto.codigoProducto);
    Color (BLACK, WHITE);
    printf(" - ");
    Color (BLACK, LMAGENTA);
    printf("Cat.: %d", producto.categoria);
    Color (BLACK, WHITE);
    printf(" - ");
    Color (BLACK, LMAGENTA);
    printf(" %s ", producto.nombre);
    Color (BLACK, WHITE);
    printf("- ");
    Color (BLACK, LMAGENTA);
    printf(" %s ", producto.descripcion);
    printf("\n\nPrecio $%.2f ",producto.precio);
    Color (BLACK, WHITE);
    printf("  -  ");
    Color (BLACK, LMAGENTA);

    if(producto.categoria==1)
    {
        printf("Pote de helado por 1/2 kg.\n\n");
    }else if(producto.categoria==2)
    {
        printf("Tarta por 6 porciones\n\n");
    }else
    {
        printf("Caja de bombones por 6 unidades\n\n");
    }
    Color (BLACK, WHITE);
    printf("----------------------------------------------------------------------------\n");
    Color (BLACK, LMAGENTA);
}


