#include "listaCliente.h"

nodoListaCliente * inicListaCliente()
{
    return NULL;
}

nodoListaCliente* crearNodoCliente(stCliente dato)
{
    nodoListaCliente * nuevo = (nodoListaCliente*) malloc(sizeof(nodoListaCliente));
    nuevo->c = dato;
    nuevo->sig = NULL;

    return nuevo;
}

nodoListaCliente* agregarAlPrincipioCliente(nodoListaCliente * lista, nodoListaCliente * nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodoListaCliente * agregarEnOrdenClientePorID (nodoListaCliente * lista, nodoListaCliente * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->c.id<lista->c.id)
        {
            lista=agregarAlPrincipioCliente(lista, nuevo);
        }
        else
        {
            nodoListaCliente * ante = lista;
            nodoListaCliente * seg = lista->sig;

            while(seg && (nuevo->c.id>seg->c.id))
            {
                ante = seg;
                seg = seg->sig;
            }
            nuevo->sig = seg;
            ante->sig = nuevo;
        }
    }
    return lista;
}



void muestraListaCliente(nodoListaCliente * lista)
{
    nodoListaCliente * seg = lista;

    while(seg)
    {

        muestraUnCliente(seg->c);

        seg = seg->sig;


    }
}


int buscarUltimoIdCliente (nodoListaCliente * lista)
{
    nodoListaCliente * seg = lista;
    int id = 0;

   while(seg)
    {
       if(seg->sig==NULL)
       {
           id=seg->c.id;
       }

       seg=seg->sig;
    }
    return id;
}

int verificarClienteExistente (nodoListaCliente * lista, int dni)
{
    nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if(seg->c.dni==dni)
       {
           flag = 1;
       }

       seg=seg->sig;
    }
    return flag;
}

int verificarClienteExistenteID (nodoListaCliente * lista, int id)
{
    nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if(seg->c.id==id)
       {
           flag = 1;
       }

       seg=seg->sig;
    }
    return flag;
}

int verificarAltaClientePorDNI (nodoListaCliente * lista, int dni)
{
    nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if((seg->c.dni==dni) && (seg->c.baja==1))
       {
           flag = 1;
       }

       seg=seg->sig;
    }
    return flag;
}

int verificarAltaClientePorId(nodoListaCliente * lista, int id)
{
    nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if((seg->c.id==id) && (seg->c.baja==1))
       {
           flag = 1;
       }

       seg=seg->sig;
    }
    return flag;
}

nodoListaCliente * darAltaClienteExistente (nodoListaCliente * lista, int dni)
{
     nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if(seg->c.dni==dni)
       {
           seg->c.baja==0;
       }

       seg=seg->sig;
    }
    return seg;
}

stCliente buscarEstructuraClienteEnListaDNI (nodoListaCliente * lista, int dni)
{
    nodoListaCliente * seg = lista;
    stCliente c;

   while(seg)
    {
       if(seg->c.dni==dni)
       {
           c=seg->c;
       }

       seg=seg->sig;
    }

    return c;
}

stCliente buscarEstructuraClienteEnListaID (nodoListaCliente * lista, int id)
{
    nodoListaCliente * seg = lista;
    stCliente c;

   while(seg)
    {
       if(seg->c.id==id)
       {
           c=seg->c;
       }

       seg=seg->sig;
    }

    return c;
}

int verificarCondicionDeCliente (nodoListaCliente * lista, int dni)
{
    nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if((seg->c.dni==dni) && (seg->c.rol==1)) ///devuelve 1 si es administrador
       {                                        ///0 si es usuario
           flag = 1;
       }

       seg=seg->sig;
    }
    return flag;
}


stCliente cargaUnCliente(nodoListaCliente * lista, int dni)
{
    stCliente cliente;

    int ultimoID = 0;

    cliente.dni=dni;
    ultimoID = buscarUltimoIdCliente(lista);
    cliente.id = ultimoID+1;
    Color (BLACK, WHITE);
    printf("Nombre:");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.nombre);
    Color (BLACK, WHITE);
    printf("Apellido:");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.apellido);
    Color (BLACK, WHITE);
    printf("Tel%cfono:", 130);
    Color (BLACK, LMAGENTA);
    scanf("%d", &cliente.movil);
    Color (BLACK, WHITE);
    printf("Mail:");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.mail);
    Color (BLACK, WHITE);
    printf("Domicilio:\n");
    printf("Calle:");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.dir.calle);
    Color (BLACK, WHITE);
    printf("N%cmero:", 163);
    Color (BLACK, LMAGENTA);
    scanf ("%d", &cliente.dir.numero);
    Color (BLACK, WHITE);
    printf("Piso:");
    Color (BLACK, LMAGENTA);
    scanf ("%d", &cliente.dir.piso);
    Color (BLACK, WHITE);
    printf("Departamento:");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.dir.departamento);
    Color (BLACK, WHITE);
    printf("Nombre de usuario:");
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.username);
    Color (BLACK, WHITE);
    printf("Contrase%ca:", 164);
    Color (BLACK, LMAGENTA);
    fflush(stdin);
    gets(cliente.password);
    Color (BLACK, WHITE);
