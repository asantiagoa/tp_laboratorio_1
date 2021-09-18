#ifndef LIBCALC_H
#define LIBCALC_H






/**
 * \brief Calcula la suma entre dos flotantes
 * \param x guarda el primer operando ingresado por el usuario
 * \param y guarda el segundo operando ingresado por el usuario
 * \return return devuelve el resultado de la suma entre los dos numeros
 */
float calcSum(float x, float y);



/**
 * \brief Calcula la resta entre dos flotantes
 * \param x guarda el primer operando ingresado por el usuario
 * \param y guarda el segundo operando ingresado por el usuario
 * \return return devuelve el resultado de la resta entre los dos numeros
 *
 */
float calcRes(float x, float y);



/**
 * \brief Calcula la division entre dos flotantes
 * \param x guarda el primer operando ingresado por el usuario
 * \param y guarda el segundo operando ingresado por el usuario
 * \return return devuelve el cociente de la division entre los dos numeros
 *
 */
float calcDiv(float x, float y);



 /**
 * \brief Calcula la multiplicacion entre dos flotantes
 * \param x guarda el primer operando ingresado por el usuario
 * \param y guarda el segundo operando ingresado por el usuario
 * \return return devuelve el producto de la multiplicacion entre los dos numeros
 *
 */
float calcMult(float x, float y);



/**
 * \brief Calcula el factorial de un numero
 * \param x guarda el numero ingresado por el usuario
 * \return return devuelve el factorial del numero ingresado como un entero
 *
 */
int calcFact(float x);

#endif // LIBCALC_H
