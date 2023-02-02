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

void delete_last_node()
{
    struct node *curr = head;
    struct node *prev = head;

    while(curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;
    printf("%d deleted \n",curr->data);
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

void insert_last()
{
    struct node *curr = head;
    struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
    newnode->next = NULL;

    printf("enter element which you wanna ti insert : \n");
    scanf("%d", &newnode->data);

    
    while(curr->next != head)
    {
        curr = curr->next;
    }
    
    curr->next = newnode;
    newnode->next = head;

    printf("%d element inserted at end \n",newnode->data);
}

void insert_after_specific_node()
{      
       int node;
       struct node *curr = head;

       printf("enter element after that you want to insert a lement : \n");
       scanf("%d",&node);

       struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
       newnode->next = NULL;

       printf("enter element which you wanna ti insert : \n");
       scanf("%d", &newnode->data);

       while(curr->data != node)
       {
         curr = curr->next;
       }
       
       newnode->next = curr->next;
       curr->next = newnode;

      printf("%d inserted after %d \n",newnode->data , node);                 

}

void insert_before_specifc_node()
{
       struct node *curr = head;
       struct  node *prev = head;
       
       int node;
       printf("enter element before that you want to insert a lement : \n");
       scanf("%d",&node);

       struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
       newnode->next = NULL;

       printf("enter element which you wanna ti insert : \n");
       scanf("%d", &newnode->data);

       while(curr->data != node)
       {
          prev = curr;
          curr = curr->next;
       }

       newnode->next = curr;
       prev->next = newnode;

       printf("%d inserted before %d \n",newnode->data , node);                 
}

void insert_begin()
{
       int node;
       struct node *curr = head;
       printf("enter element that you want to insert : \n");
       scanf("%d",&node);    

   struct node *newnode = (struct  node*)malloc(sizeof(struct node ));
   newnode->data = node;
   newnode->next = head;  

   while(curr->next != head)
   {
     curr = curr->next;
   }

   curr->next = newnode;
   head = newnode;


     printf("%d inserted at begin \n",newnode->data);
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
        printf("enter your choice : ");
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