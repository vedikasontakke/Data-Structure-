#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
char infix[SIZE] = {'\0'};
char postfix[SIZE] = {'\0'};
char operator_stack[25];
int top_operator = -1;
int post_index = 0;

void push(char);
char pop();
char peek();
int priority_return(char);

int main()
{
   char infix_expression = {'\0'};
   printf("enter a string :");
   scanf("%s",&infix);
   int i=0;
   char pop_ele;
   while(infix[i]!='\0')
   {
      char character = infix[i];
      if(character == '(')
      {
         push(character);
      }
      else if(character == ')')
      {
        while(character != '(')
        {
          pop_ele = pop();
          postfix[post_index] = pop_ele;
          post_index++;
        }
        pop();

      }else if(character == '*' || character == '/' || character == '+' || character == '-' || character == '^')
      {
         if(top_operator>=0){
            char peek_ele = peek();
             while(priority_return(peek_ele) >= priority_return(character) && top_operator!=-1)
             {
                pop_ele = pop();
                postfix[post_index] = pop_ele;
                post_index++;
             }
         }
         push(character);
      } else{
         postfix[post_index] = character;
         post_index++;
      }
      i++;
   }

   int x = 0;
   printf("postfix expression is :\n");
   if(top_operator!=-1){
          while(x<post_index)
          {
              printf("%c",postfix[x]);
              x++;
          }
   }

}

int priority_return(char ele)
{
    switch(ele)
    {
      case '^' : return 3;
      case '*' :
      case '/' : return 1;
      case '+' :
      case '-' : return 1;
    }
    return -1;
}

char pop()
{
    char del_ele;
    if(top_operator != -1)
    {
        del_ele = operator_stack[top_operator];
        top_operator--;
    }
    return del_ele;
}

void push(char ele)
{
    if(top_operator != SIZE)
    {
       top_operator++;
       operator_stack[top_operator] = ele;
    }
}

char peek()
{
    return operator_stack[top_operator];
}

