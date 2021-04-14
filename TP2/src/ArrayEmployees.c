/*
 * ArrayEmployees.c
 *
 *  Created on: 11 abr. 2021
 *      Author: Martin
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"

int menu(int *opcionMenu)
{
	int opcion;
	int retornoError = 0;
	system("cls");

	printf("\n*** MENU DE OPCIONES ***\n\n");
	printf("-----------------------------------\n");
	printf("   Ingrese opcion: \n");
	printf("   1 ALTA \n");
	printf("   2 BAJA \n");
	printf("   3 MODIFICAR \n");
	printf("   4 INFORMAR\n");
	printf("   5 SALIR\n");
	printf("-----------------------------------\n");
	scanf("%d",&opcion);

	if(opcion<1 && opcion>5)
	{
		retornoError = -1;
	}else
	{
		*opcionMenu = opcion;
	}

	return retornoError;
}

int initEmployee(Employee* list, int lenght)
{
	int retornoError = -1;

	if(list != NULL && lenght>0)
	{
		for(int i = 0; i<lenght; i++)
		{
			list[i].isEmpty = 1;
		}
		retornoError = 0;
	}

	return retornoError;
}

int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector)
{

    int retornoError = -1;
    int indice;

    if(list!= NULL && lenght > 0 && id > 0 && name != NULL && lastName !=NULL)
    {
        indice = buscarLibre(list, lenght);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
          list[indice].id = id;
          strcpy(list[indice].name,name);
          strcpy(list[indice].lastName,lastName);
          list[indice].salary = salary;
          list[indice].sector = sector;
          list[indice].isEmpty = 0;
          retornoError = 0;
        }
    }

    return retornoError;
}

int mostrarUnEmployee(Employee* lista, int indice)
{
	int retornoError = 0;

	if(lista !=NULL && indice > -1)
	{
		printf("%4d  %10s  %10s  %.2f  %d\n",lista[indice].id,lista[indice].name,lista[indice].lastName,lista[indice].salary,lista[indice].sector);
		retornoError = 0;
	}

	return retornoError;
}

int mostrarEmployees(Employee* lista, int tamanio)
{
	int retornoError = -1;

	printf(" Id  Nombre  Apellido  Salario  Sector\n");
	printf("---------------------------------------\n");
	if(lista != NULL && tamanio>0)
	{
		for(int i = 0; i<tamanio; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarUnEmployee(lista,i);
			}
		}

		retornoError = 0;
	}
	return retornoError;
}

int cargarDatosEmployee(char* nombre, char *apellido, float *salario, int *sector)
{
	int retornoError = -1;
	char auxiliarDeChar[500];

	if(nombre != NULL && apellido != NULL && salario != NULL && sector != NULL)
	{
		printf("Ingrese el nombre del empleado: ");
		fflush(stdin);
		gets(auxiliarDeChar);

		while(strlen(auxiliarDeChar)>51)
		{
			printf("El nombre esta fuera del parametro, ingreselo nuevamente");
			fflush(stdin);
			gets(auxiliarDeChar);
		}

		strcpy(nombre,auxiliarDeChar);

		printf("Ingrese el apellido del empleado: ");
		fflush(stdin);
		gets(auxiliarDeChar);

		while(strlen(auxiliarDeChar)>51)
		{
			printf("El apellido esta fuera del parametro, ingreselo nuevamente");
			fflush(stdin);
			gets(auxiliarDeChar);
		}

		strcpy(apellido,auxiliarDeChar);

		printf("Ingrese el sector al que pertenece: ");
		scanf("%d", sector);

		while(sector<0)
		{
			printf("El sector se encuentra fuera del rango, ingreselo nuevamente");
			scanf("%d", sector);
		}

		printf("Ingrese el salario del empleado: ");
		scanf("%f",salario);

		while(salario<=0)
		{
			printf("El monto ingresado es inexistente, ingreselo nuevamente: ");
			scanf("%f", salario);
		}

		retornoError = 0;
	}
	return retornoError;
}

int modificarEmployee(Employee* lista, int tamanio, int indice)
{
	int retornoError = -1;
	int opcionMenu;

	if(lista != NULL && tamanio > 0 && indice > -1)
	{
		do{
			printf("\n**** MODIFICAR DATOS EMPLEADO ***\n1->Nombre\n2->Apellido\n3->Salario\n4->Sector\n5->Salir");
			scanf("%d",&opcionMenu);

			switch(opcionMenu)
			{
			   case 1:
				   printf("Ingrese el nombre: ");
				   fflush(stdin);
				   gets(lista[indice].name);
				   retornoError = 0;
			   break;
			   case 2:
				   printf("Ingrese el apellido: ");
				   fflush(stdin);
				   gets(lista[indice].lastName);
			   break;
			   case 3:
				   printf("Ingrese el salario: ");
				   scanf("%f",&lista[indice].salary);
				   retornoError = 0;
			   break;
			   case 4:
				   printf("Ingrese el sector");
				   scanf("%d",&lista[indice].sector);
				   retornoError = 0;
			   break;
			   case 5:
			   break;
			}
		}while(opcionMenu != 5);
	}
	return retornoError;
}

int removeEmployee(Employee* list, int lenght, int id)
{
	int retornoError = -1;
	int indice = 0;

	if(list != NULL && lenght>0 && id>0)
	{
		indice = findEmployeeById(list,lenght,id);
		if(indice!= -1)
		{
			list[indice].isEmpty = 1;
		}
		retornoError = 0;
	}
	return retornoError;
}

int buscarLibre(Employee* lista, int lenght)
{
	int indice = -1;

	for(int i = 0; i<lenght; i++)
	{
		if(lista[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int findEmployeeById(Employee* list, int lenght, int id)
{
	int indice = -1;

	if(list !=NULL && lenght >0 && id<lenght && id>=0)
	{
		for(int i = 0; i<lenght; i++)
		{
			if((list[i].id == id) && (list[i].isEmpty == 0))
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
