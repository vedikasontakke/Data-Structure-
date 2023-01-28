#include<stdio.h>
//    time complexity = O(n^2)
//    easy  aapna college
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition(int arr[] , int left , int right)
{
    // last element is considered as pivot element
    int pivot = arr[right];
    int i = left-1;

    for(int j=left ; j<right ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    
    swap(&arr[i+1] , &arr[right]);
    return i+1;
}
void quick_sort(int arr[] , int left , int right)
{
    if(left < right)
    {
        int pivot = partition(arr , left , right);

        quick_sort(arr , left , pivot-1);
        quick_sort(arr , pivot+1 , right);
    }
}
int main()
{
    int a[40] , n , i;
    printf("enter size of array :\n");
    scanf("%d" , &n);

    printf("enter elements :\n");
    for(int i=0 ; i<n ; i++)
       scanf("%d" , &a[i]);

    quick_sort(a , 0 , n-1);   
    
    printf("sorted elements are :");
    for(int i=0 ; i<n ; i++)
       printf("%d " , a[i]);
    
    return 0;   
}