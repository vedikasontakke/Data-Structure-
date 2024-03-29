/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 50
 
void enqueue();
void dequeue();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;

main()
{
    int choice;
    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");

    while (1)
    {
        printf("Enter your choice : ");
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
 
void enqueue()
{
    int add_item;
    if (rear == MAX - 1) printf("Queue Overflow \n");
    else
    {
        if (front == - 1) front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        queue_array[++rear] = add_item;
    }
} /* End of insert() */
 
void dequeue1()
{
    if (front == - 1 || front > rear) printf("Queue Underflow \n");
    else printf("Element deleted from queue is : %d\n", queue_array[front++]);
} /* End of delete() */
 
void display()
{
    int i;
    if (front == - 1) printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /* End of display() */