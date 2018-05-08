#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void inicializarVariables(EPersona vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].estado = 0;
    }
}

int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int flag = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            flag = i;
        }
    }

    return flag;
}

int buscarPorDni(EPersona lista[], char dni[], int tam)
{
    int flag = -1;

    for(int i=0; i<tam; i++)
    {
        if(strcmp(lista[i].dni, dni) == 0 && lista[i].estado == 1)
        {
            flag = i;
            break;
        }
    }

    return flag;
}

void mostrar(EPersona lista, int i)
{
    gotoxy(0, i);
    printf("%s", lista.nombre);
    gotoxy(35, i);
    printf("%s", lista.dni);
    gotoxy(50, i);
    printf("%d", lista.edad);
    gotoxy(55, i);
}

int mostrarTodos(EPersona lista[], int tamP)
{
    int flag = -1, cont = 3, flagNEO = 1;

    EPersona aux;

    while(flagNEO == 1)
    {
        flagNEO = 0;
        for(int j=1; j<tamP; j++)
        {
            if(strcmp(lista[j].nombre, lista[j - 1].nombre) < 0)
            {
                aux = lista[j];
                lista[j] = lista[j - 1];
                lista[j - 1] = aux;
                flagNEO = 1;
            }
        }
    }


    system("cls");
    gotoxy(0, 1);
    printf("Nombre");
    gotoxy(35, 1);
    printf("DNI");
    gotoxy(50, 1);
    printf("Edad");

    for(int i=0; i<tamP; i++)
    {
        if(lista[i].estado == 1)
        {
            cont++;
            mostrar(lista[i], cont);
            flag = 1;
        }
    }
    printf("\n\n\n\n\n");
    if(flag != 1)
    {
        system("cls");
        printf("No hay personas para mostrar.\n");
    }
    system("pause");

    return flag;

}

void alta(EPersona lista[], int tam)
{
    EPersona nuevalista;
    int libre;

    libre = obtenerEspacioLibre(lista, tam);

    if(libre == -1)
    {
        system("cls");
        printf("No hay espacio para cargar.");
        system("pause");
    }
    else
    {
        system("cls");
        printf("**ALTA**\n\n");

        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        scanf("%[^\n]", nuevalista.nombre);
        while(strlen(nuevalista.nombre) > 28)
        {
            system("cls");
            printf("Nombre demasiado largo. Reingrese: ");
            fflush(stdin);
            scanf("%[^\n]", nuevalista.nombre);
        }
        nuevalista.edad = ingresoEdadVal();
        while(nuevalista.edad > 150)
        {
            printf("Reingrese edad: ");
            scanf("%d", &nuevalista.edad);
        }

        printf("Ingrese dni: ");
        fflush(stdin);
        scanf("%[^\n]", nuevalista.dni);
        while(strlen(nuevalista.dni) > 10)
        {
            printf("Ingrese un dni correcto: ");
            scanf("%[^\n]", nuevalista.dni);
        }

        nuevalista.estado = 1;

        system("cls");
        printf("Persona agregada!\n");
        system("pause");

    }
    lista[libre] = nuevalista;
}

void baja(EPersona lista[], int tam)
{
    char dni[12];
    char respuesta = 'n';
    int esta, flagEsta = 0;

    if((flagEsta = mostrarTodos(lista, tam)) == 1)
    {
        printf("\nIngrese dni a buscar: ");
        fflush(stdin);
        scanf("%[^\n]", dni);
        esta = buscarPorDni(lista, dni, tam);
        if(esta != -1)
        {
            system("cls");
            mostrar(lista[esta], 1);
            printf("\nConfirmar baja? s/n");
            fflush(stdin);
            respuesta = getch();
            if(respuesta == 's')
            {
                lista[esta].estado = 0;
                printf("\nBaja con exito.\n");
                system("pause");
            }
            else
            {
                printf("\nOpcion cancelada.\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("no existe el dni.\n");
            system("pause");
        }
    }
}

int validarLetra(char opcion[])
{
    int flag = 0,cant,i;

    cant = strlen(opcion);

    for(i=0; i<cant; i++)
    {
        if(!isdigit(opcion[i]))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int ingresoEdadVal()
{
    char opcion[30];
    int datoInt;

    printf("Ingrese edad: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese una edad valida: ");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}

int menu()
{
    char opcion[30];
    int datoInt;

    gotoxy(35, 1);
    printf("--Empleados--\n\n");
    gotoxy(30, 3);
    printf("1. Alta persona");
    gotoxy(30, 4);
    printf("2. Baja persona");
    gotoxy(30, 5);
    printf("3. Listar personas");
    gotoxy(30, 6);
    printf("4. Mostrar grafico de edades");
    gotoxy(30, 7);
    printf("5. Salir");
    gotoxy(30, 8);
    printf("Ingrese opcion: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese un numero ente 1 y 5:");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}

void grafico(EPersona personas[], int tam)
{
    int bar1=0,bar2=0,bar3=0,i,maximo=0,band=0;

    system("cls");

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado==1)
        {
            if(personas[i].edad<18)
            {
                bar1++;
            }
            if(personas[i].edad>17 && personas[i].edad<36)
            {
                bar2++;
            }
            if(personas[i].edad>35)
            {
                bar3++;
            }
        }
    }
    if(bar1>bar2 && bar1>bar3)
    {
        maximo=bar1;
    }

    else
    {
        if(bar2>bar1 && bar2>=bar3)
        {
            maximo=bar2;
        }
        else
        {
            maximo=bar3;
        }
    }
    for(i=maximo; i>0; i--)
    {
        if(i<=bar1)
        {
            printf("*");
        }
        if(i<=bar2)
        {
            band=1;
            printf("\t*");
        }
        if(i<=bar3)
        {
            if(band==0)
                printf("\t\t*");
            if(band==1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n");

    system("pause");
}
