#include<stdio.h>
int main()
{
/*  int var = 10;
    int* ptr = &var;
   // ptr = &var;
    printf("ptr is %d \n",ptr);
    printf("var is %d \n",var);
    printf("*ptr is %d \n",*ptr);

    *ptr = 30;
    printf("*ptr is %d \n",var);7
    int **ptr2 = &ptr ;
   // ptr2 = &ptr;
    **ptr2 = 30;
    printf("var is %d\n",var);
    printf("ptr2 is %d\n",ptr2);
    printf("*ptr2 is %d",**ptr2); 
*/
    int arr[] = {10 , 20 , 30};
    printf("*arr =  %d \n",*arr);

    int *ptr = arr;

    for(int i=0 ; i<3 ; i++)
    {
        printf("*ptr = %d\n" , *ptr);
        ptr++;  
    } 
}