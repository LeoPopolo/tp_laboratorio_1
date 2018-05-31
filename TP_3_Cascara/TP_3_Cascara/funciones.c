#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int cargarArchivo(EMovie* lista,int* contador)
{
    int flag=0;
    FILE *f;
    f=fopen("moviesbin.dat","rb");
    if(f==NULL)
    {
        f=fopen("moviesbin.dat","wb");
        if(f==NULL)
        {
            return 0;
        }
        flag=1;
    }
    if(!flag)
    {
        fread(contador,sizeof(int),1,f);
        while(!feof(f))
        {
            fread(lista,sizeof(EMovie),*contador,f);
        }
    }

    fclose(f);
    return 1;
}

int agregarPelicula(EMovie* lista,int contador,int tam)
{
    system("cls");
    int duracion,puntaje;
    char duracionString[50],puntajeString[50],auxTituloString[50],auxGeneroString[50],auxDescripcionString[100],linkImagenString[300];
    if((contador%10)==0 && contador!=0)
    {
        printf("Se agregara 10 peliculas mas al espacio de memoria\n");
        EMovie* auxP;
        auxP=(EMovie*)realloc(lista,tam*sizeof(EMovie));
        if(auxP==NULL)
        {
            printf("No hay espacio de memoria\n");
            return 0;
        }
        else
        {
            lista=auxP;
            while(!getStringLetras("Ingrese el titulo de la pelicula: ",auxTituloString))
            {
                //getStringLetras("Reingrese el titulo de la pelicula: ",auxTituloString);
            }
            if(validarTitulo(lista,contador,auxTituloString))
            {
                while(!getStringLetras("Ingrese genero: ",auxGeneroString))
                {
                    //getStringLetras("Reingrese genero: ",auxGeneroString);
                }
                while(!getStringNumeros("Ingrese duracion en minutos: ",duracionString))
                {
                    getStringNumeros("Reinngrese duracion en minutos: ",duracionString);
                }
                duracion=atoi(duracionString);
                while(duracion<10 || duracion>400)
                {
                    //getStringNumeros("La duracion debe estar entre 10 y 400 minutos, reingrese: ",duracionString);
                }
                while(!getStringLetras("Ingrese la descripcion: ",auxDescripcionString))
                {
                    //getStringLetras("Reingrese la descripcion: ",auxDescripcionString);
                }
                while(!getStringNumeros("Ingrese el puntaje (1-10): ",puntajeString))
                {
                    //getStringNumeros("El puntaje debe contener solo numeros. reingrese: ",puntajeString);
                }
                puntaje=atoi(puntajeString);
                while(puntaje<1 || puntaje>10)
                {
                    //getStringNumeros("El puntaje debe solo numeros. reingrese: ",puntajeString);
                }
                printf("Ingrese el link de la imagen: ");
                fflush(stdin);
                gets(linkImagenString);

                strcpy((lista+contador)->linkImagen,linkImagenString);
                strcpy((lista+contador)->titulo,auxTituloString);
                strcpy((lista+contador)->genero,auxGeneroString);
                (lista+contador)->duracion=duracion;
                strcpy((lista+contador)->descripcion,auxDescripcionString);
                (lista+contador)->puntaje=puntaje;
            }
            else
            {
                printf("El titulo ya existe\n");
                system("pause");
                return 0;
            }
        }
    }
    else
    {
        while(!getStringLetras("Ingrese el titulo de la pelicula: ",auxTituloString))
            {
                //getStringLetras("Reingrese el titulo de la pelicula: ",auxTituloString);
            }
            if(validarTitulo(lista,contador,auxTituloString))
            {
                while(!getStringLetras("Ingrese genero: ",auxGeneroString))
                {
                    //getStringLetras("Reingrese genero: ",auxGeneroString);
                }
                while(!getStringNumeros("Ingrese duracion en minutos: ",duracionString))
                {
                    //getStringNumeros("Reingrese duracion en minutos: ",duracionString);
                }
                duracion=atoi(duracionString);
                while(duracion<10 || duracion>400)
                {
                    //getStringNumeros("La duracion debe estar entre 10 y 400 minutos, reingrese: ",duracionString);
                }
                while(!getStringLetras("Ingrese la descripcion: ",auxDescripcionString))
                {
                    //getStringLetras("Reingrese la descripcion: ",auxDescripcionString);
                }
                while(!getStringNumeros("Ingrese el puntaje (1-10): ",puntajeString))
                {
                    //getStringNumeros("El puntaje debe contener solo numeros. reingrese: ",puntajeString);
                }
                puntaje=atoi(puntajeString);
                while(puntaje<1 || puntaje>10)
                {
                    //getStringNumeros("El puntaje debe solo numeros. reingrese: ",puntajeString);
                }
                printf("Ingrese el link de la imagen: ");
                fflush(stdin);
                gets(linkImagenString);

                strcpy((lista+contador)->linkImagen,linkImagenString);
                strcpy((lista+contador)->titulo,auxTituloString);
                strcpy((lista+contador)->genero,auxGeneroString);
                (lista+contador)->duracion=duracion;
                strcpy((lista+contador)->descripcion,auxDescripcionString);
                (lista+contador)->puntaje=puntaje;
            }
            else
            {
                printf("El titulo ya existe\n");
                system("pause");
                return 0;
            }

    }

    return 1;
}

