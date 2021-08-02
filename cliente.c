#include "cliente.h"

void muestraUnCliente (stCliente cliente)
{
    Color (BLACK, WHITE);
    printf("----------------------------------------\n");
    printf("\n");
    Color (BLACK, LMAGENTA);
    printf("ID:");
    Color (BLACK, WHITE);
    printf("        %d \n", cliente.id);
    Color (BLACK, LMAGENTA);
    printf("Nombre:");
    Color (BLACK, WHITE);
    printf("    %s %s \n", cliente.nombre, cliente.apellido);
    Color (BLACK, LMAGENTA);
    printf("DNI:");
    Color (BLACK, WHITE);
    printf("       %d \n", cliente.dni);
    Color (BLACK, LMAGENTA);
    printf("Tel%cfono:", 130);
    Color (BLACK, WHITE);
    printf("  %d \n", cliente.movil);
    Color (BLACK, LMAGENTA);
    printf("Mail:");
    Color (BLACK, WHITE);
    printf("      %s \n", cliente.mail);
    Color (BLACK, LMAGENTA);
    printf("Domicilio:");
    Color (BLACK, WHITE);
    printf(" %s %d %d %s\n", cliente.dir.calle, cliente.dir.numero, cliente.dir.piso, cliente.dir.departamento);
    Color (BLACK, WHITE);
    printf("\n");
    printf("----------------------------------------\n");
    Color (BLACK, LMAGENTA);

}


