#include<stdio.h>
#include<string.h>
#include<ctype.h>

void push(char);
char pop();
void display();

char stack[25]={'\0'};
int top = -1;
//char ch;

int main()
{
    char postfix[25] = {'\0'} , ele;
    int i=0 , j ;

   printf("enter postfix expression : \n");
   scanf("%s",postfix);
   printf("postfix expression is : %s\n" , postfix);
   
    while(i < strlen(postfix))
    {
         ele = postfix[i];
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
         i++;
    }   
    printf("infix expression is %s", stack);
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