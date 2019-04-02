#include "Funciones.h"

int getInt(char mensaje[],int numero)
{
    printf("%s", mensaje);
    scanf("%d", &numero);

    return numero;
}
int sumar (int x ,int y)
{
    int r;
    r = x+y;
    return r;
}
int restar (int x ,int y)
{
    int r;
    r = x-y;
    return r;
}
int multiplicar (int x,int y)
{
    int r;
    r = x*y;
    return r;
}
float dividir (int x,int y)
{
    float r;
    if(y==0)
    {
        r=0;
        printf("No es posible dividir por cero\n");
    }else
    {
        r = (float)x/y;
    }
    return r;
}
long factorial (int x)
{
    int r;
    if(x<0)
    {
        r=0;
        printf("Factoreo no posible, el numero no puede ser menor a cero\n");
    }else
    {
        if(x==0)
        {
            r=1;
        }
        else
        {
            r=x*factorial(x-1);
        }
    }
    return r;
}
