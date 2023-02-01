#include<stdio.h>
#include<string.h>

char opr_stack[25] = {'\0'};
char out_stack[25] = {'\0'};

int top_opr = -1;
int top_out = -1;

char pop_opr();
char peek_opr();
void push_opr(char);
void push_out(char);

int getpriority(char);

int main()
{
    char infix_string[25] = {'\0'} , ele , pop_ele;

    printf("enter a string : ");
    scanf("%s",&infix_string);

    int len = strlen(infix_string)-1;

    while(len >= 0 )
    {
         ele = infix_string[len];
        
        if(ele == ')') push_opr(ele);
        else if(ele == '(')
        {
            while(peek_opr() != ')') push_out(pop_opr());
            
            pop_opr();
        }
        else if(ele == '*' || ele == '/' || ele == '+' || ele == '-' || ele == '^')
        {
            if(top_opr >= 0)
               while(getpriority(peek_opr()) > getpriority(ele) && top_opr != -1) push_out(pop_opr());

            push_opr(ele);
        }else  push_out(ele);

        len--;
    }

    if(top_opr != -1)
       while(top_opr != -1) push_out(pop_opr());
    

    printf("prefix expression is : %s",strrev(out_stack));
}

int getpriority(char ele)
{
    switch (ele)
    {
         case '^' : return 3;
         case '*' :
         case '/' : return 2;
         case '-' :
         case '+' : return 1;
    }
    return -1;
}

void push_opr(char ele)
{
    if(top_opr == 24) printf("stack is full\n");
    else opr_stack[++top_opr] = ele;
}

void push_out(char ele)
{
    if(top_out == 24) printf("stack is full\n");
    else out_stack[++top_out] = ele;
}

char pop_opr()
{
     if(top_opr == -1) printf("stack is empty\n");
     else return opr_stack[top_opr--];
}

char peek_opr()
{
   if(top_opr != -1) return opr_stack[top_opr];
}