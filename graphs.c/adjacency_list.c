#include<stdio.h>
#include <stdlib.h>

int no_vertices;

struct node{
    int data;
    struct node *next;
};

void readGraph(struct node *adj[])
{
    struct node *newnode;
    int data ,  no_neighbors;

   for(int i=0 ; i<no_vertices ; i++)
   {
      struct node *last = NULL;
      printf("\nenter number of neighbors for %d : ",i);
      scanf("%d",&no_neighbors);

      for(int j=0 ; j<no_neighbors ; j++)
      {
         printf("enter %d neighbor value of vertices %d : ", j , i);
         scanf("%d",&data);

         struct node *newnode = (struct node*)malloc(sizeof(struct node));
         newnode->data = data;
         newnode->next = NULL;

         if(adj[i] == NULL) adj[i] = newnode;   // if array is empty or first element in the list
         else last->next = newnode;            // if element is not first elemnet

         last = newnode;
      }
   }
}
void printGraph(struct node *adj[])
{
    struct node *temp = NULL;

    for(int i=0 ; i<no_vertices ; i++)
    {
        temp = adj[i];
        printf("\nthe neighbor of %d are :",i);

        while(temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    printf("enter number of vertices : ");
    scanf("%d",&no_vertices);

    struct node *adj[no_vertices];
    
    for(int i=0 ; i<no_vertices ; i++)
        adj[i] = NULL;

        readGraph(adj);
        printGraph(adj);
    
}