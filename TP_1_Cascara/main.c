#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0, num1 = 0, num2 = 0;

    while(seguir=='s')
    {
        system("cls");

        printf("1- Ingresar 1er operando (A=%d)\n", num1);
        printf("2- Ingresar 2do operando (B=%d)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            num1 = pedir_num1(num1);
            break;
        case 2:
            num2 = pedir_num2(num2);
            break;
        case 3:
            suma(num1, num2);
            system("pause");
            break;
        case 4:
            resta(num1, num2);
            system("pause");
            break;
        case 5:
            division(num1, num2);
            system("pause");
            break;
        case 6:
            multiplicacion(num1, num2);
            system("pause");
            break;
        case 7:
            factorial(num1);
            system("pause");
            break;
        case 8:
            suma(num1, num2);
            resta(num1, num2);
            division(num1, num2);
            multiplicacion(num1, num2);
            factorial(num1);
            system("pause");
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("opcion incorrecta.\n");
            system("pause");
            break;
        }
    }

    return 0;
}