int validarTitulo(EMovie* lista,int contador,char* auxTitulo)
{
    for(int i=0; i<contador; i++)
    {
        if(strcmp(auxTitulo,(lista+i)->titulo)==0)
        {
            return 0;
        }
    }
    return 1;
}

int borrarPelicula(EMovie* lista,int contador)
{
    system("cls");
    int flag=0;
    char tituloString[50],opcion;
    if(contador!=0)
    {


    printf("\t\tLISTA DE PELICULAS\n\n");
    for(int i=0; i<contador; i++)
    {
        printf("%s\n",(lista+i)->titulo);
    }
    if(!getStringLetras("Ingrese el titulo a eliminar: ",tituloString))
    {
        printf("El titulo debe contener solo letras.\n");
        return 0;
    }

    for(int i=0; i<contador; i++)
    {
        if(strcmp(tituloString,(lista+i)->titulo)==0)
        {
            printf("TITULO :%s\nGENERO: %s\nDURACION: %d MINUTOS\nDESCRIPCION: %s\nPUNTAJE: %d\nLINK IMAGEN: %s\n", (lista+i)->titulo, (lista+i)->genero, (lista+i)->duracion, (lista+i)->descripcion, (lista+i)->puntaje, (lista+i)->linkImagen);


            printf("Seguro desea borrarla?: ");
            opcion=getche();
            if(opcion=='s' || opcion=='S')
            {
                strcpy((lista+i)->titulo,"NULL");
            }
            else
            {
                printf("\nEliminacion cancelada.\n");
                return 0;
            }
            flag=1;
            break;
        }
    }
    }
    else
    {
        printf("No hay peliculas existentes para borrar.\n");
        return 0;
    }
    if(!flag)
    {
        printf("No se encuentra la pelicula\n");
        return 0;
    }
    return 1;
}

