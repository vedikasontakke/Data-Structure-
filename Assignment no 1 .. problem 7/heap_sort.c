/*
WAP to implement Heap Sort on 1D array of Employee 
structure (contains employee_name, emp_no, emp_salary), with key as
emp_no. And count the number of swap performed.
*/
#include<stdio.h>
void heap_Sort();
void heapify();

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

    heap_Sort(emp_array , size);

    printf("print the employee no , employee name , employee salary  after sorting :");
    for(int i=0 ; i<size ; i++)
       printf("\n %d %s %d ",emp_array[i].emp_no,emp_array[i].employee_name , emp_array[i].emp_salary);    

    return 0;
 
}


void swap(struct Employee *emp_array , int x  , int y)
{
    struct Employee temp;
    temp = emp_array[x];
    emp_array[x] = emp_array[y];
    emp_array[y] = temp;
}

void heapify(struct Employee emp_array[], int size, int i)
{
    //  largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // If left child is larger than root
    if (left < size && emp_array[left].emp_no > emp_array[largest].emp_no)
        largest = left;
 
    // If right child is larger than largest
    if (right < size && emp_array[right].emp_no > emp_array[largest].emp_no)
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(emp_array , i , largest);
        // Recursively heapify the affected sub-tree
        heapify(emp_array, size, largest);
    }
}

 void heap_Sort(struct Employee emp_array[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(emp_array, size, i);
 
    // Heap sort
    for (int i = size - 1; i >= 0; i--) {
        swap(emp_array , 0 , i);
        // Heapify root element to get highest element at root again
        heapify(emp_array, i, 0);
    }
}