//    printf("Rol (1-administrador / 0-usuario):");
//    Color (BLACK, LMAGENTA);
//    scanf ("%d", &cliente.rol);
    cliente.rol = 1;
    cliente.baja = 0;


    return cliente;

}

void listaClientesToArchivo (nodoListaCliente * lista)
{
    FILE *pArch = fopen(arCliente,"wb");
    stCliente aux;

    if(pArch)
    {
        while(lista)
        {

            aux = lista->c;
            fwrite(&aux, sizeof(stCliente), 1, pArch);

            lista = lista->sig;
        }
        fclose(pArch);
    }



}


///COMPROBAR USUARIO Y CONTRASEÑA///
int buscarIDEnListaPorUsuario (nodoListaCliente * lista, char usuario [])
{
    nodoListaCliente * seg = lista;
    int id = 0;

   while(seg)
    {
       if(strcmp(seg->c.username, usuario)==0)
       {
           id=seg->c.id;
       }

       seg=seg->sig;
    }
    return id;
}

int comprobarUsuarioYClaveDevuelveID(nodoListaCliente * lista, char usuario[], char clave [])
{
    int flag = -1;
    int id = -1;

    flag = verificarUsuarioYClaveEnLista (lista, usuario, clave);

    if(flag==1)
    {
        id = buscarIDEnListaPorUsuario (lista, usuario);
    }else if (flag==0)
    {
        Color (BLACK,   WHITE);
        printf("\nLa contrase%ca ingresada es incorrecta\n", 164);
        Color (BLACK,   LMAGENTA);
    }else
    {
        Color (BLACK,   WHITE);
        printf("\nUsuario no registrado, lo invitamos a registrarse\n");
        Color (BLACK,   LMAGENTA);
    }


    return id;
}


int verificarUsuarioYClaveEnLista (nodoListaCliente * lista, char usuario[], char clave [])
{
    nodoListaCliente * seg = lista;
    int flag = -1;

    while (seg)
    {
        if (strcmp(seg->c.username, usuario)==0)
        {
            flag = 0;
            if (strcmp(seg->c.password, clave)==0)
            {
                flag = 1;
            }
        }
        seg=seg->sig;

    }
    return flag;
}

int verificarRolPorUsuario(nodoListaCliente * lista, char usuario[])
{
    nodoListaCliente * seg = lista;
    int flag = 0;

   while(seg)
    {
       if (strcmp(seg->c.username, usuario)==0)
       {
           if (seg->c.rol==1)
           flag = 1;
       }

       seg=seg->sig;
    }
    return flag;
}

nodoListaCliente * buscarNodoenListaCliente (nodoListaCliente * lista, int id)
{
    nodoListaCliente * seg = lista;
    nodoListaCliente * buscado = NULL;

   while(seg)
    {
       if(seg->c.id==id)
       {
           buscado = seg;
       }

       seg=seg->sig;
    }
    return buscado;
}

nodoListaCliente * buscarNodoenListaClienteDNI (nodoListaCliente * lista, int dni)
{
    nodoListaCliente * seg = lista;
    nodoListaCliente * buscado = NULL;

   while(seg)
    {
       if(seg->c.dni=dni)
       {
           buscado = seg;
       }

       seg=seg->sig;
    }
    return buscado;
}

nodoListaCliente * darAltaClienteExistenteID (nodoListaCliente * lista, int id)
{
     nodoListaCliente * seg = lista;


   while(seg)
    {
       if(seg->c.id==id)
       {
           seg->c.baja==0;
       }

       seg=seg->sig;
    }
    return seg;
}

void muestraListaClienteActivos(nodoListaCliente * lista)
{
    nodoListaCliente * seg = lista;

    while(seg)
    {
        if(seg->c.baja==0)
        {
            muestraUnCliente(seg->c);
        }


        seg = seg->sig;
    }
}

void muestraListaClienteInactivos(nodoListaCliente * lista)
{
    nodoListaCliente * seg = lista;

    while(seg)
    {
        if(seg->c.baja==1)
        {
            muestraUnCliente(seg->c);
        }


        seg = seg->sig;
    }
}

nodoListaCliente * borrarListaDeClientes (nodoListaCliente * lista)
{
    nodoListaCliente * proximo;
    nodoListaCliente * seg = lista;
    while(seg)
        {
        proximo = seg->sig;   /// tomo la direccion del siguiente nodo
        free(seg);              /// libero la memoria del nodo actual
        seg = proximo;          /// me muevo al siguiente nodo
    }
    return seg;
}

stCliente verPrimeroCliente(nodoListaCliente * lista)
{
    return lista->c;
}

nodoListaCliente * eliminarPrimerNodoCliente(nodoListaCliente * lista)
{
    nodoListaCliente * aux=lista;
    lista=lista->sig;
    free(aux);
    return lista;
}

