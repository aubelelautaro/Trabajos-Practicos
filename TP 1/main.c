#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    int rta;
    int x=0;
    int y=0;
    int suma,resta,multiplicacion;
    long factoreoA;
    long factoreoB;
    float division;

    do{
        printf("1. Ingresar 1er operando\n");
        printf("2. Ingresar 2do operando\n");
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");
        printf("A=%d",x);
        printf("  B=%d\n",y);
        scanf("%d", &rta);

        switch(rta)
        {
            case 1:
                x = getInt("Ingrese A:", x);
                break;
            case 2:
                y = getInt("Ingrese B:", y);
                break;
            case 3:
                suma = sumar(x,y);
                resta = restar(x,y);
                multiplicacion = multiplicar(x,y);
                division = dividir(x,y);
                factoreoA = factorial(x);
                factoreoB = factorial(y);
                break;
            case 4:
                printf("a) El resultado de A+B es:%d\n", suma);
                printf("b) El resultado de A-B es:%d\n", resta);
                if(division==0)
                {
                    printf("c) La division no es posible\n");
                }else
                {
                    printf("c) El resultado de A/B es:%.2f\n", division);
                }
                printf("d) El resultado de A*B es:%d\n", multiplicacion);
                if(factoreoA<=0)
                {
                    printf("e)Factorial de A: error\n");
                }else
                {
                    printf("e) El factorial de A es:%li\n",factoreoA);
                }
                if(factoreoB<=0)
                {
                    printf("Factorial de B: error\n");
                }else
                {
                    printf(" El factorial de B es:%li\n",factoreoB);
                }
                break;
            case 5:
                break;
            default:
            printf("Error, opcion incorrecta\n");
        }
    }while(rta!=5);


    printf("\n\n");

    return 0;
}
