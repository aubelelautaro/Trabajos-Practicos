#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "funciones.h"
#include <ctype.h>

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    int flag =0;

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = atoi(idStr);
        strcpy(nuevoEmpleado->nombre, nombreStr);
        nuevoEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
        if(employee_setId(nuevoEmpleado, atoi(idStr)) == 1){
            if(employee_setNombre(nuevoEmpleado, nombreStr)== 1){
                if(employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))== 1){
                    if(employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))== 1)
                    {
                        flag = 1;
                    }
                }
            }
        }
        if(flag == 0)
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

int employee_setId(Employee* this,int id)
{
    int flag = 0;

    if(this != NULL && id >0)
    {
        this->id = id;
        flag =1;
    }

    return flag;
}
int employee_getId(Employee* this,int* id)
{
    int flag = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag = 1;
    }

    return flag;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int flag = 0;

    if(this != NULL && sueldo >0 && sueldo <  100000)
    {
        this->sueldo = sueldo;
        flag =1;
    }

    return flag;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int flag = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        flag = 1;
    }

    return flag;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int flag = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        flag =1;
    }

    return flag;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int flag = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(*nombre,this->nombre);
        flag = 1;
    }

    return flag;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int flag = 0;

    if(this != NULL && horasTrabajadas >0)
    {
        this->horasTrabajadas = horasTrabajadas;
        flag =1;
    }

    return flag;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int flag = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        flag = 1;
    }

    return flag;
}

void employee_delete()
{

}

void employee_mostrarUno(Employee* this)
{
    printf("%d    %s     %d   %d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
}

int employee_modificarNombre(Employee* this)
{
    char auxNombre[128];
    char conf='.';
    int flag=0;
    printf("MODIFICAR NOMBRE\n");
    employee_mostrarUno(this);

    getStringLetras("\nIngrese el nuevo nombre: ",auxNombre);
    conf = getChar("\nDesea modificar el nombre (S/N)?: ",conf);
    while(toupper(conf)!='S' && toupper(conf) != 'N')
    {
        conf = getChar("\nIngrese solo s o n!!: ",conf);
    }
    if(toupper(conf)=='S')
    {
       strcpy(this->nombre, auxNombre);
       flag=1;
    }
    else
    {
        printf("Se canceló la modifiacion del nombre.");
        flag=0;
    }
    return flag;
}

int employee_modificarHoras(Employee* this)
{
    char auxHorasStr[20];
    int auxHoras;
    char conf='.';
    int flag=0;

    printf("MODIFICAR HORAS TRABAJADAS\n");

    employee_mostrarUno(this);
    getStringNumeros("\nIngrese las nuevas horas: ",auxHorasStr);
    conf = getChar("\nDesea modificar el horas (S/N)?: ",conf);
    while(toupper(conf)!='S' && toupper(conf) != 'N')
    {
        conf = getChar("\nIngrese solo s o n!!: ",conf);
    }
    if(toupper(conf)=='S')
    {
        auxHoras = atoi(auxHorasStr);
        this->horasTrabajadas = auxHoras;
        flag=1;
    }
    else
    {
        printf("Se canceló la modificacion de las horas.");
        flag=0;
    }
    return flag;
}

int employee_ModificarSueldo(Employee* this)
{
    char auxSueldoStr[20];
    int auxSueldo;
    char conf='.';
    int flag=0;

    printf("MODIFICAR SUELDO\n");

    employee_mostrarUno(this);
    getStringNumeros("\nIngrese el nuevo sueldo: ",auxSueldoStr);
    conf = getChar("\nDesea modificar el sueldo (S/N)?: ",conf);
    while(toupper(conf)!='S' && toupper(conf) != 'N')
    {
        conf = getChar("\nIngrese solo s o n!!: ",conf);
    }
    if(toupper(conf)=='S')
    {
        auxSueldo = atoi(auxSueldoStr);
        this->sueldo = auxSueldo;
        flag=1;
    }
    else
    {
        printf("Se canceló la modificacion del sueldo.");
        flag=0;
    }
    return flag;
}
