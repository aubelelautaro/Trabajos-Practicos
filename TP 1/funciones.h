#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief Pide un entero
 * \param char mensaje a mostrar
 * \param int numero que se ingresa
 * \return Devuelve el numero ingresado
 */

int getInt(char[],int);

//OPERACIONES
/** \brief int Suma los numeros
 *  \param int primer numero
 *  \param int segundo numero
 *  \return suma de los numeros
 */
int sumar (int,int);

/** \brief int Resta los numeros
 *  \param int primer numero
 *  \param int segundo numero
 *  \return resta de los numeros
 */
int restar (int,int);

/** \brief int Multiplica los numeros
 *  \param int multiplicando
 *  \param int multiplicador
 *  \return producto
 */
int multiplicar (int,int);

/** \brief float divide los numeros ingresados
 *  \param int dividendo
 *  \param int divisor
 *  \return cociente
 */
float dividir (int,int);

/** \brief long Pide un numero para factorearlo
 *  \param int Factorea el numero ingresado
 *  \return numero factoreado
 */
long factorial (int);

#endif // FUNCIONES_H_INCLUDED
