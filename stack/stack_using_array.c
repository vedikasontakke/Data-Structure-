#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define SIZE 100
int top = -1;
int stack[SIZE];

bool isEmpty()
{
   if(top == -1) return true;
   else return false;
}

bool isFull()
{
  if(top == SIZE-1) return true;
  else return false;
}

void push()
{
   int item; 
   printf("enter a element which you want to push :");
   scanf("%d" , &item);
   
   if(isFull()) printf("stack is overflow \n");
   else{
     top++;
     stack[top] = item;
     printf("%d item inserted successfully\n",item);
   }

}

void pop()
{
   if(isEmpty()) printf("stack is empty \n");
   else {
      int del_item = stack[top];
      top--;
      printf("%d item deleted successfully \n",del_item);
   }
}

void peek()
{
   printf("topmost element is %d",stack[top]);
}

void display()
{
    printf("elements in the stack are :\n");
   
   if(isEmpty()) printf("stack is empty \n");
   else{
        for(int i=top ; i>=0 ; i--)
           printf("%d ",stack[i]);
   }
}

int main()
{
   int ch;
   do
   {  
      printf("\nPerform operations on the stack:\n");
      printf("1. push\n");
      printf("2. pop\n");
      printf("3. peek\n");
      printf("4. display\n");
      printf("5. exit\n");

      printf("enter the choice :");
      scanf("%d",&ch);

      switch (ch)
      {
       case 1 : push();
               break;
       case 2 : pop();
               break;
       case 3 : peek();
               break;
       case 4 : display();
               break;
       case 5 : exit(0);
               break;       
      default: printf("invalid output ");
               break;
      }

   } while (ch != 0);
   
}