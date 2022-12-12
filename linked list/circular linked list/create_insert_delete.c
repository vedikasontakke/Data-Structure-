#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head , *temp = NULL;
void display()
{
    struct node *temp = head;
    printf("elements in the linked list are :");

    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}

void delete_first_node()
{
    struct node *temp = head;
    while(temp->next != head)
      temp = temp->next;

    head = head->next;
    temp->next = head;

    printf("first element deleted successfully \n");
    display();
}

void delete_last_node()
{
    struct node *temp = head;
    struct node *prev = head;
    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }
    
   prev->next = head;
   printf("last node deleted successfully \n");
   display();
}

void delete_specefic_node()
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

void insert_begin()
{
   struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
   printf("enter element which you want to insert at begin : \n");
   scanf("%d" , &newnode->data);
   newnode->next = NULL;
   struct node *temp = head;

   newnode->next = head;

   while(temp->next != head)
     temp = temp->next;
   
   temp->next = newnode;
   head = newnode;

   display();

}

void insert_end()
{
   struct node *temp = head;
   struct node *newnode = (struct node *)malloc(sizeof(struct node *));

   printf("enter element which you want to insert at end : \n");
   scanf("%d" , &newnode->data);

   while(temp->next != head)
      temp = temp->next;

    temp->next = newnode;  
    newnode->next = head;    

    display();
}

void insert_before_specific_node()
{
    struct node* temp = head;
    struct node* prev = head;

   struct node *newnode = (struct node *)malloc(sizeof(struct node *));
   int y;
   printf("enter element before that you want to insert at element : \n");
   scanf("%d" , &y);

   printf("enter the ellement which you want to insert :\n");
   scanf("%d" , &newnode->data);

   newnode->next = NULL;

   while(temp->data != y){
       prev = temp;
      temp = temp->next;
   }
      
   newnode->next = temp;
   prev->next = newnode;

   display();
}

void insert_after_specific_node()
{
   struct node* temp = head;
   struct node *newnode = (struct node *)malloc(sizeof(struct node *));
   int y;
   printf("enter element after that you want to insert at element : \n");
   scanf("%d" , &y);

   printf("enter the ellement which you want to insert :\n");
   scanf("%d" , &newnode->data);

   newnode->next = NULL;

   while(temp->data != y)
      temp = temp->next;

   newnode->next = temp->next;
   temp->next = newnode;

   display();
}                               

void addnode(int n)
{
   struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
   newnode->data = n;
   newnode->next = NULL;
   if(head == NULL)
   {
      head = newnode;
      temp = newnode;
      newnode->next = head;
   }else
   {
     newnode->next = head;
     temp->next = newnode;
     temp = newnode;
   }
}
int main()
{
    int size;
   printf("enter the size of list :");
   scanf("%d",&size);

   printf("enter the elements in the list \n");

   for(int i=0 ; i<size ; i++)
   {
      int n;
      scanf("%d",&n);
      addnode(n);
   }

   display();
   insert_begin();
   insert_end();
   insert_after_specific_node();
   insert_before_specific_node();
   delete_first_node();
   delete_last_node();
  delete_specefic_node();

}