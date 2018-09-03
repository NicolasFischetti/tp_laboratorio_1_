#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define INT_MAX 32767
#define INT_MIN -32767

void mostrarSumar(int numeroA, int numeroB, int resultado);
void mostrarRestar(int numeroA, int numeroB, int resultado);
void mostrarDividir(int numeroA, int numeroB);
void mostrarMultiplicar(int numeroA, int numeroB, int resultado);
void mostrarFactorial(int numeroA, int numeroB,  int resultado);

int main()
{
    char seguir='s';
    int opcion=0;
    int numeroA = 0;
    int numeroB = 0;
    int resultado;


    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando A: %d\n", numeroA);
        printf("2- Ingresar 2do operando B: %d\n", numeroB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el numero A\n");
                scanf("%d", &numeroA);
                break;
            case 2:
                printf("Ingrese el numero B\n");
                scanf("%d", &numeroB);
                break;
            case 3:
                mostrarSumar( numeroA, numeroB, resultado);
                break;
            case 4:
                mostrarRestar( numeroA, numeroB, resultado);
                break;
            case 5:
                mostrarDividir( numeroA, numeroB);
                break;
            case 6:
                mostrarMultiplicar( numeroA, numeroB, resultado);
                break;
            case 7:
               mostrarFactorial( numeroA, numeroB, resultado);
                break;
            case 8:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void mostrarSumar(int numeroA, int numeroB, int resultado)
{
    if (sumar(numeroA, numeroB, &resultado)==0)
        {
            printf("“El resultado de A+B es: %d\n", resultado);
        }
    else
        {
            printf("Error ingrese nuevamente su suma\n");
        }
}

void mostrarRestar(int numeroA, int numeroB, int resultado)
{
    if (restar(numeroA, numeroB, &resultado)==0)
        {
            printf("“El resultado de A-B es: %d\n", resultado );
        }
    else
        {
            printf("Error ingrese nuevamente su resta\n");
        }
}

void mostrarDividir(int numeroA, int numeroB)
{
    float resultadoDivision;
    if (dividir(numeroA, numeroB, &resultadoDivision)==0)
        {
            printf("El resultado de A/B es: %.2f\n", resultadoDivision);
        }
    else
        {
            printf("No es posible dividir por 0\n");
        }
}

void mostrarMultiplicar(int numeroA, int numeroB, int resultado)
{
    if (multiplicar(numeroA, numeroB, &resultado)==0)
        {
            printf("“El resultado de A*B es: %d\n", resultado );
        }
    else
        {
            printf("Error ingrese nuevamente su multiplicacion\n");
        }
}


void mostrarFactorial(int numeroA, int numeroB,  int resultado)
{
    if (factoriar(numeroA, &resultado)==0)
        {
            printf("El factorial de A es: %d\n", resultado );
        }
    else
        {
            printf("Error ingrese nuevamente su factorial\n");
        }
    if (factoriar(numeroB, &resultado)==0)
        {
            printf("El factorial de B es: %d\n", resultado );
        }
    else
        {
            printf("Error ingrese nuevamente su factorial\n");
        }
}
