#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX_EMPLEADOS 1000

static int nextId();
static int findFreePlaces(Employee* list,int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
  int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;
}

static int findFreePlaces(Employee* list,int len)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = -2;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int nextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free */

int addEmployee(Employee* list, int len)
{
    int retorno = -1;
    char Auxname[51];
    char AuxlastName[51];
    float Auxsalary;
    int Auxsector;
    int Auxid;
    int index;

    index = findFreePlaces(list,len);

    if(len > 0 && list != NULL)
    {
        retorno = -2;

        if(index >= 0)
        {
            Auxid = nextId();
            retorno = -3;

            if(!getValidString("Nombre?\n","Error, ingrese su nombre nuevamente\n","Overflow", Auxname,51,2))
            {
                if(!getValidString("Apellido?\n","Error, ingrese su apellido nuevamente\n","Overflow", AuxlastName,51,2))
                {
                    if(!getValidFloat("Ingrese su salario:\n","Error, salario no valido\n",&Auxsalary,0,200000,2))
                    {
                        if(!getValidInt("Ingrese su sector\n","Error, sector no valido\n",&Auxsector,0,1000,2))
                        {
                                retorno = 0;

                                strncpy(list[index].name,AuxlastName,51);
                                strncpy(list[index].lastName,AuxlastName,51);
                                list[index].salary = Auxsalary;
                                list[index].sector = Auxsector;

                                list[index].id = Auxid;
                                list[index].isEmpty = 0;

                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int modifyEmployees(Employee* list,int len, int id)
{
    int retorno = -1;
    int index;
    char Auxname[51];
    char AuxlastName[51];
    float Auxsalary;
    int Auxsector;

    index = findEmployeeById(list,len,id);
    if(index >= 0)
    {
        retorno = -2;

        if(!getValidString("Nombre del empleado nuevo?\n","Error, ingrese su nuevo nombre nuevamente\n","Overflow", Auxname,51,2))
            {
                 if(!getValidString("Apellido del empleado nuevo?\n","Error, ingrese su nuevo apellido nuevamente\n","Overflow", AuxlastName,51,2))
                    {
                        if(!getValidFloat("Nuevo salario?\n","Error, salario no valido\n", &Auxsalary,0, 100000,2))
                        {
                            if(!getValidInt("Nuevo sector?\n","Error, sector no valido\n", &Auxsector,0, 100000,2))
                            {
                                retorno = 0;

                                strncpy(list[index].name,Auxname,51);
                                strncpy(list[index].lastName,AuxlastName,51);
                                list[index].salary = Auxsalary;
                                list[index].sector = Auxsector;
                            }
                        }
                    }
            }
    }
    return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;
    int index;
    index = findEmployeeById(list,len,id);
    if(index >= 0)
    {
        retorno = 0;
        list[index].isEmpty = 1;
    }
    return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
  int retorno = -1;
    int i;
    if(list > 0 && list != NULL)
    {
        retorno = -2;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 0 && list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Employee auxiliarLastName;

    if(len > 0 && list != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<len-1;i++)
            {
                    if(list[i].isEmpty == 0 && list[i+1].isEmpty == 0 )
                    {

                            if((strncmp(list[i].lastName,list[i+1].lastName, 51) > 0 && !orden) || (strncmp(list[i].lastName,list[i+1].lastName,51) < 0 && orden))
                            {
                                if(list[i].sector == list[i+1].sector)
                                {

                                    auxiliarLastName = list[i];
                                    list[i] = list[i+1];
                                    list[i+1] = auxiliarLastName;

                                }

                            }

                    }
            }
        }while(flagSwap);
    }

     for(i = 0; i < MAX_EMPLEADOS; i++) {
        if(list[i].isEmpty == 0)
            printf("\n Apellido: %s - Sector: %d\n",list[i].lastName,list[i].sector);
    }
    printf("\n\n");

    return retorno;
}

int totalSalary(Employee *list, int len) {

    double acumulator = 0;
    int i;
    int retorno = -1;
    double average;
    int addEmployeeSalary = 0;
    int salaryMaxAverage = 0;

    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i < len-1; i++)
        {
            addEmployeeSalary++;

            if(list[i].isEmpty == 0)
            {
                acumulator = acumulator + list[i].salary;
                average = acumulator / addEmployeeSalary;

                if (list[i].salary > average)
                {
                    salaryMaxAverage++;
                }
            }
        }
    }

    printf("\n El total de salarios es: %.2f\n El promedio de salario es: %.2f\n El numero de personas con salario mayor al promedio es: %d", acumulator, average, salaryMaxAverage);
    printf("\n\n");

    return retorno;
}

int printEmployees(Employee* list, int length)
{
    int retorno = -1;
    int i;
    if(length > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty == 0)
            {
               printf("\n Apellido: %s - ID: %d - Salario: %.2f - Sector: %d",list[i].lastName,list[i].id,list[i].salary,list[i].sector);
            }
        }
    }
    return retorno;
}

int initEmployeesFirstPosition(Employee* list, int len)
{
  int retorno = -1;

    if(len > 0 && list != NULL)
    {

            if(list[0].isEmpty == 1)
            {
                printf("\nTiene que dar de alta un usuario para continuar\n");
                retorno = 0;
            }
    }

    return retorno;
}
