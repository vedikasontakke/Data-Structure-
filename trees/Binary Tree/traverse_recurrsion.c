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

    if(x == -1) return 0;

    newnode->data = x;
    printf("enter a left node %d :\n", x);
    newnode->left = create();
    printf("enter a right node %d :\n" , x);
    newnode->right = create();
    return newnode;
}

int preorder(struct node *root)
{
    if(root == NULL) return 0;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int inorder(struct node *root)
{
    if(root == NULL) return 0;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int postorder(struct node *root)
{
    if(root == NULL) return 0 ;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void insert(struct node * root)
{   
    int data; 
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter a element which you want to insert :");
    scanf("%d",&data);
        printf("1\n");

    struct node* temp = root;
    struct node * prev = root;
        printf("2\n");
    newnode->data = data;
    while(temp != NULL){
            printf("3\n");
             prev = temp;
             temp = temp->left;
    }     
     printf("4\n");

    prev->left = newnode;
    printf("5\n");
}
void deleteTree(struct node *root){
     if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
     
    printf("\nDeleteing Node : %d\n", root->data);
    free(root);
     
    return;
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

   // deleteTree(root);
    insert(root);
    inorder(root);
}
