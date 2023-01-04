#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[25] = {'\0'};
int top = -1;
char ch;

void push(char);
char pop();
void display();

void main()
{
   char prefix[25] = {'\0'} , ele;
   int j ;

   printf("enter prefix expression : \n");
   scanf("%s",prefix);
   printf("prefix expression is : %s\n" , prefix);
   
   int i = strlen(prefix)-1;

   while(i>=0)
   {
      ele = prefix[i];
       if((isalnum(ele)))
         {
            push(ele);
            push(' ');
            printf("\n ele = %c push to the stack",ele);  
         }
         else
         {
             printf("\n operator = %c" , ele);
             for(j= top-1 ; j>=0 ; j--)
             {
                if(stack[j]==' ')
                {
                    stack[j] = ele;
                    break;
                }
             }
         }
    display();
    printf("\n-------------------------------------------------------------------\n");
        
      i--;
   }
    
    printf("\n Infix expression is %s ", strrev(stack));
}


void push(char ele)
{
    if(top == 24) printf("stack is overflow\n");
    else stack[++top] = ele;
}

char pop()
{
    if(top == -1) printf("stack is empty\n");
    else return stack[top--];
}

void display()
{
    int i;
    for(int i=0 ; i<=top ; i++) printf("\n s[%d] =%c", i, stack[i]);
}