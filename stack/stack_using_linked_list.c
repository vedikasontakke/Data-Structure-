#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
struct node* top = 0;

struct node{
    int data;
    struct node* next;
};

void push()
{
   struct node *newnode = (struct node *) malloc(sizeof(struct node));
   printf("enter a element which you want to insert\n ");
   scanf("%d",&newnode->data); 

   newnode->next = top;
   top = newnode;

   printf("%d element inserted successfully \n",newnode->data);
}
void pop()
{
    struct node* temp;
    temp = top;
    top = top->next;
    free(temp);
    printf("element deleted sucessfully \n");
}
void peek()
{
   if(top==0) printf("stack is empty"); 
   printf("%d is a topmost element \n",top->data);
}
void display()
{
    struct node* temp = top;
    printf("total elements in the stack are : \n");
    while(temp!=0)
    {
       printf("%d ",temp->data);
       temp= temp->next;
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