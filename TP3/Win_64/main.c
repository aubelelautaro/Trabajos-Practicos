#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Aubele Lautaro
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag=1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("Error al crear la lista");
        exit(1);
    }
    do{
        flag =ll_isEmpty(listaEmpleados);
        option = getInt("\nMENU\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n10. Salir\nIngrese opcion: ",option,1,10);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
                system("cls");
                if(flag==0)
                {
                    if(controller_addEmployee(listaEmpleados))
                    {
                        printf("Se dió de alta.\n");
                    }else
                    {
                        printf("ERROR AL DAR DE ALTA.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }

                break;
            case 4:
                system("cls");
                if(flag==0)
                {
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("Modificacion exitosa.\n");
                    }else{
                        printf("ERROR AL MODIFICAR.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }
                break;
            case 5:
                system("cls");
                if(flag==0)
                {
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Baja exitosa.\n");
                    }else{
                        printf("ERROR AL DAR DE BAJA.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }
                break;
            case 6:
                system("cls");
                if(flag==0)
                {
                    if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("Se listaron los empleados exitosamente.\n");
                    }else{
                        printf("ERROR AL LISTAR.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }
                break;
            case 7:
                system("cls");
                if(flag==0)
                {
                    if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("Se ordeno exitosamente.\n");
                    }else{
                        printf("ERROR AL ORDENAR.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }
                break;
            case 8:
                system("cls");
                if(flag==0)
                {
                    if(controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("Se guardo como texto.\n");
                    }else{
                        printf("ERROR AL GUARDAR TEXTO.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }
                break;
            case 9:
                system("cls");
                if(flag==0)
                {
                    if(controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("Se guardo como binario.\n");
                    }else{
                        printf("ERROR AL GUARDAR ARCHIVO BINARIO.\n");
                    }
                }else
                {
                    printf("No se cargaron empleados todavia.\n");
                }
                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                exit(1);
                break;
        }
    }while(option != 10);

    return 0;
}
