#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[25] = {'\0'};
void push(char);
char pop();
int top = -1;

int main()
{
    char postfix_string[25] = {'\0'};
    printf("enter a postfix string : ");
    scanf("%s",&postfix_string);

    int i = strlen(postfix_string)-1;

    while(i >= 0)
    {
        char ele = postfix_string[i];

        if((isalnum(ele))) 
        {
            push(ele);
            push(' ');
        }else
        {
            for(int j=top-1 ; j>=0 ; j--)
            {
                if(stack[j] == ' ') 
                {
                    stack[j] = ele;
                    break;
                }
            }
        }

        i--;
    }

    printf("infix expression is : %s ", strrev(stack));
}

void push(char ele)
{
    if(top == 24) printf("stack is full \n");
    else stack[++top] = ele;
}

char pop()
{
    if(top == -1) printf("stack is empty \n");
    else return stack[top--];
}