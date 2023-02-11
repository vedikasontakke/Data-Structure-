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
    if (key < root->data) root->left = insert(root->left , key) ;
    else if (key > root->data) root->right = insert(root->right , key);
    return root;
    }
}
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
        root = root->right;
    
    return root;
}
struct node* deleteNode(struct node* root , int element)
{
    struct node* iPre;
    if(root == NULL) return NULL;
    // if wanna delete leaf node
    if ( root->left==NULL && root->right==NULL )
    {
        free(root);
        return NULL;
    }
    //searching for the node to be deleted
    if (element < root->data) root-> left = deleteNode(root->left,element);
    
    else if (element > root->data) root-> right = deleteNode(root->right,element);
    
   else{
        //deletion strategy when the node is found
       //if element == root->data 
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
   // printf("root is %d ",root);
   //return first element's address;
    return root;
}

int main()
{
   struct node * root;
   root = NULL;
   int size , element;
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
   printf("root is -- %d ",root);
   printf("\nenter a elment which you want to insert :");
   scanf("%d" , &element);
   insert(root , element); 

   printf("\ninorder traversal after inseration :");
   inorder(root);

   int del_element;
   printf("\nenter the node which you want to delete :");
   scanf("%d",&del_element);
   
   struct node * hello = deleteNode(root , del_element);
   printf("root is %d ",hello);
   printf("\ninorder traversal after deletion :");
   inorder(root);

}
