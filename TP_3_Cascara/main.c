#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define TAM 10
int main()
{
    int contadorp=0,opcion=0;
    int* punteroContadorp=&contadorp;
    EMovie* listaP;
    char seguir='s';

    listaP=(EMovie*)malloc(sizeof(EMovie)*TAM);
    if(listaP==NULL)
    {
        printf("No hay memoria libre\n");
        exit(1);
    }
    if(cargarArchivo(listaP,punteroContadorp))
    {
        printf("El archivo se abrio correctamente\n");
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    while(seguir=='s')
    {
        printf("Peliculas cargadas:%d\n",contadorp);
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\nIngrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
          if(agregarPelicula(listaP,contadorp,TAM))
          {
              printf("Carga exitosa.\n");
              system("pause");
              contadorp++;
          }
            break;
        case 2:
            if(borrarPelicula(listaP,contadorp))
            {
                printf("\nPelicula borrada exitosamente.\n");
                system("pause");
                contadorp--;
            }
            break;
        case 3:
            if(modificarPelicula(listaP,contadorp))
            {
                printf("Pelicula modificada exitosamente.\n");
                system("pause");
            }
            break;
        case 4:
            if(generarPagina(listaP,contadorp,punteroContadorp))
            {
                printf("Pagina generada exitosamente.\n");
                system("pause");
            }
            break;
        case 5:
            if(contadorp==0)
            {
                remove("moviesbin.dat");
            }
            else
            {
                guardarEnArchivo(listaP,contadorp,punteroContadorp);
            }
            seguir='n';
            break;
        case 6:
            mostrarPeliculas(listaP, contadorp);
            system("pause");
            break;
        default:
            printf("Ingrese una opcion del 1 al 5.\n");
            break;
        }
        system("cls");
    }
    return 0;
}
