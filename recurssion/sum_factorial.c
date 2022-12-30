/*calculate sum of n natural number*/
/*calculate factorial of n natural number*/
#include<stdio.h>
int sum(int x){
    int s = 0;
    if(x==0)
    return x;
    s= x + sum(x-1);
    return s;
}
int fact(int x){
    if(x<=1)
    return x;
    return x*fact(x-1);
}
int fun1(int x, int y)
{
    if (x == 0)
        return y;
    else
        return fun1(x - 1, x + y);
}
void fun2(int n)
{
  if(n == 0)
    return;
 
  fun2(n/2);
  printf("%d ", n);
} 

void fun3(int n)
{
   int i = 0; 
   if (n > 1) fun3(n-1);
   for (i = 0; i < n; i++)
     printf(" * ");

     printf("\n");
}

#define LIMIT 1000
void fun4(int n)
{
  if (n <= 0)
     return;
  if (n > LIMIT)
    return;
  printf("%d ", n);
  fun4(2*n);
  printf("%d ", n);
}  
int main()
{
    int n;
    printf("Enter natural numbers till you wish to find its sum \n");
    scanf("%d",&n);
  /*
    int x=n;
    printf("sum of n natural number is %d\n",sum(n));
    printf("factorial of n natural number is %d",x*fact(x-1));
    int y=1;
*/
    fun2(n);
    printf("\n");
    fun3(n);
    fun4(n);
    return 0;
}