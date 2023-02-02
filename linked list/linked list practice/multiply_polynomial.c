#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coe;
    int expo;
    struct node *next;
};

struct node* add_node(struct node *head , int coe , int expo)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coe = coe;
    newnode->expo = expo;
    newnode->next = NULL;

    if(head == NULL)
    {
      head = newnode;
      return head;
    }
     else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
     }
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp->next != NULL)
    {
        printf("%dx^%d + ", temp->coe , temp->expo);
        temp = temp->next;
    }

    printf("%dx^%d ", temp->coe , temp->expo);

}

void removeDuplicates(struct node *ans)
{
    struct node *poly1 = ans;

    while(poly1 != NULL && poly1->next != NULL)
    {
        struct node *poly2 = poly1;

        while(poly2->next != NULL)
        {
            if(poly1->expo == poly2->next->expo)
            {
                poly1->coe = poly1->coe + poly2->next->coe;
                struct node *duplicate_ = poly2->next;
                poly2->next = poly2->next->next;
                free(duplicate_);
            }
            else
            {
                poly2 = poly2->next;
            }
        }

        poly1 = poly1->next;
    }
}

struct node* multiply(struct node *ans_head , struct node *p1 , struct node *p2 )
{
    struct node *temp_p1 = p1;
    struct node *temp_p2 = p2;

    while(temp_p1 != NULL)
    {
        while(temp_p2 != NULL)
        {
            int coe = temp_p1->coe * temp_p2->coe;
            int expo = temp_p1->expo + temp_p2->expo;
            ans_head = add_node(ans_head , coe , expo);
            temp_p2 = temp_p2->next;
        }
        
        temp_p2 = p2;
        temp_p1 = temp_p1->next;
    }
    
    removeDuplicates(ans_head);
    return ans_head;
}

int main()
{
    struct node *ans = NULL;
    struct node *p1 = NULL;
    struct node *p2 = NULL;

    int size_p1 , size_p2;

    printf("enter size of polynomial 1 : ");
    scanf("%d",&size_p1);

    printf("enter size of polynomial 2 : ");
    scanf("%d",&size_p2);

    for(int i=0 ; i<size_p1 ; i++)
    {
        int coe , expo;
        printf("enter %d coeff for poly 1 : ",i+1);
        scanf("%d",&coe);

        printf("enter %d expo for poly 1 : ",i+1);
        scanf("%d",&expo);

        p1 = add_node(p1 , coe , expo);
    }

     for(int i=0 ; i<size_p2 ; i++)
    {
        int coe , expo;
        printf("enter %d coeff for poly 2 : ",i+1);
        scanf("%d",&coe);

        printf("enter %d expo for poly 2 : ",i+1);
        scanf("%d",&expo);

        p2 = add_node(p2 , coe , expo);
    }

    printf("1st polynnomial is : ");
    display(p1);

    printf("\n2nd polynnomial is : ");
    display(p2);

    ans = multiply(ans , p1 , p2);
    printf("\nans polynnomial is : ");
    display(ans);

    //return 0;
}