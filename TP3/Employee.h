#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE 128
#define HORAS 1000000
#define SUELDO 5000000
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*
 * \brief Constructor del espacio de memoria para el empleado
 *
 * \return devuelve un puntero al espacio de memoria que encontro y si no devuelve NULL
 */
Employee* employee_new();

/** \brief Constructor que inicializa las variables que va recibe por parametro
 * de tipo int mayoritariamente
 *
 * \param  id a asignar al empleado
 * \param   nombre a asigna al empleado
 * \param   horasTrabajasad a asignar al empleado
 * \param   sueldo a asigna al empleado
 * \return puntero al empleado generado
 *
 */

Employee* employee_newParametrosInt(int id,char* nombre,int horasTrabajadas, int sueldo);
/** \brief Constructor en formato char que inicializa las variables que va recibe por parametro
 * que son de tipo char mayormente
 *
 * \param  id char a asignar al empleado
 * \param   nombre a asigna al empleado
 * \param   horasTrabajadas char asignar al empleado
 * \param   sueldo char a asigna al empleado
 * \return puntero  al empleado generado
 *
 */
Employee* employee_newParametrosChar(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief libera el espacio de memoria donde se encuentra el empleado que le pasamos
 * \param puntero al empleado que deseamos borrar
 */

void employee_delete(Employee* oneEmployee);
/*
 * \brief copia el valor introducido del id y lo copia al array
 * \param puntero array en el guardamos los ids
 * \param número de id introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
/*
 * \brief recibre el nombre y lo copia al array de nombres
 * \param puntero array en el guardamos los nombres
 * \param nombre introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra el empleado pasado por el puntero a donde se ubicad
 *
 * \param empleado puntero a la direccion del empleado a mostrar
 * \param
 * \return  0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int mostrarEmpleado(Employee* empleado);

/** \brief Genera el proximo id del empleado a partir de la busqueda del ultimo id generado
 * y se lo asgina al nuevo empleado creado
 * \param pArrayListaDeEmpleados puntero a la lista de empleados
 * \param
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int generarIdEmpleado(LinkedList* pArrayListaDeEmpleados);

/** \brief Realiza la busqueda del indice del empleado que deseamos encontrar a partir
 * de pasarle el id como parametro
 * \param pArrayListaDeEmpleados puntero al array de lista de empleados
 * \param IdBuscado id del empleado que deseamos encontrar
 * \return indice del empleado que deseamos encontrar, y si no retorna -1 lo cual indica que no exitste
 *
 */

int employee_buscarPorId(LinkedList* pArrayListaDeEmpleados, int idBuscado);
int employee_ordenarPorId(void*emp1,void* emp2);
int employee_ordenarNombre(void*emp1,void* emp2);
int employee_ordenarHorasTrabajadas(void*emp1,void* emp2);
int employee_ordenarPorSueldo(void*emp1,void* emp2);
#endif // employee_H_INCLUDED
