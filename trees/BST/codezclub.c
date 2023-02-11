/*  C Program for binary search tree deletion without recursion  */

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node
{
        struct node *lchild;
        int info;
        struct node *rchild;
};

struct node *insert_nrec(struct node *root, int ikey );
struct node *del_nrec(struct node *root, int dkey);
struct node *case_c(struct node *root, struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_a(struct node *root, struct node *par,struct node *ptr );
void display(struct node *ptr,int level);



int main( )
{
        struct node *root=NULL, *ptr;
        int choice,k;

        while(1)
        {
                printf("\n");
                printf("1.Insert\n");
                printf("2.Delete\n");
                printf("3.Display\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {

                case 1:
                        printf("Enter the key to be inserted : ");
                        scanf("%d",&k);
                        root = insert_nrec(root, k);
                        break;

                case 2:
                        printf("Enter the key to be deleted : ");
                        scanf("%d",&k);
                        root = del_nrec(root, k);
                        break;

        case 3:
                        printf("\n");
                        display(root,0);
                        printf("\n");
                        break;

                case 4:
                        exit(1);
                        
                default:
                        printf("Wrong choice\n");
                        
                }/*End of switch*/
        }/*End of while */
        
        return 0;
        
}/*End of main( )*/


struct node *insert_nrec(struct node *root, int ikey)
{
        struct node *tmp,*par,*ptr;

        ptr = root;
        par = NULL;

        while( ptr!=NULL)
        {
                par = ptr;
                if(ikey < ptr->info)
                        ptr = ptr->lchild;
                else if( ikey > ptr->info )
                        ptr = ptr->rchild;
                else
                {
                        printf("Duplicate key");
                        return root;
                }
        }
        
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->lchild=NULL;
        tmp->rchild=NULL;

        if(par==NULL)
                root=tmp;
        else if( ikey < par->info )
                par->lchild=tmp;
        else
                par->rchild=tmp;

        return root;
}/*End of insert_nrec( )*/


struct node *del_nrec(struct node *root, int dkey)
{
        struct node *par,*ptr;

        ptr = root;
        par = NULL;
        while(ptr!=NULL)
        {
                if( dkey == ptr->info)
                        break;
                par = ptr;
                if(dkey < ptr->info)
                        ptr = ptr->lchild;
                else
                        ptr = ptr->rchild;
        }

        if(ptr==NULL)
                printf("dkey not present in tree\n");
        else if(ptr->lchild!=NULL && ptr->rchild!=NULL)/*2 children*/
                root = case_c(root,par,ptr);
        else if(ptr->lchild!=NULL )/*only left child*/
        root = case_b(root, par,ptr);
        else if(ptr->rchild!=NULL)/*only right child*/
        root = case_b(root, par,ptr);
        else /*no child*/
                root = case_a(root,par,ptr);

        return root;
}/*End of del_nrec( )*/

struct node *case_a(struct node *root, struct node *par,struct node *ptr )
{
        if(par==NULL) /*root node to be deleted*/
                root=NULL;
        else if(ptr==par->lchild)
                par->lchild=NULL;
        else
                par->rchild=NULL;
        free(ptr);
        return root;
}/*End of case_a( )*/

struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
        struct node *child;

        /*Initialize child*/
        if(ptr->lchild!=NULL) /*node to be deleted has left child */
                child=ptr->lchild;
        else                /*node to be deleted has right child */
                child=ptr->rchild;

        if(par==NULL )   /*node to be deleted is root node*/
                root=child;
        else if( ptr==par->lchild)   /*node is left child of its parent*/
                par->lchild=child;
        else                  /*node is right child of its parent*/
                par->rchild=child;
        free(ptr);
        return root;
}/*End of case_b( )*/

struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
        struct node *succ,*parsucc;

        /*Find inorder successor and its parent*/
        parsucc = ptr;
        succ = ptr->rchild;
        while(succ->lchild!=NULL)
        {
                parsucc = succ;
                succ = succ->lchild;
        }

        ptr->info = succ->info;

        if(succ->lchild==NULL && succ->rchild==NULL)
                root = case_a(root, parsucc,succ);
        else
                root = case_b(root, parsucc,succ);
        return root;
}/*End of case_c( )*/


void display(struct node *ptr,int level)
{
        int i;
        if(ptr == NULL )/*Base Case*/
                return;
        else
    {
                display(ptr->rchild, level+1);
                printf("\n");
                for (i=0; i<level; i++)
                        printf("    ");
                printf("%d", ptr->info);
                display(ptr->lchild, level+1);
        }
}/*End of display()*/