#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    char dni[12];

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tamaño del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], char dni[], int tam);

/** \brief funcion para mostrar menu de opciones en la pantalla
 *
 * \return opcion del menu
 *
 */

int menu();

/** \brief funcion para dar de alta una persona al array
 *
 * \param array de la estructura persona
 * \param tamaño del array
 * \return void
 *
 */

void alta(EPersona lista[], int tam);

/** \brief funcion que muestra todas las personas del array
 *
 * \param array de personas
 * \param tamaño del array
 * \return flag que indica si hay personas ingresadas o no
 *
 */

int mostrarTodos(EPersona lista[], int tamP);

/** \brief funcion que muestra una sola persona del array
 *
 * \param persona del array
 * \param iterador para la funcion gotoxy
 * \return void
 *
 */

void mostrar(EPersona lista, int i);

/** \brief funcion que posiciona el cursor en una coordenada del eje x,y
 *
 * \param coordenada x
 * \param coordenada y
 * \return void
 *
 */

void gotoxy(int x,int y);

/** \brief funcion que da de baja una persona
 *
 * \param personas del array
 * \param tamaño del array
 * \return void
 *
 */

void baja(EPersona lista[], int tam);

/** \brief funcion que valida caracteres(si son numeros o letras)
 *
 * \param la variable a analizar
 * \return (1) si es digito (0) si no
 *
 */

int validarLetra(char opcion[]);

/** \brief funcion que valida que la edad no sea letras
 *
 * \return la edad validada
 *
 */

int ingresoEdadVal();

/** \brief funcion para inicializar las variables de la estructura
 *
 * \param array de personas
 * \param tamaño del array
 * \return void
 *
 */

void inicializarVariables(EPersona vec[], int tam);

/** \brief funcion que muestra un grafico de edades de las personas ingresadas
 *
 * \param array de personas
 * \param tamaño del array
 * \return void
 *
 */

void grafico(EPersona personas[], int tam);

#endif // FUNCIONES_H_INCLUDED
