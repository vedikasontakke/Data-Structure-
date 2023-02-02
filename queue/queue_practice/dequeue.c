#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
int dequeue_array[20];
int front = -1;
int rear = -1;

void enqueue_front()
{
   int data;

   printf("enter a data : \n");
   scanf("%d",&data);
   if(front==0 && rear == SIZE-1) printf("queue os full\n");
   else if(front==-1 && rear==-1)
   {
       // queue is empty
       front = rear = 0;
       dequeue_array[front] = data;
   }
   else if(front == 0)
   {
     front = SIZE-1;
     dequeue_array[front] = data;
   }else
   {
    // if front is at a random postion
      front = front-1;
      dequeue_array[front] = data;
   }

   printf("%d is inserted\n", data);
}

void enqueue_rear()
{
     int data;
     printf("enter a data : ");
     scanf("%d",&data);
     
     if(front==0 && rear==SIZE-1) printf("queue is full\n");
     else if(front== -1 && rear == -1)
     {
        front = rear = 0;
        dequeue_array[rear] = data;
     }else if(rear == SIZE-1)
     {
         rear = 0;
         dequeue_array[rear] = data;
     }else
     {
        rear++;
        dequeue_array[rear] = data;
     }

     printf("%d inserted\n",data);
}

void dequeue_front()
{
    if(front == -1 && rear == -1) printf("queue is empty\n");
    else if(front == rear) {
            // only one elemnt in a queue 
           printf("deleted item is %d",dequeue_array[front]);
           front = rear = -1;
    }else if(front == SIZE-1)
    {
        printf("%d is deleted\n",dequeue_array[front]);
        front = 0;
    }else
    {
        printf("%d is deleted\n",dequeue_array[front]);
        front++;
    }
}

void dequeue_rear()
{
    if(front == -1 && rear == -1) printf("queue is empty\n");
    else if(front == rear )
    {
        printf("%d is deleted\n",dequeue_array[rear]);
        front = rear = -1;
    }else if(rear == 0)
    {
        printf("%d is deleted\n",dequeue_array[rear]);
        rear = SIZE-1;
    }
    else
    {
        printf("%d is deleted\n");
        rear--;
    }
}

void display()
{
    if(front == -1 && rear == -1) printf("queue is empty\n");
    else{
        printf("elements in the dequqe are :\n");
        int i=front;

        while(i!=rear)
        {
            printf("%d ",dequeue_array[i]);
            i = (i+1)%SIZE;
        }

        printf(" %d ",dequeue_array[rear]);
    }
}

int main()
{
    int choice;
    printf("1.Insert element at front end \n");
    printf("2.Insert element at rear end \n");
    printf("3.Delete element from front end \n");
    printf("4.Delete element from rear end \n");
    printf("5.Display all elements of queue \n");
    printf("8.Quit \n");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue_front();
            break;

            case 2:
            enqueue_rear();
            break;

            case 3:
            dequeue_front();
            break; 
            
            case 4:
            dequeue_rear();
            break;

            case 5:
            display();
            break;

            case 8:
            exit(1);

            default:
            printf("Wrong choice \n");
        } 
    } 
}