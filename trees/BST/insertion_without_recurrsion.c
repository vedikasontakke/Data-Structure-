#include<stdio.h>
#include<stdlib.h>
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
      return;
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

void inorder(struct node *root)
{
   if(root == NULL) return;

   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}

struct node* deleteNode(struct node * root , int element)
{  
   printf("a");
   struct node* curr = root;
   struct node* prev = root;
   printf("b");

   while(curr!=NULL || element!= curr->data)
   {
      prev = curr;
      printf("c");

      if(element < curr->data) curr = curr->left;
      else curr = curr->right;
   }
   
   // if wanna delete leaf node

   if(curr->left == NULL && curr->right == NULL) 
   {

       free(curr);
       printf("d");

       if(element < prev->data) prev->left = NULL;
       else prev->right = NULL;

          printf("e");

   }
         printf("f");

   //5return root;
}


struct node* deleteNode(struct node* root, int key)
{
    struct node* curr = root;
    struct node* prev = NULL;
 
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
 
    if (curr == NULL) {
       printf("%d key not found ", key);
        return root;
    }
 
    // Check if the node to be deleted has atmost one child.
    if (curr->left == NULL || curr->right == NULL) {
        struct node* newCurr;
 
        if (curr->left == NULL) newCurr = curr->right;
        else newCurr = curr->left;
 
        if (prev == NULL) return newCurr;
 

        if (curr == prev->left)  prev->left = newCurr;
        else prev->right = newCurr;
 
        free(curr);
    }
    // node to be deleted has two children.
    else {
        struct node* p = NULL;
        struct node* temp;
 
        // Compute the inorder successor
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
 
        if (p != NULL) p->left = temp->right;
        else curr->right = temp->right;
        curr->data = temp->data;
        free(temp);
    }
    return root;
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
      insert(element);   
   }
   
   printf("inorder traversal :");
   inorder(root);

   printf("\nenter a elment which you want to insert :");
   scanf("%d" , &element);
   insert(element); 

   printf("\ninorder traversal after inseration :");
   inorder(root);

   int del_element;
   printf("\nenter the node which you want to delete :");
   scanf("%d",&del_element);
   
   deleteNode(root , del_element);
   printf("\ninorder traversal after deletion :");
   inorder(root);

}