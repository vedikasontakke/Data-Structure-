#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front = NULL , *rear = NULL;

void enqueue()
{
     int ele;
    printf("enter a data ");
    scanf("%d",&ele);
    struct node *newnode = (struct node*)malloc(sizeof(struct node ));
    newnode->data = ele;
    newnode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }else
    {
         rear->next = newnode;
         newnode->next = front;
         rear = newnode;
    }

    printf("element inserted is %d\n",ele);
}

void dequeue()
{
   struct node *temp = front;
   
   if(front == NULL && rear == NULL) printf("empty\n");
   else
   {
      front = front->next;
       rear->next = front;
       
        printf("delete is %d \n",temp->data);

      free(temp);
   }

   
}

void display()
{
    struct node *temp = front;

    if(front == NULL && rear == NULL) printf("Queue is empty \n");
    else{

    printf("element in the list are : ");
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while(temp != front);
    }
}

int main()
{
    int choice;
    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    }
}