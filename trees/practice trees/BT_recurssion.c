#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}
struct node *root;

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
        scanf("%d",ele);
        insert(ele);
        printf("%d element inserted \n",ele);
    }
}

void insert(int ele)
{
    
}
/*
void delete()
{

}

void inorder()
{

}

void preorder()
{

}

void postorder()
{

}

void levelwise()
{

}

void mirror()
{

}

void height()
{

}
*/
int main()
{
        printf("1. creation\n")
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. inorder\n");
        printf("4. preorder\n");
        printf("5. postorder\n");
        printf("6. levelwise\n");
        printf("7. mirror\n");
        printf("8. height\n");
        printf("9. exit\n");

    while(1)
    {
        int choice;
       printf("enter a choice : ");
       scanf("%d",&choice);

        switch(choice)
        {
            case 1 : insert();
                     break;
      /*      case 2 : delete();
                     break;
            case 3 : inorder();
                     break;
            case 4 : preorder();
                     break;
            case 5 : postorder();
                     break;
            case 6 : levelwise();
                     break;
            case 7 : mirror();
                     break;
            case 8 : height();
                     break;
        */             
            case 9 : exit(1);
                     break;         
        }

    }
}