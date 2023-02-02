#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*front=NULL , *rear=NULL;

void enqueue();
void dequeue();
void display();

int main()
{
   int choice;

    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");
  
   while(1)
   {
      printf("\n\nenter your choice : ");
      scanf("%d",&choice);

      switch ((choice))
      {
        case 1: enqueue();
                break;
        case 2: dequeue();
                break;
        case 3: display();
                break;
        case 4: exit(1);
                break;
        default: break;
      }

   }
}

void enqueue()
{  
   int data;

    printf("enter a data : ");
    scanf("%d",&data);

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(front == NULL) front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
   
    printf("element inserted is %d \n",data);

}

void dequeue()
{
   if(front == NULL) printf("queue is empty \n");
   else
   {
     struct node *temp = front;
     front = front->next;
     printf("deleted item is %d \n", temp->data);
     free(temp);  
   }
}

void display()
{
   struct node *temp = front;

   if(front == NULL) printf("queue is empty \n");
   else
   {
      printf("elements in the queue are : \n");
      while(temp !=NULL)
      {
        printf("%d ", temp->data);
        temp = temp->next;
      }
   }
}