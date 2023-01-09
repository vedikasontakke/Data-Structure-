#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue()
{
   int add_item;
   printf("enter a element :");
   scanf("%d",&add_item);

   if((front == -1 && rear == SIZE-1) || (front == rear +1)) printf("overflow \n");
   else
   {
     if(front == -1) front = 0;
     rear = (rear+1)%SIZE;
     queue[rear] = add_item;
     printf("%d is inserted\n", add_item);
   }
}

void dequeue()
{
   int del_ele = queue[front];
   if(front == -1) printf("queue is empty\n");
   else {

     // if only one element in a array 
     if(rear == front) rear = front = -1;
     else front = (front +1)%SIZE;
     
     printf("deleted element is %d ",del_ele);
   }
}

void display()
{
   if(front == -1) printf("queue is empty\n");
   else {
        int i;
        printf("elements in the queue are : \n");
        for( i=front ; i!=rear ; i=(i+1)%SIZE) printf("%d ", queue[i]);
        printf("%d ", queue[i]);    
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
        } /* End of switch */
    } /* End of while */
} /* End of main() */
 