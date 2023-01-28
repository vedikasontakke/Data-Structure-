/*
inseration sort
time complixity O(n^2)
used when only few elements needs to sorted 
*/

#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void InsertionSort(int arr[], int n)
{
    int i , j , key;

    for(i=1 ; i<n ; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }

        arr[j+1] = key;
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
    int size;
    printf("enter eleemnts of array : ");
    scanf("%d",&size);
    int arr[size];

	for(int i=0 ; i<size ; i++)
       scanf("%d",&arr[i]);

	InsertionSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);
	return 0;
}
