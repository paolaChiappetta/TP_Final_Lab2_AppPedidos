
#include "colores.h"

///funcion cambio de colores///

void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);


 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color);

}
