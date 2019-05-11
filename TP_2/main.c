#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define T 3

int main()
{
    char seguir='s';
    char opcionInforme='.';

    eEmployee lista[T];
    initEmployees(lista, T);

    do
    {
        switch(menu())
        {
        case '1':
            addEmployees(lista,T);
            break;
        case '2':
            eEmployee_menuModificacion(lista,T);
            break;
        case '3':
            removeEmployee(lista,T);
            break;
        case '4':
            printf("1- Empleados ordenados por apellido\n");
            printf("2- Total y promedio de salarios\n");
            printf("3- Salir\n");
            opcionInforme = getOpcion("\nIngrese opcion entre 1 y 3: ", opcionInforme,'1','3');
            switch(opcionInforme)
            {
            case '1':
                sortEmployeeByName(lista,T);
                break;
            case '2':
                mostrarTotalPromedioySuperanPromedio(lista,T);
                break;
            case '3':
                break;
            default:
                printf("ERROR, INGRESE OPCION VALIDA");
            }
            break;
        case '5':
            printf("Seguro desea salir? s/n \n");
            fflush(stdin);
            seguir = getch();
            if(tolower(seguir)== 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Error, ingrese una opcion valida\n");
            break;
        }
    }while(seguir=='s');
    return 0;
}
