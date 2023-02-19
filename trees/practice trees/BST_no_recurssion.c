// not workiing 
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * root ;

struct stack
{
    int size;
    int top;
    struct Node** array;
};

struct stack *createStack(int size)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node**)malloc(stack->size* sizeof(struct node*));
    return stack;
}

void creation()
{
    int size;
    printf("enter size : ");
    scanf("%d",&size);

    for(int i=0 ; i<size ; i++)
    {
        int ele;
        printf("enter %d element : ",i+1);
        scanf("%d",&ele);
        if(root == NULL) root = insert(root , ele);
        else insert(root , ele);
        printf("%d inserted \n", ele);
    }
}

void insert(struct node *root , int ele)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = newnode->right = NULL;

    if(root == NULL) {

        root = newnode;
        return ;
    }

    struct node *curr = root;
    struct node *prev = root;

    while(curr != NULL)
    {
        if(ele < curr->data)
        {
            prev = curr;
            curr = curr->left;

        }else if(ele > curr->data)
        {
            prev = curr;
            curr = curr->right;
        }
    }

    if(ele < curr->left) prev->left = newnode;
    else prev->right = newnode;
}

struct node* delete()
{

}
int isFULL(struct stack* stack)
{
    return stack->size == stack->top -1;
}

int isEMTPY(struct stack *stack)
{
    return stack->top == -1;
}

void push(struct stack *stack , struct node * node)
{
    if(isFULL(stack)) return ;
    else stack->array[++stack->top] = node;
}

struct node * pop(struct stack *stack)
{
    if(isEMTPY(stack)) return 0;
    else return stack->array[stack->top--];
}

void inorder(struct node *root)
{
        if(root == NULL) return ;

   struct stack *s1 = createStack(MAX_SIZE);
   struct node *temp = root;

   while(temp != NULL || !isEMTPY(s1))
   {
     while(temp != NULL)
     {
        push(s1 , temp);
        temp = temp->left;
     }

     temp = pop(s1);
     printf("%d ",temp->data);
     temp = temp->right;
   }
}

void preorder(struct node *root)
{
        if(root == NULL) return ;

   struct stack *s1 = createStack(MAX_SIZE);
   struct node *temp = root;
   push(s1 , temp);
   while(isEMTPY(s1))
   {
       temp = pop(s1);
       printf("%d ",temp->data);

       if(temp->right != NULL) push(s1 , temp->right);
       else push(s1 , temp->left);
   }

}

void postorder(struct node *root)
{
         if(root == NULL) return ;

    struct stack *s1 = createStack(MAX_SIZE);
   struct stack *s2 = createStack(MAX_SIZE);

   push(s1 , root);
    struct node* node;

   while(isEMTPY(s1))
   {
      node = pop(s1);
      push(s2 , node);

      if(node->left) push(s1 , node->left);
      if(node->right) push(s1 , node->right);
   }
   while(isEMTPY(s2))
   {
      node = pop(s2);
      printf("%d ",node->data);
   }


}

int main()
{
        printf("1. creation\n");
        printf("2. insert\n");
        printf("3. delete\n");
        printf("4. inorder\n");
        printf("5. preorder\n");
        printf("6. postorder\n");
        printf("8. mirror\n");
        printf("9. height\n");
        printf("10. exit\n");

    while(1)
    {
       int choice , element , h;
       printf("\nenter a choice : ");
       scanf("%d",&choice);

        switch(choice)
        {
            case 1 : creation();
                     break;

            case 2 : printf("\nnenter element : \n");
                     scanf("%d",&element);
                     insert(root , element);
                     printf("\nelement inserted %d \n",element);
                     break;

           case 3 :   printf("\nnenter element : \n");
                     scanf("%d",&element);
                     struct node *del = delete(root , element);
                     printf("\nelement deleted %d \n",element);
                     break;

           case 4 : printf("inorder traversal is : ");
                    inorder(root);
                     break;

             case 5 : printf("preorder traversal is : ");
                     preorder(root);
                     break;

            case 6 : printf("postorder traversal is : ");
                     postorder(root);
                     break;

/*            case 8 :  printf("mirror image is : ");
                     mirror(root);
                     break;

            case 9 :  h =  height(root);
                     printf("height is %d ",h);
                     break;
                   
  */          case 10 : exit(1);
                     break;         
        }

    }
}