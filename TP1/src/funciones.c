/*
 * funciones.c
 *
 *  Created on: 29 mar. 2021
 *      Author: Martin
 */


#include <stdio.h>
#include <stdlib.h>

void menu(float A, float B)
{
	printf("\n******** MENU DE OPCIONES ********\n");
	printf("===========================================\n");
	printf("1 Ingresar el primer operando \nA = %.2f\n",A);
	printf("2 Ingresar el segundo operando \nB = %.2f\n",B);
	printf("3 Calcular todas las operaciones\n");
	printf("    a) Calcular la suma (A+B)\n");
	printf("    b) Calcular la resta (A-B)\n");
	printf("    c) Calcular la division (A/B)\n");
	printf("    d) Calcular la multiplicacion (A*B)\n");
	printf("    e) Calcular el factorial (A)\n");
	printf("    f) Calcular el factorial (B)\n");
	printf("4 Mostrar resultados\n");
    printf("5 Salir\n");
    printf("===========================================");
}

int getNumeroEntero(int*pResultado, char* mensaje, char*mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do{

			printf("%s",mensaje);
			scanf("%d", &bufferInt);

			if(bufferInt>=minimo && bufferInt<=maximo && reintentos>0)
			{
				*pResultado = bufferInt;
				retorno = 0;
				return retorno;
			}else
			{
				printf("%s",mensajeError);
				scanf("%d", &bufferInt);
				reintentos--;
			}

		}while(reintentos>0);
	}
	return retorno;
}



int getNumeroCalculadora(float*pResultado, char *mensaje, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	printf("%s",mensaje);
	scanf("%f",&bufferFloat);

	if(bufferFloat>=minimo && bufferFloat<=maximo)
	{
		*pResultado = bufferFloat;
		retorno = 0;
	}

	return retorno;
}


int dividir(float* pResultadoDivision, int dividendo, int divisor)
{
	int retorno = -1;
	if(pResultadoDivision != NULL && divisor != 0)
	{
		*pResultadoDivision = (float)dividendo / divisor ;
		retorno = 0;
	}
	return retorno;
}

int multiplicadorDeOperandos(float multiplicando, float multiplicador)
{
	int resultadoMultiplicacion;
	resultadoMultiplicacion = multiplicando * multiplicador;
	return resultadoMultiplicacion;
}

int restadorDeOperandos(float sustraendo, float minuendo)
{
	float resultadoResta;
	resultadoResta = sustraendo - minuendo;
	return resultadoResta;
}

int sumadorDeOperandos(float sumando1, float sumando2)
{
	float resultadoSuma;
	resultadoSuma = sumando1 + sumando2;
	return resultadoSuma;
}

int funcionFactorial(float numero)
{
	float retornoFactorial = 1;

	for(float factorial = 1 ; factorial<=numero;factorial++)
	{
		retornoFactorial = retornoFactorial * factorial;
	}

	return retornoFactorial;
}

