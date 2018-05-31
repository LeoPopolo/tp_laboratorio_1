#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
} EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  \param Pide el contador de peliculas
 *  \param Pide el tamaño de la lista dinamica
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* lista,int contador,int tam);
/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* lista,int contador);
/** \brief Modifica una pelicula del archivo binario
 * \param  Pide el puntero a la lista de peliculas
 * \param  Pide el contador de peliculas
 * \return Retorna 1 si esta todo bien y sino retorna 0
 */
int modificarPelicula(EMovie* lista,int contador);
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 *  \param Pide el puntero al contador de peliculas
 */
int generarPagina(EMovie* lista,int contador,int* punteroContador);
/** \brief Valida que el titulo no este repetido
 * \param Pide el puntero a la lista de peliculas
 * \param Pide el contador de peliculas
 * \param Pide el titulo que se ingreso
 * \return Retorna 1 si esta todo bien y sino retorna 0
 */
int validarTitulo(EMovie* lista,int contador,char* auxtitulo);
/** \brief Carga el archivo binario y sino lo crea
 * \param Pide el puntero a la lista de peliculas
 * \param Pide el puntero al contador de peliculas
 * \return Retrona 1 si esta todo bien y sino retorna 0
 */
int cargarArchivo(EMovie* lista,int* contador);
/** \brief Guarda la lista de peliculas en el archivo binario
 * \param  Pide el puntero a la lista de peliculas
 * \param  Pide el contador de peliculas
 * \param  Pide el puntero a el contador de peliculas
 * \return Retorna 1 si esta todo bien y sino retorna 0
 *
 */
int guardarEnArchivo(EMovie* lista,int contador,int* punteroContador);

/** \brief Muestra un mensaje y pide al usuario ingresar un string
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 */
void getString(char mensaje[],char input[]);
/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga letras
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 * \return Retorna 1 si esta todo validado, sino retorna 0
 */
int getStringLetras(char mensaje[],char input[]);
/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga numeros
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 * \return Retorna 1 si esta todo validado, sino retorna 0
 */
int getStringNumeros(char mensaje[],char input[]);
/** \brief Pide un string y valida que contenga solo letras
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene numero, sino retorna 1
 */
int esSoloLetras(char str[]);
/** \brief Pide un string y valida que contenga solo numeros
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene letras, sino retorna 1
 */
int esNumerico(char str[]);

void mostrarPelicula(EMovie* lista);
void mostrarPeliculas(EMovie* lista, int tam);

#endif // FUNCIONES_H_INCLUDED


