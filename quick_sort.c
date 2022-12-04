#include<stdio.h>
void quicksort(int a[] , int first , int last)
{
   int i , j , pivot ;

   if(first < last)
   {
      pivot = first;
      i=first;
      j=last;

      while(i < j)
      {
         while(a[i] <= a[pivot] && i<last)
            i++;

        while(a[j] > a[pivot])
           j--;

        if(i <j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }   
      }

      temp = a[pivot];
      a[pivot] = a[j];
      a[j] = temp;

      // for left digits
      quicksort(a , 0 , pivot-1);
      // for right digits;
      quicksort(a , pivot+1 , last);
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

    quicksort(a , 0 , n-1);   
    
    printf("sorted elements are :");
    for(int i=0 ; i<n ; i++)
       printf("%d" , a[i]);

    return 0;   
}