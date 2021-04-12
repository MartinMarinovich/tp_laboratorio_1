/*
 * funciones.h
 *
 *  Created on: 29 mar. 2021
 *      Author: Martin
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @brief  La funcion dividir recibe 2 dos valores, el dividendo y el divisor, valida que se el divisor no sea 0 y que el *pResultado no sea NULL
 * /si el numero es valido se realiza la division y se pasa a traves del puntero retorna un valor si se realizo correctamente.
 *
 * @param pResultado Puntero de renferncia, la direccion de memoria donde se guardara el valor del resultado de la division
 * @param dividendo Operador Ade tipo int ingresado por el usuario para calcular luego se castea a float
 * @param divisor Operador B de tipo int ingresado por el usuario, se valida que no sea 0
 * @return RETORNA -1 SI SALIO MAL O 0 SI SE REALIZO CORRECTAMENTE
 */

int dividir(float* pResultadoDivision, int dividendo, int divisor);

/***
 * @brief La funcion multiplicadorDeOperandos recibe dos valores de tipo float, realiza la multiplicacion y devuelve el resultado a traves del return
 * @param multiplicando Operador A de tipo float implicado en la operacion
 * @param multiplicador Operador B de tiplo float implicado en la operacion
 * @return Retorna el resultado de la multiplicacion de A * B
 */

int multiplicadorDeOperandos(float multiplicando, float multiplicador);

/**
 * @brief La funcion sumadorDeOperandos recibe dos valores de tipo float, realiza la suma y  devuelve el resultado a traves del return
 * @param sumando1 Operador A de tipo float ingresado por el usuario que se utiliza para realizar el calculo
 * @param sumando2 Operador B de tipo float ingresado por el usuario que se utiliza para  realizar el calculo
 * @return Retorna el resultado de la suma de A + B
 */

int sumadorDeOperandos(float sumando1, float sumando2);
/**
 * @brief La funcion restadorDeOperandos recibe dos valores de tipo float, realiza la resta y  devuelve el resultado a traves del return
 * @param sustraendo Operador A de tipo float ingresado por el usuario que se utililiza para realizar el calculo
 * @param minuendo Operador B de tipo float ingresado por el usuario que se utililiza para realizar el calculo
 * @return Retorna el resultado de la resta de A - B
 */
int restadorDeOperandos(float sustraendo, float minuendo);
/**
 * @brief La funcion funcionFactorial recibe un numero como parametro para realizar la operacion factorial
 * @param La operador ingresado por el usuario al cual se le realiza el factoreo
 * @return Devuelve el resultado de la operacion factoreo
 */
int funcionFactorial(float numero);
/**
 * @brief La funcion getNumeroEntero se compone de,*pResultado el puntero donde se guarda el numero ingresado validado/
 * *charMensaje error es el puntero del mensaje de error en caso de ingresar un numero invalido, *mesaje es el puntero del mensaje
 * que solicita el ingreso del numero,  minimo es el parametro del numero "minimo" que se puede ingresar
 * "maximo" es el parametro del mayor numero posible a ingresar, "reintentos" es la cantidad de reintentos que se permiten
 *
 * @param pResultado  Puntero donde se guarda el numero valido que ingresa el usuario
 * @param mensajeError Puntero del mensaje de error en caso de ingresar un numero invalido
 * @param mensaje	Puntero del mensaje que informa al usuario que debe ingresar un numero
 * @param minimo	Parametro que indica el numero minimo que es posible ingresar
 * @param maximo	Parametro que indica el numero maximo que es posible ingresar
 * @param reintentos Parametro de la cantidad de reintentos que se permite realizar
 * @return Retorna 0 si la operacion de obtener el numero entero se realizo correctamente  O -1 en caso de error ingreso un numero invalido
 */
int getNumeroEntero(int*pResultado, char*mensajeError ,char* mensaje, int minimo, int maximo, int reintentos);

/**
 * @brief La funcion getNumeroCalculadora se compone de *pResultado puntero tipo float en el cual se guardara el numero resultado de la funcion
 * *mensaje es el puntero del mensaje que le mostramos al usuario para que ingrese el numero, minimo es el parametro de tipo float que marca el numero
 * minimo posible de ingresar, maximo es el parametro de tipo float que indica el numero maximo que podemos ingresar
 * @param pResultado Puntero del espacio de memoria donde se almacena el numnero elegido
 * @param mensaje Puntero del espacio donde esta el mensaje que solicita al usuario que ingrese un numero
 * @param minimo Parametro que indica el numero menor que es posible ingresar
 * @param maximo Parametro que indica el numero mayor que es posible ingresar
 * @return Retorna 0 si la operacion se realizo correctamente o -1 si se introdujo un valor invalido
 */

int getNumeroCalculadora(float*pResultado, char *mensaje, float minimo, float maximo);

void menu(float A, float B);

#endif /* FUNCIONES_H_ */
