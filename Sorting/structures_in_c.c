

#include<stdio.h>
#include <string.h>    

struct Employee
{
    char employee_name[40];
    int emp_no;
    int emp_salary;
};
int main()
{
    int size;
    printf("enter the size of the array \n");
    scanf("%d",&size);

    struct Employee a[size];

    printf("enter the employee no , employee name , employee salary :");
    for(int i=0 ; i<size ; i++)
       scanf("%d %s %d" , &a[i].emp_no , &a[i].employee_name , &a[i].emp_salary);

    printf("print the employee no , employee name , employee salary :");
    for(int i=0 ; i<size ; i++)
       printf("\n%d %s %d ",a[i].emp_no,a[i].employee_name , a[i].emp_salary);    

    return 0;
   
}
