#include<stdio.h>
#include<stdlib.h>
// not working 
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node *finalroot;
struct node * insert(struct node * root , int x)
{
          printf("3\n");

    struct node* temp = root;
    struct node * newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    // tree is empty;
    if(root == NULL)
    {       
        printf("c\n");
        finalroot = newnode;
        return newnode;
    } 
    else
    {
         while(root !=  NULL)
        {  
               if(x < root->data)
               {
                  temp = root;
                  root = root->left;
               }
               else{
                  temp = root;
                  root = root->right;
                }
        }
        if(x < temp->data) temp->left = newnode;
       else temp->right = newnode;
       printf("b\n");
       return newnode;
    }  
}

void inorder(struct node* finalroot)
{
   if(finalroot == NULL) return  ;

   inorder(finalroot->left);
   printf("%d ",finalroot->data);
   inorder(finalroot->right);
}

int main()
{
   struct node * root ;
   root = NULL;
   int size;
   printf("enter the number of element you want to insert :\n");
   scanf("%d",&size);

   
   int element;
   for(int i=0; i<size ; i++)
   {
      printf("enter the %d element : ", i+1);
      scanf("%d ", &element);
      printf("a");
      if(root == NULL) {
               printf("d");

         root = insert(root , element);
      }
      else {
         insert(root , element);
      }
   }
   
   printf("inorder traversal :");
   inorder(finalroot);
/*
   printf("\nenter a elment which you want to insert :");
   scanf("%d" , &element);
   insert(root , element); 

   printf("\ninorder traversal after inseration :");
   inorder(finalroot);
*/
 
}