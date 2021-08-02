#include "pila.h"


void inicPilaP(Pila* p){
    (*p)=inicListaCliente();
}

int pilaVaciaP(Pila* p){
    int rta = 0;

    if((*p)==NULL){
        rta = 1;
    }else{
        rta = 0;
    }

    return rta;
}

void apilarP(Pila* p, stCliente dato)
{

    (*p)=agregarAlPrincipioCliente((*p),crearNodoCliente(dato));
}


stCliente desapilarP(Pila * p)
{
    stCliente cli = verPrimeroCliente(*p);
    (*p) = eliminarPrimerNodoCliente(*p);
    return cli;
}

stCliente topeP(Pila* p)
{

    return verPrimeroCliente(*p);
}

void mostrarPilaP(Pila* p)
{

   muestraListaCliente(*p);
}

int clienteExistenteEnPilaMejoresClientes (Pila * p, int idCliente)
{
    int flag = 0;
    stCliente c;
    Pila aux;
    inicPilaP(&aux);

    while(!pilaVaciaP(p))
    {
        c=topeP(p);
        if(c.id==idCliente && flag==0)
        {
            flag=1;
        }
        apilarP(&aux, desapilarP(p));

    }
    while(!pilaVaciaP(&aux))
    {
        apilarP(p, desapilarP(&aux));
    }

    return flag;
}
