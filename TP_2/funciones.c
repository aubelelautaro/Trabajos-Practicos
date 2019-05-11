#include "funciones.h"
#include <stdio.h>
#include <string.h>

int initEmployees(eEmployee lista[], int tam)
{
    int i;
    int flag=-1;

    for(i=0;i<tam;i++)
    {
        lista[i].estado=0;
        strcpy(lista[i].nombre,"");
        strcpy(lista[i].apellido,"");
        lista[i].salario=0;
        lista[i].id=0;
        lista[i].sector=0;
        flag =0;
    }
    return flag;
}

int addEmployees(eEmployee lista[], int tam)
{
    int lugarLibre,sector;
    float salario=0;
    int flag=-1;
    int id,validar;
    char auxNombre[51];
    char auxSalario[20];
    char auxApellido[51];
    char auxSector[4];

    lugarLibre=obtenerEspacioLibre(lista, tam);

    if(lugarLibre!=-1)
    {
        id = eEmployee_nextId(lista,tam);
        printf("\nID de empleado: %d", id);

        validar = getStringLetras("Ingrese nombre: ",auxNombre);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
        }
        strcpy(lista[lugarLibre].nombre,auxNombre);

        validar = getStringLetras("Ingrese apellido: ",auxApellido);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
        }
        strcpy(lista[lugarLibre].apellido,auxApellido);

        printf("Ingrese salario: ");
        fflush(stdin);
        scanf("%s",auxSalario);
        fflush(stdin);

        while(!esSalario(auxSalario))
        {
            printf("Ingrese salario correcto: ");
            fflush(stdin);
            scanf("%s",auxSalario);
            fflush(stdin);
        }
        salario = atol(auxSalario);

        lista[lugarLibre].salario = salario;
        getStringNumeros("Ingrese sector: ",auxSector);
        while(!esSalario(auxSector))
        {
            getStringNumeros("Ingrese sector valido: ",auxSector);
        }
        sector = atoi(auxSector);
        lista[lugarLibre].sector = sector;
        lista[lugarLibre].id= id;
        lista[lugarLibre].estado=1;
        id++;
    }
    else
    {
        printf("No se puede agregar mas personas.\n");
    }
    return flag;
}

int obtenerEspacioLibre(eEmployee lista[], int tam)
{
    int i;
    int lugarLibre=-1;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}

void removeEmployee(eEmployee lista[], int tam)
{
    int id;
    int index;
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
             printf("ID: %d  -  Nombre: %s - Apellido: %s  - Salario: %.2f  - Sector: %d\n",lista[i].id, lista[i].nombre, lista[i].apellido,lista[i].salario,lista[i].sector);
        }
    }
    if(lista[i].estado==0)
    {
        printf("No hay personas cargadas en el sistema\n");
    }
    else
    {
        printf("Ingrese id a dar de baja: ");
        scanf("%d",&id);
        index = findEmployeeById(lista, id,tam);
    }
    if(index!=-1)
    {
        lista[index].estado=0;
        strcpy(lista[index].nombre,"");
        strcpy(lista[index].apellido,"");
        lista[index].sector=0;
        lista[index].id=0;
        lista[index].salario = 0;
    }
    else
        printf("La persona seleccionada no esta registrada\n");
}

int findEmployeeById(eEmployee lista[], int id, int tam)
{
    int i;
    int index=-1;

    for(i=0;i<tam;i++)
    {
        if(id==lista[i].id)
        {
            index=i;
            break;
        }
        else if(i==tam-1)
        {
            printf("El ID ingresado no esta en la lista. ");
        }
    }

    return index;
}

void sortEmployeeByName(eEmployee lista[], int tam)
{
   int i,j;
   int contAct=0;
   eEmployee aux;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            contAct++;
        }
    }
    for(i=0;i<contAct-1;i++)
    {

        for(j=i+1;j<contAct;j++)
        {
            if(strcmp(lista[j].apellido,lista[i].apellido)>0)
            {
                aux = lista[j];
                lista[j]= lista[i];
                lista[i]= aux;
            }
            else if(strcmp(lista[i].apellido,lista[j].apellido) == 0)
            {
                if(lista[i].sector > lista[j].sector )
                {
                    aux = lista[j];
                    lista[j]= lista[i];
                    lista[i]= aux;
                }
            }
        }
    }

    for(i=0;i<contAct;i++)
    {
        printf("ID: %d Nombre: %s Apellido: %s Salario: %f  Sector: %d\n", lista[i].id, lista[i].nombre, lista[i].apellido,lista[i].salario,lista[i].sector);
    }
}

void mostrarTotalPromedioySuperanPromedio(eEmployee lista[], int tam)
{
    int i,j, salarioCant, salarioAcum=0,superanSalario=0;
    float promedio=-1;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            salarioCant+=lista[i].salario;
            salarioAcum++;
        }
    }
    promedio=salarioCant/salarioAcum;

    for(j=0;j<tam;j++)
    {
        if(lista[j].salario>promedio)
        {
            superanSalario++;
        }
    }

    printf("TOTAL DE SALARIOS: %d  PROMEDIO DE SALARIOS: %f SUPERAN EL PROMEDIO %d SALARIOS",salarioAcum,promedio,superanSalario);

}

