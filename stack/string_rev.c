// C program to demonstrate
// example of strrev() function
 
#include <stdio.h>
#include <string.h>
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
    char exp[50] , *e , output[100] , x;
    int output_index = 0;

    printf("enter the expression :");
    scanf("%s",exp);
 
    printf("The given string is =%s\n", exp);
 
    printf("After reversing string is =%s\n", strrev(exp));
    e = exp;
    printf("e : %s\n", e);

    while(*e != '\0')
    {
        //printf("*e is %d\n ",*e);
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
    return 0;
}