#include<stdio.h>
// divide a array untill you didnt get single value
/*
The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) 
as merge sort always divides the array into two halves and takes linear time to merge two halves.
*/
void merge_sort();
// sort a array 
void merge();

int main()
{
    int a[40] , n , i;
    printf("enter size of an array \n");
    scanf("%d", &n);

    printf("elements before soting") ;
    for( i=0 ; i<n ; i++)
      scanf("%d" , &a[i]);

    merge_sort(a , 0 , n-1); 

    printf("elements after soting") ;

    for( i=0 ; i<n ; i++)
      printf("%d",a[i]);
}

void merge_sort(int a[] , int first , int last)
{
    int mid ;
    if(first < last)
    {
        mid = (first+last)/2;
        merge_sort(a , first , mid);
        merge_sort(a , mid+1 , last);

        // merge array after sorting 
        merge(a , first , mid , last);
    }
}

void merge(int a[] , int first , int mid , int last)
{
    int b[50];
    int i , j , k;
    i = first ;   // looping for first array
    j = mid+1;    // divide array and 
    k = first;   // looping for 2nd array 

    while(i<=mid && j<=last)
    {
        //check 1st element of 1st half with 1st eleemnt of first half 
        if(a[i]<=a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];   
    }

    if(i>mid)
    {
        while(j<=last)
          b[k++] = a[j++];
    }
    else{
        while(i<=mid)
           b[k++] = a[i++];
    }

    for( i=first ; i<=last ; i++)
       a[i] = b[i];
}