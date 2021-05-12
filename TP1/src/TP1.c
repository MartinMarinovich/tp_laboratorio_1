/*
 ============================================================================
 Name        : TP1.c
 Author      : Martin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);

		float A = 0;
		float B = 0;
		float suma;
		float resta;
		float multiplicacion;
		int division;
		float resultadoDivision;
		float factorialA;
		float factorialB;
		int respuestaA;
		int respuestaB;
		int opcionMenu = -1;
		int flagCalculo = 1;
		int flagMostrar = 1;

		do {
			 menu(A,B);

			getNumeroEntero(&opcionMenu,"\nIngrese la opcion deseada\n","\nError numero incorrecto\n",1,5,3);

			if(opcionMenu == -1)
			{
				printf("\nError, supero la cantidad de intentos");
				break;
			}else
			{
				switch(opcionMenu)
				{
					case 1:
					respuestaA = getNumeroCalculadora(&A,"Ingrese el primer operando\n",-999999,999999);



					if(!respuestaA)
					{
						printf("Usted ingreso el primer operando correctamente\n\n");

					}else
					{
						printf("Vuelva a ingresar el primer operador\n");
					}

					break;

					case 2:
					if(!respuestaA)
					{
						respuestaB = getNumeroCalculadora(&B,"Ingrese el segundo operando\n",-999999,999999);

						if(!respuestaB)
						{
							flagCalculo = 0;
							printf("Usted ingreso ambos operadores correctamente\n\n");
						}
					}else
					{
						printf("Para ingresar el operador B, debe ingresar primero el operador A\n\n");
					}

					break;

					case 3:
					if(flagCalculo)
					{
						printf("Debe ingresar ambos operandos para realizar los calculos\n");
					}else
					{
						printf("Se ha calculado correctamente\n");
						flagMostrar = 0;
						resta = restadorDeOperandos(A,B);
						multiplicacion = multiplicadorDeOperandos(A,B);
						division = dividir(&resultadoDivision,A,B);
						suma = sumadorDeOperandos(A,B);

						if(A>=0)
						{
							factorialA = funcionFactorial(A);

						}else
						{
							factorialA = -1;
						}

						if(B>=0)
						{
							factorialB = funcionFactorial(B);
						}else
						{
							factorialB = -1;
						}
					}
					system("pause");
					break;

					case 4:

					if(!flagMostrar)
					{
						printf("\nEl resultado de la resta de A - B es: %.2f\n",resta);
						printf("El resultado de la suma de A + B es: %.2f\n",suma);
						printf("El resultado de la multiplicacion de A * B es: %.2f\n",multiplicacion);

						if(!division)
						{
							printf("El resultado de la division de A / B es: %.2f\n",resultadoDivision);
						}else
						{
						    	printf("Error, no se puede dividir por 0\n");
						}

						if(factorialA>=1 )
						{
							printf("El factorial de A es: %.2f\n",factorialA);
						}else
						{
							printf("Error, no se pudo realizar el factorial de A con el numero ingresado \n");
						}

						if(factorialB>=1 )
						{
							printf("El factorial de B es: %.2f\n",factorialB);
						}else
						{
							printf("Error, no se pudo realizar el factorial de B con el numero ingresado\n");
						}
					}else
					{
						printf("No puede mostrar los resultados sin haber calculado\n");
					}
					system("pause");
					break;

				}

			}

		}while(opcionMenu != 5);
}
