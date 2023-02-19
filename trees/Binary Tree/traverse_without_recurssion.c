#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
struct Node{
    int data;
    struct Node *left , *right;
};

struct Stack{
    int size;
    int top;
    struct Node** array;
};

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
    return stack;
}
void insert(struct Node * root)
{   
    int data; 
    struct Node * newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter a element which you want to insert :");
    scanf("%d",&data);
        printf("1\n");

    struct Node* temp = root;
    struct Node * prev = root;
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
struct Node * create()
{
    int data;
    struct Node * newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter a data (-1 for no node ):");
    scanf("%d",&data);

    if(data == -1) return 0;

    newnode->data = data;
    printf("left node for %d \n", data);
    newnode->left = create();
    printf("right node for %d \n", data);
    newnode->right = create();
    return newnode;
}

int isFull(struct Stack* stack)
{
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack , struct Node* node)
{
   if(isFull(stack)) return;
   
   stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
{
    if(isEmpty(stack)) return NULL;
    return stack->array[stack->top--];
}

void inorder(struct Node *root)
{
    if(root == NULL) return ;
    struct Stack* s1 = createStack(MAX_SIZE);
    struct Node* node = root;

    while(node != NULL || !isEmpty(s1))
    {
        while(node != NULL)
        {
            push(s1 , node);
            node = node->left;
        }

        node = pop(s1);
        printf("%d ", node->data);
        node = node->right;
    }
}

void preorder(struct Node *root)
{
    if(root == NULL) return ;
    struct Stack* s1 = createStack(MAX_SIZE);
    push(s1 , root);

    while(!isEmpty(s1))
    {
        struct Node * node ;
        node = pop(s1);
        printf("%d ", node->data);

        if(node->right) push(s1 , node->right);
        if(node->left) push(s1 , node->left);
    }
}

void postorder(struct Node* root)
{
   if(root == NULL) return;

   struct Stack* s1 = createStack(MAX_SIZE);
   struct Stack* s2 = createStack(MAX_SIZE);
   
   push(s1, root);
   struct Node* node;

   while(!isEmpty(s1))
   {
      node = pop(s1);
      push(s2 , node);

      if(node->left) push(s1 , node->left);
      if(node->right) push(s1 , node->right);
   }
   while(!isEmpty(s2))
   {
      node = pop(s2);
      printf("%d ",node->data);
   }
}

int main()
{
   struct Node *root;
  // struct Node *delnode;
   root = NULL;
   root = create();

   printf("\ntraverse in inorder :");
   inorder(root);

   printf("\ntraverse in preorder :");
   preorder(root);

   printf("\ntraverse in postorder :");
   postorder(root);

   insert(root);
   printf("6\n");
   inorder(root);

}