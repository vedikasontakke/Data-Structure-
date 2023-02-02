// 

#include<stdio.h>
#include <stdlib.h>
struct Node
{
    int coe;
    int expo;
    struct Node *next;
};

struct Node* addNode(struct Node* head,int coe, int expo)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coe = coe;
    newNode->expo = expo;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    printf("\nPrinting LL.\n");
    while(temp != NULL)
    {
        printf("Coe:%d Expo:%d",temp->coe,temp->expo);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addPoly(struct Node* p3, struct Node* p1, struct Node* p2)
{
    struct Node* temp1 = p1;
    struct Node* temp2 = p2;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->expo == temp2->expo)
        {
            p3 = addNode(p3,temp1->coe+temp2->coe,temp1->expo);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->expo > temp2->expo)
        {
            p3 = addNode(p3,temp1->coe,temp1->expo);
            temp1 = temp1->next;
        }
        else
        {
            p3 = addNode(p3,temp2->coe,temp2->expo);
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL)
    {
        p3 = addNode(p3,temp1->coe,temp1->expo);
        temp1= temp1->next;
    }
    while(temp2 != NULL)
    {
        p3 = addNode(p3,temp2->coe,temp2->expo);
        temp2 = temp2->next;
    }

    return p3;
}

int main()
{
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;
    struct Node* p3 = NULL;

    int p1Sz, p2Sz;
    printf("Enter Size of Polynomial 1: ");
    scanf("%d",&p1Sz);
    printf("Enter Size Of Polynomial 2: ");
    scanf("%d",&p2Sz);

    printf("\nEnter Data For Polynomial 1: \n");
    for(int i=0; i<p1Sz; i++)
    {
        int coe, expo;
        printf("Enter Coeficient %d : " , i+1);
        scanf("%d",&coe);
        printf("Enter Exponent %d : ", i+1);
        scanf("%d",&expo);
                      
        p1 = addNode(p1,coe,expo);
    }
                                                  
    printf("\nEnter Data For Polynomial 2: \n");
    for(int i=0; i<p2Sz; i++)
    {
        int coe, expo;
        printf("Enter Coeficient %d : " , i+1);
        scanf("%d",&coe);
        printf("Enter Exponent %d : " , i+1);
        scanf("%d",&expo);

        p2 = addNode(p2,coe,expo);
    }

    printLL(p1);
    printLL(p2);

    p3 = addPoly(p3,p1,p2);

    printLL(p3);

}
