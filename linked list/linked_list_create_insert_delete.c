#include <stdio.h>  
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head , *temp = NULL;
void display();
void delete_specific_node()
{
    struct node* prev = head;
    struct node* current = head;
    int y;
    printf("enter the element which you want to delete :\n");
    scanf("%d" , &y);

    while(current->data != y)
    {
       prev = current;
       current = current->next;
    }

    prev->next = current->next;
    current->next = NULL;
    free(current);

    printf("%d element deleted successfully \n" , y);
    display(); 
}
void delete_last_node()
{
    struct node* prev = head;
    struct node* current = head;
    while(current->next != NULL){
       prev = current;
       current = current->next;
    }
    prev->next = NULL;
    free(current);  
    printf("last element deleted successfully \n");
    display(); 

    delete_specific_node();
}

void delete_first_node()
{
   struct node* first = head;
   head = head->next;
   free(first);
   printf("first element deleted successfully \n");
   display();

   delete_last_node();
}

void insert_before_specific_node()
{
    struct node* current = head;
    struct node* prev = head;

   struct node *newnode = (struct node *)malloc(sizeof(struct node *));
   int y;
   printf("enter element before that you want to insert at element : \n");
   scanf("%d" , &y);

   printf("enter the ellement which you want to insert :\n");
      scanf("%d" , &newnode->data);

   newnode->next = NULL;

   while(current->data != y){
       prev = current;
      current = current->next;

   }
      
   newnode->next = current;
   prev->next = newnode;

   display();

   delete_first_node();
}

void insert_after_specific_node()
{
   struct node* current = head;
   struct node *newnode = (struct node *)malloc(sizeof(struct node *));
   int y;
   printf("enter element after that you want to insert at element : \n");
   scanf("%d" , &y);

   printf("enter the ellement which you want to insert :\n");
      scanf("%d" , &newnode->data);

   newnode->next = NULL;

   while(current->data != y)
      current = current->next;

   newnode->next = current->next;
   current->next = newnode;

   display();
   insert_before_specific_node();
}                               

void insert_end()
{
   struct node *newnode = (struct node *)malloc(sizeof(struct node *));

   printf("enter element which you want to insert at end : \n");
   scanf("%d" , &newnode->data);
   newnode->next = NULL;
   struct node *current_ = head;

   while( current_->next != NULL )
        current_ = current_->next;
   
   current_->next = newnode;

   display();
   insert_after_specific_node();
}

void addnode(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void insert_begin()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));

   printf("enter element which you want to insert at begin : \n");
   scanf("%d" , &newnode->data);

    newnode->next = head;
    head = newnode;  
 
   display();
   insert_end();
}

void display()
{
    struct node *current = head;

    printf("elements in the linked list are :");
     while(current != NULL)
     {
        printf("%d ", current->data);
        current = current->next;
     }

     printf("\n");
}

void creation()
{
    int size;
    printf("enter the size of linked list :");
    scanf("%d",&size);
    printf("enter elements of linked list :\n");

    for(int i=0 ; i<size ; i++)
    {
       int n;
       scanf("%d",&n);
       addnode(n);  
    }

    display();
    insert_begin();
}

int main()
{
    creation();
}
