// display after first element deleted not working 

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head = NULL , *temp = NULL;

void display()
{
   printf("elements of linked list are : ");

   struct node *curr = head;

   while(curr->next != head)
   {
     printf("%d ",curr->data);
     curr = curr->next;
   }
   
   printf(" %d ", curr->data);
}

void delete_first_node()
{
     struct node *curr = head;

     while(curr->next != head)
     {
        curr = curr->next;
     }

     head = head->next;
     curr->next = head;
     printf("%d deleted \n",curr->data);
     free(curr);

    // display();
}

void add_node(int node)
{
   struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
   newnode->data = node;
   newnode->next = NULL;  

   if(head == NULL)
   {
      head = newnode;
      temp = newnode;
      newnode->next = head;
   } 
   else
   {
      temp->next = newnode;
      newnode->next = head;
      temp = newnode;
   } 

   printf("%d inserted \n",newnode->data);
}

void creation()
{
      int size;
   printf("enter the size of list :");
   scanf("%d",&size);

   printf("enter the elements in the list \n");

   for(int i=0 ; i<size ; i++)
   {
      int n;
      scanf("%d",&n);
      add_node(n);
   }
}
int main()
{
    int choice;

    printf("1. create a linked list\n");
    printf("6. delete first element\n");
    printf("9. display linked list\n");
    printf("10. exit\n");

    while(1)
    {
        printf("enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : creation();
                     break;
            case 6 : delete_first_node();
                     break;
            case 9 : display();
                     break;
            case 10 : exit(1);
                     break;
            default: printf("invalid input\n");
                     break;
        }
    }        
}