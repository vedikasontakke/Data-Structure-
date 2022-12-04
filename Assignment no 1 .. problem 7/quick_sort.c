/*
WAP to implement Quick Sort on 1D array of Employee
structure (contains employee_name, emp_no, emp_salary), with key as
emp_no. And count the number of swap performed.
*/

#include<stdio.h>
#include <string.h>    
int count_swap = 0;
struct Employee
{
    char employee_name[40];
    int emp_no;
    int emp_salary;
};

void swap(struct Employee *emp_array , int x  , int y)
{
    struct Employee temp;
    temp = emp_array[x];
    emp_array[x] = emp_array[y];
    emp_array[y] = temp;

    count_swap++;
}

void quick_sort(struct Employee emp_array[] , int first , int last)
{
    int i , j , pivot;

    if(first < last){
           
    i = first;
    j = last;
    pivot = first;

    while(i < j)
    {
       while(emp_array[i].emp_no <= emp_array[pivot].emp_no && i<last)
         i++;

       while(emp_array[j].emp_no > emp_array[pivot].emp_no)
         j--;  

       if(i < j) swap(emp_array , i , j);  
    }

    swap(emp_array , j , pivot);

    // for left digits
    quick_sort(emp_array , 0 , pivot-1);
      // for right digits;
    quick_sort(emp_array , pivot+1 , last);
    }
   
}
int main()
{
    int size ;
    printf("enter the size of the array \n");
    scanf("%d",&size);

    struct Employee emp_array[size];

    printf("enter the employee no , employee name , employee salary :");
    for(int i=0 ; i<size ; i++)
       scanf("%d %s %d" , &emp_array[i].emp_no , &emp_array[i].employee_name , &emp_array[i].emp_salary);

    quick_sort(emp_array , 0 , size-1);
    
    printf("number of swaps are : %d" , count_swap);

    printf("\n print the employee no , employee name , employee salary  after sorting :");
    for(int i=0 ; i<size ; i++)
       printf("\n %d %s %d ",emp_array[i].emp_no,emp_array[i].employee_name , emp_array[i].emp_salary);    

    return 0;
   
}
