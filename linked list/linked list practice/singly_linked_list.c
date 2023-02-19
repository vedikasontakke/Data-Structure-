#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head = NULL , *temp = NULL;

void display()
{
   printf("elements of linked list are : ");

   temp = head;

   while(temp->next != NULL)
   {
      printf("%d ",temp->data);
      temp = temp->next;
   }
   
         printf("%d ",temp->data);
}

void delete_last_node()
{
    struct node *curr = head;
    struct node *prev = head;

    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = NULL;
    printf("%d elemnt deleted \n", curr->data);
    free(curr);
}

void delete_specific_node()
{
    int del_node;

    struct node *curr = head;
    struct node *prev = head;

    printf("enter element which you want to delete: \n");
    scanf("%d",&del_node);
    
    while(curr->data != del_node)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    free(curr);

    printf("%d deleted successfully \n" , del_node);
}

void delete_first_node()1

{
    struct node *first = head;
    int del_node = first->data;
    head = head->next;
    free(first);

    printf("delelted item is %d \n",del_node);
}

void insert_last()
{
       int node;
       struct node *curr = head;

        printf("enter element that you want to insert at last: \n");
        scanf("%d",&node);  

       struct node *newnode = (struct node *)malloc(sizeof(struct node));
       newnode->next = NULL;
       newnode->data = node;

       while(curr->next != NULL)
       {
         curr = curr->next;
       }

       curr->next = newnode;

    printf("eleent inserted at last is %d \n", node);

}

void insert_after_specific_node()
{      
       int node , ele;
       struct node *curr = head;
       struct node *newnode = (struct node *)malloc(sizeof(struct node));
       newnode->next = NULL;

       printf("enter element after that you want to insert a lement : \n");
       scanf("%d",&node);

        printf("enter element whihc you want to insert  : \n");
       scanf("%d",&ele);

       newnode->data = ele;

       while(curr->data != node)
       {
         curr = curr->next;
       }
       
       newnode->next = curr->next;
       curr->next = newnode;
 
      printf("%d eleent inserted  after  %d \n", newnode->data , node);

}

void insert_before_specifc_node()
{
       int node , ele;
       struct node *current = head;
       struct node *prev = head;

       struct node *newnode = (struct node *)malloc(sizeof(struct node));
       newnode->next = NULL;

       printf("enter element before that you want to insert a lement : \n");
       scanf("%d",&node);

       printf("enter elment whihc you want to insert : ");
       scanf("%d",&ele);
       newnode->data = ele;

       while(current->data != node)
       {
          prev = current;
          current = current->next;
       }

       newnode->next = current;
       prev->next = newnode;

      printf("%d eleent inserted  before  %d \n", ele, node);

}

void insert_begin()
{
    int node;
    printf("enter element that you want to insert at begin: ");
    scanf("%d",&node);  

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = node;
    newnode->next = head; 
    head = newnode;

    printf("eleent inserted at begin is %d \n", node);
}

void add_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

   if(head == NULL)
   {
      head = newnode;
      temp = newnode;
   }
   else
   {
      temp->next = newnode;
      temp = newnode;
   }

   printf("%d elemnt is inserted \n" , data);
}

void creation()
{
    int size;
    printf("enter number of elements in the linked list : ");
    scanf("%d",&size);

    for(int i=0 ; i<size ; i++)
    {
        int data;
        printf("enter %d elemnt : ",i);
        scanf("%d",&data);
        add_node(data);
    }
}

int main()
{
    int choice;

    printf("1. create a linked list\n");
    printf("2. add element at first\n");
    printf("3. add element after specific node\n");
    printf("4. add element before specific node\n");
    printf("5. add element at last\n");
    printf("6. delete first element\n");
    printf("7. delete specific node\n");
    printf("8. delete last node\n");
    printf("9. display linked list\n");
    printf("10. exit\n");

    while(1)
    {
        printf("\nenter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : creation();
                     break;
            case 2 : insert_begin();
                     break;
            case 3 : insert_after_specific_node();
                     break;
            case 4 : insert_before_specifc_node();
                     break;
            case 5 : insert_last();
                     break;
            case 6 : delete_first_node();
                     break;
            case 7 : delete_specific_node();
                     break;
            case 8 : delete_last_node();
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