int printEmployees(eEmployee lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado ==1)
        {
            printf("ID: %d Nombre: %s Apellido: %s Salario: %f  Sector: %d\n", lista[i].id, lista[i].nombre, lista[i].apellido,lista[i].salario,lista[i].sector);
        }
    }
    return 0;
}

char getChar(char mensaje[],char caracter)
{
    printf("%s", mensaje);
    fflush(stdin);
    caracter = getch();

    return caracter;
}

char getOpcion(char mensaje[],char caracter,char minimo, char maximo)
{
    printf("%s", mensaje);
    fflush(stdin);
    caracter = getch();
    while(caracter < minimo && caracter > maximo)
    {
        printf("\nIngrese una opcion correcta entre %c y %c:",minimo,maximo);
        caracter = getch();
        fflush(stdin);
    }

    return caracter;
}

int eEmployee_nextId(eEmployee empleado[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(empleado[i].id>retorno)
        {
            retorno=empleado[i].id;
        }
    }
    return retorno+1;
}

void getString(char mensaje[], char cadena[])
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
    fflush(stdin);
}

int esSoloLetras(char str[])
{
    int i=0;
    int flag = 1;

    for(i=0;i<strlen(str);i++)
    {
        if((str[i] != ' ') && !(isalpha(str[i])))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int getStringLetras(char mensaje[],char cadena[])
{
    char aux[256];
    int flag =0;
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(cadena,aux);
        flag=1;
    }
    return flag;
}

int esSalario(char str[])
 {
   int i = 0;
   int flag = 1;
   int cantComas = 0;
   for(i=0;i<strlen(str);i++)
   {
       if (str[i] =='.' && cantComas ==0)
       {
           cantComas++;
           continue;
       }
       if(str[i] <'0' || str[i] >'9')
       {
           flag = 0;
           break;
       }
       if(cantComas > 1)
       {
           flag =0;
           break;
       }
   }
   return flag;
}

int esNumerico(char str[])
{
    int i=0;
    int flag = 1;

    for(i=0;i<strlen(str);i++)
    {
        if(!(isdigit(str[i])))
        {
            flag = 0;
            printf("Error! Ingrese solo numeros\n");
            break;
        }
    }
    return flag;
}

int getStringNumeros(char mensaje[],char cadena[])
{
    char aux[256];
    int flag =0;
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(cadena,aux);
        flag=1;
    }
    return flag;
}

int menu()
{
    char opcion= '0';
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n");

    opcion = getOpcion("\nIngrese opcion entre 1 y 5: ", opcion,'1','5');
    return opcion;
}

int eEmployee_menuModificacion()
{
    char opcion = '0';

    printf("\n----Modificacion----\n");
    printf("1.Nombre\n");
    printf("2.Apellido\n");
    printf("3.Salario\n");
    printf("4.Sector\n");
    printf("5.Cancelar\n");

    opcion = getOpcion("\nIngrese opcion entre 1 y 5: ", opcion,'1','5');
    return opcion;
}

void eEmployee_modificarCampo(eEmployee empleados[], int tam)
{
    int id,sector;
    int index;
    int validar;
    float salario;
    char auxApellido[51];
    char auxNombre[51];
    char auxSalario[16];
    char auxSector[31];
    int retorno = printEmployees(empleados,tam);
    char confirma='N';
    if(retorno==0)
    {
        printf("NO HAY EMPLEADOS");
    }else
    {
        printf("Ingrese id del empleado a modificar: ");
        scanf("%d",&id);
        index = findEmployeeById(empleados,tam,id);
        if(index==-1)
        {
            printf("No se encontro el empleado\n");
        }else{
            do{
                switch(eEmployee_menuModificacion())
                {
                case '1':
                    printf("El apellido actual es: %s\n",empleados[index].apellido);
                    validar = getStringLetras("Ingrese nuevo apellido: ",auxApellido);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(empleados[index].apellido,auxApellido);
                    }
                    system("pause");
                    break;

                case '2':
                    printf("El nombre actual es: %s\n",empleados[index].nombre);
                    validar = getStringLetras("Ingrese nuevo nombre: ",auxNombre);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(empleados[index].nombre,auxNombre);
                    }
                    system("pause");
                    break;
                case '3':
                    printf("El salario actual es: %f\n",empleados[index].salario);
                    printf("Ingrese nuevo salario: ");
                    scanf("%s",auxSalario);

                    while(!esSalario(auxSalario))
                    {
                        printf("Ingrese salario valido: ");
                        scanf("%s",auxSalario);
                    }
                    salario = atol(auxSalario);

                    confirma = getChar("\nSeguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("Error, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        empleados[index].salario = salario;
                    }
                    system("pause");
                    break;

                case '4':
                    printf("El sector actual es: %d\n",empleados[index].sector);
                    validar = getStringNumeros("Ingrese nuevo sector: ",auxSector);
                    while(validar == 0)
                    {
                        validar = getStringNumeros("ERROR, ingrese sector valido: ",auxSector);
                    }
                    sector= atol(auxSector);

                    confirma = getChar("Seguro quiere modificarlo? (N/S): ", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        empleados[index].sector = sector;
                    }
                    system("pause");
                    break;
                case '5':
                    confirma = getChar("Seguro quiere salir? (N/S): ", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        confirma = 'N';
                    }
                    break;

                default:
                    printf("Ingrese opcion correcta \n");
                    system("pause");
                }
            }while (confirma == 'S');
        }
    }
}
