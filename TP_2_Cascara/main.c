#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 20

int main()
{
    char seguir='s';
    EPersona lista[TAM];
    inicializarVariables(lista, TAM);

    while(seguir=='s')
    {

        system("cls");

        switch(menu())
        {
            case 1:
                alta(lista, TAM);
                break;
            case 2:
                baja(lista, TAM);
                break;
            case 3:
                mostrarTodos(lista, TAM);
                break;
            case 4:
                grafico(lista, TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
