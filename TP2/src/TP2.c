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
#include "utn.h"

#define TAMANIO 1000
#define NOMBRE 51
#define APELLIDO 51
#define CRITERIO1 0
#define CRITERIO2 1

int main() {

	setbuf(stdout,NULL);

	Employee EmployeesList[TAMANIO];

	char nombre[NOMBRE];
	char apellido[APELLIDO];
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

		 		 if(cargarDatosEmployee(nombre,apellido,&salario,&sector,NOMBRE,APELLIDO))
		 		 {
		 			id++;
		 		   addEmployee(EmployeesList,TAMANIO,id,nombre,apellido,salario,sector);
		 		   printf("\nAlta exitosa\n");
		 		   system("pause");

		 		 }else
		 		 {
		 			 printf("\nError el empleado no pudo ser cargado");
		 		 }
		 		 system("pause");
		 	 break;
		 	 case 2:
		 		 if(verificarExistencia(EmployeesList,TAMANIO))
		 		 {

		 			mostrarEmployees(EmployeesList, TAMANIO);

		 			if(utn_getNumero(&auxId,"Ingrese el ID del empleado\n","Error, ID inexistente\n",1, 1000, 3))
		 			{

		 				if(removeEmployee(EmployeesList, TAMANIO, auxId))
		 				{
		 					printf("Baja exitosa!\n");
		 				}else
		 				{
		 					printf("ID inexistente\n");
		 				}
		 			}

		 		 }else
		 		 {
		 			 printf("No es posible realizar  bajas ya que no hay ningun empleado\n");
		 		 }
		 		system("pause");
		 	 break;
		 	 case 3:
		 		 if(verificarExistencia(EmployeesList,TAMANIO))
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
		 		system("pause");
		 	 break;
		 	 case 4:
		 		 if(verificarExistencia(EmployeesList,TAMANIO))
		 		 {
		 		    mostrarEmployees(EmployeesList,TAMANIO);
		 		    printf("\n");
		 			 system("pause");

		 		 }else
		 		 {
		 			 printf("No hay empleados para informar");
		 		 }

		 		system("pause");
		 	 break;
		 }

	    }while(opcionesMenu != 5);

	return 0;
}
