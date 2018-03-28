#include <stdio.h>
#include <stdlib.h>

int pedir_num1(int num)
{
    printf("Ingrese primer operando: ");
    scanf("%d", &num);

    return num;
}

int pedir_num2(int num)
{
    printf("Ingrese segundo operando: ");
    scanf("%d", &num);

    return num;
}

void suma(int num1, int num2)
{
    int resultado = num1 + num2;

    printf("La suma es: %d\n\n", resultado);

}

void resta(int num1, int num2)
{
    int resultado = num1 - num2;

    printf("La resta es: %d\n\n", resultado);

}

void division(int num1, int num2)
{
    float resultado;

    while(num2 == 0)
    {
        printf("ERROR. no se puede dividir por 0. reingrese segundo operando: ");
        scanf("%d", &num2);

    }

    resultado = (float) num1 / num2;

    printf("La division es: %.2f\n\n", resultado);

}

void multiplicacion(int num1, int num2)
{
    int resultado = num1 * num2;

    printf("La multiplicacion es: %d\n\n", resultado);

}

void factorial(int num)
{
    int resultado= 1;

    if(num == 0)
    {
        resultado = 1;
    }
    else if(num < 0)
    {
        resultado = 0;
    }
    else
    {
        for(int i=1; i<=num; i++)
        {
            resultado = resultado * i;
        }
    }

    printf("El factorial es: %d\n\n", resultado);

}
