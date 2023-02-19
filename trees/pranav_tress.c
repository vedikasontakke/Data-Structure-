#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

/// Data Structures

// Structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
/*
// Stack
Node* stack[1000];
int top = -1;
void push(Node* data) {
    stack[++top] = data;
}
Node* pop() {
    return stack[top--];
}
int isEmpty() {
    if(top == -1)
        return 1;
    return 0;
}

/// METHODS
Node* insert(Node* root, int data) {
    if(root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        root = newNode;
        return root;
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrderR(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderR(root->left);
    printf("%d ",root->data);
    inOrderR(root->right);
}

/// INORDER without recursion
void inOrderI(Node* root) {

    Node* crnt = root;
    while(!isEmpty() || crnt != NULL) {
        while(crnt != NULL) {
            push(crnt);
            crnt = crnt->left;
        }

        crnt = pop();
        printf("%d ",crnt->data);
        crnt = crnt->right;
    }
}


void preOrderR(Node* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preOrderR(root->left);
    preOrderR(root->right);
}

void preOrderI(Node *root) {
    if(root == NULL) return;

    Node* crnt = root;

    while(!isEmpty() || crnt != NULL) {

        while(crnt != NULL) {
            push(crnt);
            printf("%d ",crnt->data);
            crnt = crnt->left;
        }

        crnt = pop();
        crnt = crnt->right;
    }
}

void postOrderR(Node* root) {
    if(root == NULL) return;

    postOrderR(root->left);
    postOrderR(root->right);
    printf("%d ",root->data);
}
*/

/**
- In this algorithm, we use two stacks to store the nodes of the binary tree. Let's see how the algorithm works:

- Start from the root node and push the root node to the first stack
- While the first stack is not empty repeat the below two steps
    - From the first stack pop a node and push that node to the second stack
    - If there is a left and right node of the popped stack then push the left and right node of the popped stack to the first stack
Once the first stack is empty print the nodes in the second stack. It will be post-order traversal order.
*/
/*
void postOrderI(Node* root) {
    Node* postOrderStack[500];
    int top2 = -1;

    Node *crnt = root;
    push(crnt);

    while(!isEmpty()) {
        crnt = pop();
        postOrderStack[++top2] = crnt;

        if(crnt->left != NULL)
            push(crnt->left);
        if(crnt->right != NULL)
            push(crnt->right);
    }

    while(top2 >= 0){
        printf("%d ",postOrderStack[top2--]->data);
    }
}

int countNode(Node* root) {

    Node* crnt = root;
    int count = 0;

    while(!isEmpty() || crnt != NULL) {
        while(crnt != NULL) {
            push(crnt);
            crnt = crnt->left;
        }

        crnt = pop();
        printf("%d ",crnt->data);
        count++;
        crnt = crnt->right;
    }

    return count;
}
*/
/**

ALGORITHM TO FIND THE HEIGHT
------------------------------

1. Create a stack or a queue to store the nodes at each level of the tree.
2. Push the root node of the tree onto the stack or queue.
3. Initialize a variable height to 0.
4. While the stack or queue is not empty:
    - Increment height by 1.
`   - Initialize a variable level_size to the size of the stack or queue.
    - Loop through the level_size number of nodes in the stack or queue:
        - Pop the next node from the stack or queue.
        - Push its left and right child nodes onto the stack or queue if they exist.
5. Return height.

*/

/// Queue
Node* queue[500];
int front = -1, rear = -1;

void enq(Node* data){
    if(front == -1 && rear == -1) {
        queue[++rear] = data;
        front++;
        return;
    }
    queue[++rear] = data;
}
Node* deq(){
    return queue[front++];
}
int isQEmpty() {
    if(front > rear) {
        return 1;
    }
    return 0;
}
int getQSize() {
    return (rear-front)+1;
}

void levelWiseI(Node *root) {
    Node* crnt = root;
    enq(crnt);
    int height = 1;
    while(!isQEmpty()) {
        crnt = deq();
        printf("%d ",crnt->data);
        if(crnt->left != NULL) enq(crnt->left);
        if(crnt->right!= NULL) enq(crnt->right);
    }
}

int getHeightI(Node* root) {

    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;

    Node* crnt = root;
    enq(crnt);

    int s = 1;
    int h = 0;
    while(!isQEmpty()) {
        for(int i=0; i<s; i++) {
            crnt = deq();
            if(crnt->left != NULL) enq(crnt->left);
            if(crnt->right != NULL) enq(crnt->right);
        }
        h++;
        s = getQSize();
    }

    return h;
}

/// MIRROR
void mirror(Node* root) {

    Node* crnt = root;
    enq(crnt);

    while(!isQEmpty()) {
        crnt = deq();

        // Before change
        if(crnt->left != NULL) enq(crnt->left);
        if(crnt->right != NULL) enq(crnt->right);

        if(crnt->left != NULL && crnt->right != NULL) {
            Node* tp = crnt->left;
            crnt->left = crnt->right;
            crnt->right = tp;
        }
        if(crnt->left != NULL && crnt->right == NULL) {
            crnt->right = crnt->left;
            crnt->left = NULL;
        }
        if(crnt->left == NULL && crnt->right != NULL) {
            crnt->left = crnt->right;
            crnt->right = NULL;
        }
    }
    printf("\nMirroring Done...");
}

/*
/// DELETION OF NODE
Node* deleteNode(Node* root, int data) {

    Node* orderArr[500];
    int k=0;
    Node* temp = NULL;
    // doing in-order to search the element
    Node* crnt = root;
    while(!isEmpty() || crnt != NULL)
    {
        while(crnt!=NULL)
        {
            push(crnt);
            crnt = crnt->left;
        }
        crnt = pop();
        // Storing target element in temp
        if(crnt->data == data) {
            temp = crnt;
        }
        //printing data (adding in array)
        orderArr[k++] = crnt;
        crnt = crnt->right;
    }

    // Replace predessors data with target
    Node* pred;
    for(int i=0; i<k; i++) {
        if(orderArr[i]->data == data)
        {
            orderArr[i]->data = orderArr[i+1]->data;
            pred = orderArr[i+1];
            break;
        }
    }

    // Putting NULL into all node's left right ptr where predessor node is present (DELETING PRedicssor)
    for(int i=0; i<k; i++) {
        if(orderArr[i] == pred) continue;
        if(orderArr[i]->left == pred) {
            orderArr[i]->left == NULL;
        } else if(orderArr[i]->right == pred) {
            orderArr[i]->left == NULL;
        }
    }
    return root;
}

*/


int main() {
    Node* root = NULL;
    int choice, key;
    while (1) {

        printf("\n--------BST Operations:---------\n");
        printf("4. Level-wise Display\n");
        printf("5. Mirror Image\n");
        printf("7. Height of the tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 4:
                printf("Level-wise Display of the tree: ");
                levelWiseI(root);
                break;
            case 5:
                printf("Mirror Image of the tree: \n");
                mirror(root);
                //inorder(root);
                break;
            case 7:
                printf("Height of Tree: %d",getHeightI(root));
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}