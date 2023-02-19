#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *queue[100];
int front = -1 , back = -1;

struct node* insert(struct node * root , int key)
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

void creation()
{
    root = NULL;
    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int ele;
    for(int i=0 ; i<size ; i++)
    {
        printf("enter %d elememnt ",i+1);
        scanf("%d",&ele);

        if(root == NULL) root = insert(root , ele);
        else insert(root , ele);

        printf("%d element inserted \n",ele);
    }
}

struct node *inOrder_Pre(struct node *root)
{
    root = root->left;

    while(root != NULL) root = root->right;

    return root;
}

struct node *delete(struct node *root , int key)
{
   struct node *iPre ;

   if(root == NULL) return NULL;

   if(root->left == NULL && root->right == NULL)
   {
     free(root);
     return NULL;
   }
   
   if(key < root->data) root->left = delete(root->left , key);
   else if(key > root->data) root->right = delete(root->right , key);
   else
   {
       iPre = inOrder_Pre(root);
       root->data = iPre->data;
       root->left = delete(root->left , iPre->data);
   }

   return root;
}

void inorder(struct node *root)
{
    if(root == NULL) return ;
    
    inorder(root->left);
    printf("%d | ",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL) return ;

   printf("%d | ",root->data);
   preorder(root->left);
   preorder(root->right);
}

void postorder(struct node *root)
{
        if(root == NULL) return ;

     postorder(root->left);
     postorder(root->right);
     printf("%d | ",root->data);
}

void enqueue(struct node *root)
{
    if(front == -1) {
        queue[++back] = root;
        front++;
    }else queue[++back] = root;
}

struct node* dequeue()
{
    return queue[front++];
}

void levelwise(struct node *root)
{
   enqueue(root);

   while(1)
   {
      if(front > back ) break;

      struct node *temp = dequeue();
      printf("%d | ",temp->data);

      if(temp->left != NULL) enqueue(temp->left);
      
      if(temp->right != NULL) enqueue(temp->right);
   }
}

void mirror(struct node *root)
{
    if(root == NULL) return;
    else
    {
        struct node *temp ;
        mirror(root->left);
        mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;

    }

    printf("\nInorder traversal of the mirror tree is : ");
    inorder(root);
}

int height(struct node *root)
{
    if(!root) return 0;
    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);

        if(left_height >= right_height) return left_height+1;
        else return right_height+1;
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
        printf("7. levelwise\n");
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

/*            case 2 : printf("\nnenter element : \n");
                     scanf("%d",&element);
                     insert(root , element);
                     printf("\nelement inserted %d \n",element);
                     break;

           case 3 :   printf("\nnenter element : \n");
        a             scanf("%d",&element);
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

            case 7 : printf("levelwise display: ");
                     levelwise(root);
                     break;
*/
/*            case 8 :  printf("mirror image is : ");
                     mirror(root);
                     break;
*/
            case 9 :  h =  height(root);
                     printf("height is %d ",h);
                     break;
                   
            case 10 : exit(1);
                     break;         
        }

    }
}