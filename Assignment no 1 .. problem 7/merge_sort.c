/*
WAP to implement Merge Sort on 1D array of Employee 
structure (contains employee_name, emp_no, emp_salary), with key as
emp_no. And count the number of swap performed.
*/

#include<stdio.h>

void merge_sort();
void merge();

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

    struct Employee emp_array[size];

    printf("enter the employee no , employee name , employee salary :");
    for(int i=0 ; i<size ; i++)
       scanf("%d %s %d" , &emp_array[i].emp_no , &emp_array[i].employee_name , &emp_array[i].emp_salary);

    merge_sort(emp_array , 0 , size-1);

    printf("print the employee no , employee name , employee salary  after sorting :");
    for(int i=0 ; i<size ; i++)
       printf("\n %d %s %d ",emp_array[i].emp_no,emp_array[i].employee_name , emp_array[i].emp_salary);    

    return 0;
}

void merge_sort(struct Employee emp_array[], int first , int last)
{
    int mid ;
    if(first < last)
    {
        mid = (first+last)/2;
        merge_sort(emp_array , first , mid);
        merge_sort(emp_array , mid+1 , last);
        merge(emp_array , first , mid , last);
    }
}

void merge(struct Employee emp_array[], int first , int mid , int last)
{
    struct Employee b[50];
    int i , j , k;
    i = first ;
    j = mid+1;
    k = first;

    while(i<=mid && j<=last)
    {
        if(emp_array[i].emp_no <= emp_array[j].emp_no)
           b[k++] = emp_array[i++];
        else 
           b[k++] = emp_array[j++];   
    }

    if(i>mid)
    {
        while(j<=last)
          b[k++]= emp_array[j++];
    }
    else{
        while(i<=mid)
           b[k++] = emp_array[i++];
    }

    for( i=first ; i<=last ; i++)
       emp_array[i] = b[i];
}