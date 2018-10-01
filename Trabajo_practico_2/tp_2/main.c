#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX_EMPLEADOS 1000

int main()
{
    Employee list[MAX_EMPLEADOS];
    int menu;
    int auxiliarId;

    initEmployees(list, MAX_EMPLEADOS);

    do
    {
        getValidInt("\n1.Alta Empleado\n2.Modificacion Empleado\n3.Baja Empleado\n4.Ordenar y mostrar empleados y sector\n5.Total salarios de empleado, promedios y cant. de empleados mayores a su salario medio \n6. Lista de empleados con todos sus datos\n7. Salir\n","\n Opcion no valida",&menu,1,7,1);

        switch(menu)
        {
            case 1:
                addEmployee(list,MAX_EMPLEADOS);
                break;
            case 2:
                initEmployeesFirstPosition(list, MAX_EMPLEADOS);
                getValidInt("\nID del empleado?","\nNumero invalido\n",&auxiliarId,0,4,2);
                modifyEmployees(list,MAX_EMPLEADOS, auxiliarId);
                break;
            case 3:
                initEmployeesFirstPosition(list, MAX_EMPLEADOS);
                getValidInt("\nID del empleado?","\nNumero invalidado\n",&auxiliarId,0,4,2);
                removeEmployee(list,MAX_EMPLEADOS, auxiliarId);
                break;
            case 4:
                initEmployeesFirstPosition(list, MAX_EMPLEADOS);
                sortEmployees(list,MAX_EMPLEADOS,0);
                break;
            case 5:
                totalSalary(list, MAX_EMPLEADOS);
                break;
            case 6:
                printEmployees(list, MAX_EMPLEADOS);
                break;
            case 7:
                break;
        }

    }while(menu != 7);

     return 0;
}
