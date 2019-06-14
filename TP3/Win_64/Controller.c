#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret =0;
    FILE* pFile=fopen(path,"r");

    if(pFile == NULL)
    {
        printf("El archivo no existe.");
    }
    else
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        ret=1;
        printf("Cargados de texto exitosamente.\n");
    }
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret =0;
    FILE* pFile=fopen(path,"rb");

    if(pFile == NULL)
    {
        printf("El archivo no existe.");
    }
    else
    {
        ret = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        printf("Cargados de binario exitosamente\n");
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int auxId=0;
    char auxIdStr[20];
    char auxNombre[128];
    char auxHoras[20];
    char auxSueldo[20];

    Employee* emp = employee_new();
    if(pArrayListEmployee != NULL && emp!= NULL)
    {
        auxId=controller_proximoId(pArrayListEmployee);
        itoa(auxId,auxIdStr,10);
        getStringLetras("Ingrese nombre: \n",auxNombre);
        getStringNumeros("Ingrese horas trabajadas: \n",auxHoras);
        getStringNumeros("Ingrese sueldo (entero): \n",auxSueldo);
        emp=employee_newParametros(auxIdStr,auxNombre,auxHoras,auxSueldo);
        if(emp!=NULL)
        {
            ll_add(pArrayListEmployee, emp);
            printf("Alta exitosa!\n");
            ret=1;
        }
    }else
    {
        printf("ERROR.");
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char auxIdStr[100];
    int auxId=0;
    int i;
    int ret=0;
    Employee* aux;

    if(pArrayListEmployee!= NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        getStringNumeros("Ingrese ID a modificar: ",auxIdStr);
        auxId=atoi(auxIdStr);

        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux= (Employee*) ll_get(pArrayListEmployee,i);

            if(auxId == aux->id)
            {
                int opcion=0;
                do
                {
                    employee_mostrarUno(aux);
                    opcion = getInt("\nMENU MODIFICACION\n1. Nombre\n2. Horas trabajadas\n3. Sueldo\n4. Salir\nIngrese una opcion: ",opcion,1,4);
                    switch(opcion)
                    {
                    case 1:
                        ret = employee_modificarNombre(aux);
                        if(ret==1)
                        {
                            printf("SE MODIFICO EL NOMBRE.\n");
                        }
                        else
                        {
                            printf("NO SE MODIFICO EL NOMBRE.\n");
                        }
                        break;
                    case 2:
                        ret = employee_modificarHoras(aux);
                        if(ret==1)
                        {
                            printf("SE MODIFICARON LAS HORAS.\n");
                        }
                        else
                        {
                            printf("NO SE MODIFICARON LAS HORAS.\n");
                        }
                        break;
                    case 3:
                        ret = employee_ModificarSueldo(aux);
                        if(ret==1)
                        {
                            printf("SE MODIFICO EL SUELDO.\n");
                        }
                        else
                        {
                            printf("NO SE MODIFICO EL SUELDO.\n");
                        }
                        break;
                    case 4:
                        ret=1;
                        break;
                    }
                }while(opcion != 4);
            break;
            }
        }
        if(ret==0)
        {
            printf("No se encontro el ID.\n");
        }
    }
    else
    {
        printf("ERROR.\n");
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxId=0;
    char auxIdStr[100];
    int i;
    int flag =0;
    int flagRemove=0;
    int index=0;
    char conf='.';
    int max= ll_len(pArrayListEmployee);
    Employee* aux;

    controller_ListEmployee(pArrayListEmployee);
    getStringNumeros("Ingrese ID a modificar: ",auxIdStr);
    auxId=atoi(auxIdStr);

    for(i=0;i<max;i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee, i);
        if(auxId == aux->id)
        {
            flag = 1;
            index=i;
            break;
        }
    }
    if(flag)
    {
        employee_mostrarUno(aux);
        conf = getChar("\nDesea dar de baja al empleado? (S/N)?: ",conf);
        while(toupper(conf)!='S' && toupper(conf) != 'N')
        {
            conf = getChar("\nIngrese solo s o n!!: ",conf);
        }
        if(toupper(conf)=='S')
        {
            if(!ll_remove(pArrayListEmployee,index))
            {
                flagRemove=1;
            }
        }else
        {
            printf("Se cancelo la baja.\n");
        }
    }
    return flagRemove;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    Employee* aux;
    int ret = 0;

    if(pArrayListEmployee!= NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux= (Employee*) ll_get(pArrayListEmployee,i);
            employee_mostrarUno(aux);
            ret =1;
        }
    }else
    {
        printf("ERROR.");
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int i,j;
    int tam = ll_len(pArrayListEmployee);

    Employee* emp1=employee_new();
    Employee* emp2=employee_new();

    if(emp1!=NULL && emp2!=NULL && tam>0)
    {
        for (i=0;i<tam-1;i++)
        {
            for (j=i+1;j<tam;j++)
            {
                emp1 = ll_get(pArrayListEmployee,i);
                emp2 = ll_get(pArrayListEmployee,j);
                if (strcmp(emp1->nombre,emp2->nombre)>0 )
                {
                    ll_set(pArrayListEmployee,j, emp1);
                    ll_set(pArrayListEmployee,i, emp2);
                }
            }
        }
        ret=1;
        printf("\nSe ordenaron los empleados por nombre.\n");
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ret =0;
    int i;
    int tam =ll_len(pArrayListEmployee);
    Employee* emp= employee_new();
    if(tam==0)
    {
        printf("No hay datos en la lista.");
    }
    else
    {
        FILE *pFile = fopen(path,"w");
        if(emp!= NULL && pFile != NULL && pArrayListEmployee!= NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
            for(i=0;i<tam;i++)
            {
                emp = ll_get(pArrayListEmployee, i);
                fprintf(pFile,"%d,%s,%d,%d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
            }
            ret=1;
        }
        fclose(pFile);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret =0;
    int i;
    int tam =ll_len(pArrayListEmployee);
    Employee* emp= employee_new();
    if(tam==0)
    {
        printf("No hay datos en la lista.");
    }
    else
    {
        FILE *pFile = fopen(path,"wb");
        if(emp!= NULL && pFile != NULL && pArrayListEmployee!= NULL)
        {
            for(i=0;i<tam;i++)
            {
                emp = ll_get(pArrayListEmployee, i);
                fwrite(emp,sizeof(Employee),1,pFile);
            }
            ret=1;
        }
        fclose(pFile);
    }
    return ret;
}

/** \brief calculates the next available ID
 *
 * \param listEmployee LinkedList* list of employees
 * \return int ID
 *
 */
 int controller_proximoId(LinkedList* pArrayListEmployee)
{
    int tam = ll_len(pArrayListEmployee);
    int auxId=0;
    int i;

    Employee* aux;

    for(i=0;i<tam;i++)
    {
        aux = ll_get(pArrayListEmployee,i);
        if(aux->id >auxId)
        {
            auxId=aux->id;
        }
    }
    return auxId+1;
}
