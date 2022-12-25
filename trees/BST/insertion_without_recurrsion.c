#include<stdio.h>
#include<stdlib.h>
// not working 
struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * insert(struct node * root , int x)
{
    struct node* temp = root;
    struct node * newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    // tree is empty;
    if(root == NULL) return newnode;
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
            printf("9\n");
        }
printf("10\n");
        if(x < temp->data) temp->left = newnode;
       else temp->right = newnode;
printf("11\n");
       return newnode;
    }  
}

void inorder(struct node* root)
{
   if(root == NULL) return  ;

   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}

int main()
{
   struct node * root ;
   root = NULL;
   int size;
   printf("enter the number of element you want to insert :\n");
   scanf("%d",&size);

   printf("enter the %d elements : ", size);
   int element;
   for(int i=0; i<size ; i++)
   {
      scanf("%d ", &element);
      if(root == NULL) root = insert(root , element);
      else insert(root , element);
   }
   
   printf("inorder traversal :");
   inorder(root);

   printf("\nenter a elment which you want to insert :");
   scanf("%d" , &element);
   insert(root , element); 

   printf("\ninorder traversal after inseration :");
   inorder(root);
}