#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[100];

int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top==-1) return -1;
    else return stack[top--];
}
                      
int main()
{
    char postfix_exp[100] , *e;
    // char infix_exp[100];

    printf("enter postfix expression :");
    scanf("%s",postfix_exp);
     e = postfix_exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e)) push(*e);
        else
        {
            char op1 = pop();
            char op2 = pop();
            push("(" + op2 + *e + op1 + ")");
            //printf("( %c %e %c ",op2,*e,op1);
        }
    }
    printf("%c",pop());
}