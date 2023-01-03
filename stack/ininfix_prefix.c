#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top==-1) return '\0';
    else return stack[top--];
}

int priority(char x)
{
   if(x == '(' || x==')') return 0;
   if(x == '+' || x == '-') return 1;
   if(x == '*' || x == '/') return 2;
   if(x == '^') return 3;
   return 0;
}

int main()
{
    char exp[100] , output[100];
    char *e , x;
    printf("enter the expression :");
    scanf("%s",exp);
    printf("\n");

    int output_index = 0;
    strrev(exp);
    
    e= exp;
  while(*e != '\0')
    {
        if(isalnum(*e)) output[output_index++] = *e;
        else if(*e == ')') push(*e);
        else if(*e == '(') while((x == pop()) != ')') output[output_index++] = x;
        else{
            while(priority(stack[top]) > priority(*e)) output[output_index++] = pop();
            push(*e);
        }
        *e++;
    }

    while(top != -1) output[output_index++] = pop();

    printf("prefix expression is : ");
    for(int i=strlen(exp)-1 ; i>=0 ; i--)
    {
        printf("%c",output[i]);
    }
  
    return 0 ;
}