#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

int queue_array[SIZE];
int front = -1;
int  rear = -1;

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
        printf("enter your choice : ");
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
        default: printf("invalid input\n");
            break;
        }
    }

}

void enqueue()
{
    int data;

    if(rear == SIZE-1) printf("queue is full\n");
    else{

        if(front = -1) front = 0;
        printf("enter element : \n");
        scanf("%d",&data);

        queue_array[++rear] = data;
    }
}

void dequeue()
{
    if(front == -1 || front > rear) printf("queue is empty\n");
    else{

        int data = queue_array[front++];
        printf("element deleted is : %d",data);
    }
}

void display(){

    if(front == -1 || front > rear) printf("queue is emtpy\n");
    else{
    
    printf("elements in the queue are : \n");
    for(int i=front ; i<=rear ; i++)
        printf(" %d ",queue_array[i]);
    
    printf("\n");
    }
}