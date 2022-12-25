#include<stdio.h>
#include<stdlib.h>
// not working 
struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * root ;

void insert(int num)
{
   struct node * newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data = num;
   newnode->left = newnode->right = NULL;

   if(root == NULL){
      root = newnode;
      return 0;
   } 
   
   struct node * curr = root;
   struct node * prev = root;

   while(curr != NULL)
   {
      if(num < curr->data)
      {
         prev = curr;
         curr = curr->left;
      }else if(num > curr->data)
      {
         prev = curr;
         curr = curr->right;
      }
   }

   if(num < prev->data) prev->left = newnode;
   else prev->right = newnode;
}

void inorder()
{
   if(root == NULL) return  ;

   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}

int main()
{
   root = NULL;
   int size;
   printf("enter the number of element you want to insert :\n");
   scanf("%d",&size);

   
   int element;
   for(int i=0; i<size ; i++)
   {
      printf("enter the %d element : ", i+1);
      scanf("%d", &element);
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
   inorder(root);

   printf("\nenter a elment which you want to insert :");
   scanf("%d" , &element);
   insert(root , element); 

   printf("\ninorder traversal after inseration :");
   inorder(finalroot);

 
}