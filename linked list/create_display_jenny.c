// not working 

#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head , *newnode , *temp;
int head = NULL;

int main()
{
   int choice=1;

   while(choice)
   {
     struct node newnode = (struct node *) malloc(sizeof(struct node));
     printf("enter data :");
     scanf("%d",&newnode->data);
     newnode->next = NULL;

     if(head == NULL) {
      head = newnode;
      temp = newnode;
     }
     else
     {
        temp->next=newnode;
        temp = newnode;
     }

     printf("Do you want to continue (0,1) ??");
     scanf("%d",&choice);
   }

   temp = head;
   while(temp !=NULL)
   {
     printf("%d",temp->data);
     temp=temp->next;
   }

   getch();
}