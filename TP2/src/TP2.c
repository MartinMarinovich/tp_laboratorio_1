/*
 ============================================================================
 Name        : TP2.c
 Author      : Martin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define TAMANIO 1000

int main() {

	setbuf(stdout,NULL);

	Employee EmployeesList[TAMANIO];

	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int opcionesMenu;
	int auxMenu;
	int confirmarBaja;
	int id = 0;
	int idBuscado;
	int auxId;

	initEmployee(EmployeesList,TAMANIO);

	 do{

		 auxMenu = menu(&opcionesMenu);

		 while(auxMenu !=0)
		 {
			 auxMenu = menu(&opcionesMenu);

		 }

		 switch(opcionesMenu)
		 {
		 	 case 1:

		 		 if(cargarDatosEmployee(nombre,apellido,&salario,&sector)==0)
		 		 {
		 			id++;
		 		   addEmployee(EmployeesList,TAMANIO,id,nombre,apellido,salario,sector);
		 		   printf("\nAlta exitosa\n");
		 		   system("pause");

		 		 }else
		 		 {
		 			 printf("\nError el empleado no pudo ser cargado");
		 		 }

		 	 break;
		 	 case 2:
		 		 if(id > 0)
		 		 {
		 			system("cls");
		 			printf("*** BAJAS ***\n");
		 			printf("Ingrese la id del empleado que desea eleminar");
		 			scanf("%d",&idBuscado);
		 			printf("\n EL EMPLEADO A DAR DE BAJA ES EL SIGUIENTE \n");

		 			auxId = findEmployeeById(EmployeesList,TAMANIO,idBuscado);
		 			mostrarUnEmployee(EmployeesList,auxId);

		 			printf("¿DESEA DAR DE BAJA AL EMPLEADO?\n1Si\n2No\n");
		 			scanf("%d",&confirmarBaja);
		 			system("pause");

		 			if(confirmarBaja == 1)
		 			{
		 				removeEmployee(EmployeesList,TAMANIO,auxId);
		 				printf("Usted ha dado de baja al empleado exitosamente\n");
		 				system("pause");

		 			}else
		 			{
		 				printf("\nUsted ha cancelado la baja");
		 			}
		 		 }else
		 		 {
		 			 printf("\nNo es posible realizar la baja ya que no hay ningun empleado");
		 		 }

		 	 break;
		 	 case 3:
		 		 if(id > 0)
		 		 {
		 			 mostrarEmployees(EmployeesList,TAMANIO);
		 			 printf("\nIngrese el id del empleado que desea modificar");
		 			 scanf("%d",&idBuscado);
		 			 auxId = findEmployeeById(EmployeesList,TAMANIO,idBuscado);

		 			 if(modificarEmployee(EmployeesList,TAMANIO,auxId)==0)
		 			 {
		 				 printf("El empleado fue modificado con exito");
		 			 }else
		 			 {
		 				 printf("Error en la modificacion");
		 			 }

		 		 }else
		 		 {
		 			 printf("No hay empleados en la lista");
		 		 }
		 	 break;
		 	 case 4:
		 		 if(id>0)
		 		 {
		 		    mostrarEmployees(EmployeesList,TAMANIO);
		 		    printf("\n");
		 			 system("pause");

		 		 }else
		 		 {
		 			 printf("No hay empleados para informar");
		 		 }
		 	 break;
		 }

	    }while(opcionesMenu != 5);

	return 0;
}
