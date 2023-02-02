#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int c_queue[SIZE];
int front = -1;
int rear = -1;

void enqueue()
{
   int data;
   
   printf("enter element :");
   scanf("%d",&data);

   if(front == -1 && rear == SIZE-1 || front == rear+1) printf("queue is full\n");
   else 
   {
       if(front == -1) front = 0;
       
       rear = (rear+1)%SIZE;
       c_queue[rear] = data;
       printf("element inserted is %d \n",data);
   }
}

void dequeue()
{
    int del_ele = c_queue[front];

   if(front == -1 && rear == -1) printf("empty\n");
   else
   {
     if(front == rear) front = rear = -1;
     else front = (front+1)%SIZE;
   }

    printf("deleted element is %d \n",del_ele);

}

void display()
{
   printf("elements are : ");

   int i=front;

   while(i!=rear)
   {
      printf("%d ",c_queue[i]);
      i = (i+1)%SIZE;
   }

   printf(" %d",c_queue[rear]);
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
        } /* End of switch */
    } 
}