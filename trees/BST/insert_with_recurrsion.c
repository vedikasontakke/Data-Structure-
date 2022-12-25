#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left , *right;
};

void inorder(struct node* root)
{
   if(root == NULL) return  ;

   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}

struct node * insert(struct node * root , int key)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;

    // tree is empty;
    if(root == NULL) return newnode;
    else{
    if (key < root->data) {
        root->left = insert(root->left , key) ;
    }
    else if (key > root->data) {
        root->right = insert(root->right , key);
    }
    return root;
    }
};

int main()
{
   struct node * root;
   root = NULL;
   int size , element;;
   printf("how many nodes should be in a list :");
   scanf("%d",&size);

   printf("enter a element :");

   for(int i=0 ; i<size ; i++)
   {
     scanf("%d",&element);

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
