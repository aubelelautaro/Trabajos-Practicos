#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;
    int retorno=0;
    char auxId[20];
    char auxNombre[128];
    char auxHoras[20];
    char auxSueldo[20];

    if((pFile=fopen("data.csv","r"))!=NULL && pArrayListEmployee!= NULL)
    {
        ll_clear(pArrayListEmployee);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);//Elimina la primer linea no deseada
        while(!feof(pFile))
            {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
            if(cant ==4)
            {
                Employee* aux=employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
                ll_add(pArrayListEmployee,aux);
                retorno =1;
            }
            else if(cant!=4)
            {
                if(feof(pFile))
                    break;
                else
                {
                    printf("No leyo el ultimo registro");
                    retorno=0;
                    break;
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;
    int retorno=0;
    Employee* aux;

    if((pFile=fopen("data.bin","rb"))!=NULL && pArrayListEmployee!= NULL)
    {
        ll_clear(pArrayListEmployee);
        while(!feof(pFile))
            {
            aux=employee_new();
            cant = fread(aux,sizeof(Employee),1,pFile);

            if(aux!=NULL && cant ==1)
            {
                ll_add(pArrayListEmployee,aux);
                retorno =1;
            }
            else if(cant!=1)
            {
                if(feof(pFile))
                    break;
                else
                {
                    printf("No leyo el ultimo registro");
                    retorno=0;
                    break;
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}
