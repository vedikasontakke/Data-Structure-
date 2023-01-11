#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head , *temp = NULL;

void display()
{
   struct node *temp = head;
    
    printf("elements in the linked list are :");
    while(temp != NULL){

        printf("%d " ,temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_speciefic_node(){
     int y ; 
     struct node *temp = head;

     printf("enter element which you want delete \n");
     scanf("%d",&y);

    while(temp->data != y)
       temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    display();
}

void delete_last_node()
{
    struct node *prev = head;
    struct node *first = head;
    while(first->next != NULL){
        prev = first;
        first = first->next;
    }
    prev->next = NULL;
    free(first);
    printf("last element deleted successfully \n");
    display(); 
}
void delete_first_node()
{
    struct node *first = head;
    head = head->next;
    free(first);
    printf("first element deleted successfully \n");
    display();

}
void insert_element_before_specefic_node()
{
   struct node *temp = head;
   struct node *newnode_ = (struct node *)malloc(sizeof(struct node *));
   int y;
   printf("enter element before that you want to insert at element : \n");
   scanf("%d" , &y);

   printf("enter the element which you want to insert :\n");
   scanf("%d" , &newnode_->data);
  
   while(temp->data != y)
        temp = temp->next;

    newnode_->prev = temp->prev;
    temp->prev->next = newnode_;
    temp->prev = newnode_;
    newnode_->next = temp;
  
   display();
}

void insert_after_specific_node()
{   
    struct node *temp = head;
   struct node *newnode = (struct node *)malloc(sizeof(struct node *));
   int y;
   printf("enter element after that you want to insert at element : \n");
   scanf("%d" , &y);

   printf("enter the ellement which you want to insert :\n");
   scanf("%d" , &newnode->data);
    
    while(temp->data != y)
      temp = temp->next;
   
     temp->next->prev = newnode;
     newnode->next = temp->next;
     temp->next = newnode;
     newnode->prev = temp;

   display();
}
void insert_end()
{
    struct node *temp = head;

    struct node *newnode = (struct node *)malloc(sizeof(struct node *));

   printf("enter element which you want to insert at end : \n");
   scanf("%d" , &newnode->data);
   newnode->next = NULL;

   while(temp->next != NULL)
     temp = temp->next;
   
   temp->next = newnode;
   newnode->prev = temp;

   display();
}
void insert_begin()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter element which you want to insert at begin : \n");
    scanf("%d" , &newnode->data);

    newnode->next = head;
    head = newnode;

    display();
}
void addnode(int x)
{ 
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;

   if(head == NULL)
   {
     head = newnode;
     temp = newnode;
   }else
   {
     temp->next = newnode;
     newnode->prev = temp;
     temp = newnode;
   }   
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
   
}


int main()
{
    creation();
    insert_begin();
    insert_end();
  //insert_after_specific_node();
  //insert_element_before_specefic_node();
    delete_first_node();
    delete_last_node();
    delete_speciefic_node();
}
