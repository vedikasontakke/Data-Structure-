#include<stdio.h>
#include<conio.h>

/*
MARKS SCHEME :
10-LAB
10-CP
20-CV
40-PRACTICAL
20-ESC
*/

// Structure of TreeNode
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


// Creating Queue For Nodes
struct Node* ar[1000];
int front = -1, back = -1;

void enqueue(struct Node* data)
{
    if(front == -1)
    {
        ar[back+1] = data;
        front++;
        back++;
    }
    else
    {
        ar[back+1] = data;
        back++;
    }
}

struct Node* dequeue()
{
    front++;
    return ar[front-1];
}

void displayQueue()
{
    printf("\n---Displaying Queue ------\n");
    for(int i=front; i<=back; i++)
    {
        printf("%d | ", ar[i]->data);
    }
    printf("\n----\n");
}


// Function to insert node in tree
struct Node* insertNode(struct Node* root, int data)
{
    // Creating new Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // If tree is not present (BASE_CASE)
    if(root == NULL)
    {
        root = newNode;
        return root;
    }

    // Inserting node at down of root
    if(data < root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void displayLevelWise(struct Node* root)
{
    printf("\n ----- Displaying Level Wise ----- \n");
    enqueue(root);
    struct Node* tp1 = root;
    while(1)
    {
        if(front > back)
            break;
        tp1 = dequeue();
        printf("%d | ",tp1->data);
        if(tp1->left != NULL)
            enqueue(tp1->left);
        if(tp1->right != NULL)
            enqueue(tp1->right);
    }
    printf("\n");
}

int main()
{
    struct Node* root = NULL;

    /** AUTO_INPUT_CODE */
    int ar[] = {12,45,9,16,10,18,2,20,8};
    int sz = sizeof(ar)/sizeof(int);
    for(int i=0; i<sz; i++)
    {
        root = insertNode(root,ar[i]);
    }

    /*
    USER_INPUT_CODE
    ================

    int n;
    printf("How many number you want to insert in Tree: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        int temp;
        printf("Enter data to insert: ");
        scanf("%d",&temp);
        root = insertNode(root, temp);
    } */

    displayLevelWise(root);

    return 0;
}
