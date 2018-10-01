#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
 int maxAddEmployee;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len);
int modifyEmployees(Employee* list,int len,int id);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeById(Employee* list, int len,int id);
int sortEmployees(Employee* list, int len, int order);
int totalSalary(Employee *list, int len);
int printEmployees(Employee* list, int length);
int initEmployeesFirstPosition(Employee* list, int len);




#endif // ARRAYEMPLOYEES_H_INCLUDED
