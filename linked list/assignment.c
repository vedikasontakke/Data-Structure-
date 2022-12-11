/*
Given a list, split it into two sublists — one for the front half, and one
for the back half. If the number of elements is odd, the extra element
should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11}
should yield the two lists {2, 3, 5} and {7, 11}. Getting this right for all
the cases is harder than it looks. You should check your solution against
a few cases (length = 2, length = 3, length=4) to make sure that the list
gets split correctly near the short­list boundary conditions. If it works
right for length=4, it probably works right for length=1000. You will
probably need special case code to deal with the (length <2) cases.
*/

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

void split(int mid , int size)
{
     struct node *temp = head;
     struct node *prev = head;
     int first_list_end = mid;
     int second_list_start = mid+1;

    printf("elements of first list are : ");
    while(first_list_end>0)
    {
       printf("%d " , temp->data);
       prev = temp;
       temp = temp->next;
        first_list_end--;
    }
    struct node *head2 ;
    head2 = temp;
    prev->next = NULL;

    printf("\nelements of first list are : ");

    while (second_list_start <= size)
    {
         printf("%d ", head2->data);
         head2 = head2->next;
         second_list_start++;
    }
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
int creation()
{
    int size , mid;
    printf("enter the size of linked list : ");
    scanf("%d",&size);

    if(size == 0) printf("invalid input \n");
    else 
    {
        printf("enter elements of linked list : ");

    
        for(int i=0 ; i<size ; i++)
       {
          int n;
          scanf("%d",&n);
          addnode(n);  
       }

       display();
    
       if(size == 1)
       {
        printf("list can't split \n");
        return 0;
       }
       else if(size%2==0) mid = size/2;
       else mid = (size/2)+1;

       split(mid , size);
    }
}

int main()
{
    creation();
}