/* selection sort in c
   based on the selection of the smallest elmement and swapped it 
   selection sort = min_index=i and start looping form i+1 and update min_index if element is < minidex
   time complexity O(n^2)
   Auzilary space O(1)*/
#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void SelectionSort(int arr[], int n)
{
    int i , j , min_index;
    
    for( i=0 ; i<n ; i++)
    {
        min_index = i;

        for(j=i+1 ; j<n ; j++)
            if(arr[j] < arr[min_index]) min_index = j;
        
        if(min_index!=i) swap(&arr[min_index] , &arr[i]);
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

	SelectionSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);
	return 0;
}