int modificarPelicula(EMovie* lista,int contador)
{
    int opcion,AuxInt,flag=0;
    char auxTituloString[50],opcionString[50],AuxString[50];
    system("cls");
    if(contador!=0)
    {
        printf("\t\tLISTA DE PELICULAS\n\n");
        for(int i=0; i<contador; i++)
        {
            printf("%s\n",(lista+i)->titulo);
        }
        if(!getStringLetras("Ingrese el titulo a modificar: ",auxTituloString))
        {
            printf("El titulo debe contener solo letras.\n");
            return 0;
        }
        for(int i=0; i<contador; i++)
        {
            if(strcmp(auxTituloString,(lista+i)->titulo)==0)
            {
                flag=1;
                getStringNumeros("\nIngrese la opcion a modificar\n1-Titulo\n2-Genero\n3-Duracion\n4-Descripcion\n5-Puntaje\n6-Imagen\n",opcionString);
                opcion=atoi(opcionString);
                switch(opcion)
                {
                case 1:
                    if(!getStringLetras("Ingrese nuevo titulo: ",AuxString))
                    {
                        printf("El titulo debe contener solo letras\n");
                        return 0;
                    }
                    strcpy((lista+i)->titulo,AuxString);
                    break;
                case 2:
                    if(!getStringLetras("Ingrese nuevo genero: ",AuxString))
                    {
                        printf("El genero debe contener solo letras\n");
                        return 0;
                    }
                    strcpy((lista+i)->genero,AuxString);
                    break;
                case 3:
                    if(!getStringNumeros("Ingrese nueva duracion: ",AuxString))
                    {
                        printf("La duracion debe contener solo numeros.\n");
                        return 0;
                    }
                    AuxInt=atoi(AuxString);
                    if(AuxInt<10 || AuxInt>400)
                    {
                        printf("La duracion debe estar entre 10 y 400 minutos.\n");
                        return 0;
                    }
                    (lista+i)->duracion=AuxInt;
                    break;
                case 4:
                    if(!getStringLetras("Ingrese nueva descripcion: ",AuxString))
                    {
                        printf("La descripcion debe tener solo letras.\n");
                        return 0;
                    }
                    strcpy((lista+i)->descripcion,AuxString);
                    break;
                case 5:
                    if(!getStringNumeros("Ingrese nuevo puntaje: ",AuxString))
                    {
                        printf("El puntaje debe contener solo numeros.\n");
                        return 0;
                    }
                    AuxInt=atoi(AuxString);
                    if(AuxInt<1 || AuxInt>10)
                    {
                        printf("El puntaje debe estar entre 1 y 10");
                        return 0;
                    }
                    (lista+i)->puntaje=AuxInt;
                    break;
                case 6:
                    printf("\nIngrese nuevo link de imagen: ");
                    fflush(stdin);
                    gets((lista+i)->linkImagen);
                    break;
                default:
                    printf("Opcion incorrecta");
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay peliculas para modificar.");
        return 0;
    }
    if(!flag)
    {
        printf("No se encontraron peliculas con ese nombre.\n");
        return 0;
    }
    return 1;
}

int generarPagina(EMovie* lista,int contador,int* punteroContador)
{
    char nombreHtml[50]= {"listadoPeliculas"};
    FILE *f;
    int flag=0;
    strcat(nombreHtml,".html");
    f=fopen(nombreHtml,"w");
    if(f == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
    for(int i=0; i<contador; i++)
    {
        if(strcmp((lista+i)->titulo,"NULL")!=0)
        {
            fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(lista+i)->linkImagen);
            fprintf(f,"<h3><a href='#'>%s</a></h3>\n",(lista+i)->titulo);
            fprintf(f,"<ul><li>Genero:%s</li>\n<li>Puntaje:%d</li>\n<li>Duracion:%d</li></ul>\n",(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion);
            fprintf(f,"<p>%s</p></article>",(lista+i)->descripcion);
            flag=1;
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
    if(!flag)
    {
        printf("No se puede generar la pagina ya que no se encuentra ninguna pelicula.\n");
        system("pause");
        return 0;
    }
    if(!guardarEnArchivo(lista,contador,punteroContador))
    {
        printf("No se pudo abrir el archivo.\n");
        system("pause");
        return 0;
    }
    else
    {
        return 1;
    }
}

int guardarEnArchivo(EMovie* lista,int contador,int* punteroContador)
{
    FILE *f;
    f=fopen("moviesbin.dat","wb");
    if(f==NULL)
    {
        return 0;
    }
    fflush(stdin);
    fwrite(punteroContador,sizeof(int),1,f);

    fwrite(lista,sizeof(EMovie),contador,f);

    fclose(f);

    return 1;
}



void getString(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    fflush(stdin);
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    fflush(stdin);
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    fflush(stdin);
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void mostrarPelicula(EMovie* lista)
{
    printf("%s\t%s\t%s\%d\t%d\n", lista->titulo, lista->genero, lista->descripcion, lista->duracion, lista->puntaje);
}

void mostrarPeliculas(EMovie* lista, int tam)
{
    for(int i=0; i<tam; i++)
    {
        mostrarPelicula((lista+i));
    }
}
