#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter a data (-1 for no node ):");
    scanf("%d",&x);

    if(x == -1) return ;

    newnode->data = x;
    printf("enter a left node %d :\n", x);
    newnode->left = create();
    printf("enter a right node %d :\n" , x);
    newnode->right = create();
    return newnode;
}

int preorder(struct node *root)
{
    if(root == NULL) return ;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int inorder(struct node *root)
{
    if(root == NULL) return ;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int postorder(struct node *root)
{
    if(root == NULL) return ;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void main()
{
   struct node *root;
   root = NULL;
   root = create();

   printf("\n pre order is :");
   preorder(root);

   printf("\n in order is :");
   inorder(root);

   printf("\n post order is :");
   postorder(root);
}
