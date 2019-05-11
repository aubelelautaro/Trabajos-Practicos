#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    int id;
    char apellido[50];
    char nombre[50];
    float salario;
    int sector;
    int estado;

}eEmployee;

#endif // FUNCIONES_H_INCLUDED

/** \brief Se busca el primer indice lbire
 * @param lista el array se pasa como parametro
 * @return el primer indice libre
 */
int obtenerEspacioLibre(eEmployee [], int);

/** \brief Encuentra el indice que coincide con el dni buscado
 * @param lista el array se pasa como parametro
 * @param dni el dni que se va a buscar
 * @param largo (de la lista)
 * @return el indice en donde esta el elemento que coincide con el parametro del dni
 */
int findEmployeeById(eEmployee[], int , int);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee[]
 * \param tam int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployees(eEmployee [], int);

/** \brief Permite dar de baja la persona(todo en 0) ingresando el dni y sabiendo si esta o no validado
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void removeEmployee(eEmployee [], int);

/** \brief Se imprime una lista por orden de nombre
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void imprimirListaOrdPorNombre(eEmployee [], int);

/** \brief Se inicializan todos los estados en 0 antes de cargar algun dato
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(eEmployee [], int);

/** \brief print the content of employees array
 *
 * \param list Employee[]
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee[], int);


/** \brief Pide un caracter
 * \param char mensaje a mostrar
 * \param char caracter que se ingresa
 * \return Devuelve el char ingresado
 */

char getChar(char [],char );

/** \brief Pide un caracter
 * \param char mensaje a mostrar
 * \param char caracter que se ingresa
 * \param char caracter minimo
 * \param char caracter maximo
 * \return Devuelve el char ingresado
 */

char getOpcion(char [],char ,char , char );

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char [],char []);

/** \brief Verifica si el valor recibido es un salario (float)
 * \param str Array a ser analizado
 * \return 1 si contiene un flotante y 0 si no
 */

int esSalario(char []);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene solo numeros
 */

int getStringNumeros(char [],char []);

void sortEmployeeByName(eEmployee [], int );


void mostrarTotalPromedioySuperanPromedio(eEmployee[], int );

int eEmployee_nextId(eEmployee [],int );
