/*
 * utn.h
 *
 *  Created on: 17 abr. 2021
 *      Author: Martin
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos);
int utn_getCadena(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int esNombreValido(char* cadena, int len);

#endif /* UTN_H_ */
